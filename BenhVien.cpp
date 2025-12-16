#include "BenhVien.h"
/*Quanly::Quanly()
{
    next_id = 01;
    load();
}*/
// Hàm xóa khoảng trắng đầu/cuối và xuống dòng thừa
string Quanly::trim(const string &s) const
{
    string res = s;
    // xóa khoảng trắng đầu
    res.erase(res.begin(), find_if(res.begin(), res.end(), [](unsigned char ch)
                                   { return !isspace(ch); }));
    // xóa khoảng trắng cuối
    res.erase(find_if(res.rbegin(), res.rend(), [](unsigned char ch)
                      { return !isspace(ch); })
                  .base(),
              res.end());
    return res;
}
Quanly::Quanly(int cp, int cpbs, int cplk)
{

    succhua = cp;
    succhuabs = cpbs;
    succhuaLK = cplk;
    soluong = 0;
    soluongbs = 0;
    soluongLK = 0;
    next_idbn = 1;
    next_idbs = 1;
    next_idLK = 1;
    dsbs = new Doctor[succhuabs];
    ds = new Patient[succhua];
    dsLK = new LichKham[succhuaLK];
    // cleanfile("BenhNhan.txt");
    //  0 cleanfile("Doctor.txt");
    load();
    loadbs();
    loadLK();
}
Quanly::~Quanly()
{
    delete[] ds;
    delete[] dsbs;
    delete[] dsLK;
}
bool Quanly::ktratrungtenbs(const string &ten) const
{
    string ten1 = trim(ten);
    for (int i = 0; i < soluongbs; i++)
    {
        if (tolower1(trim(dsbs[i].getTenBS())) == tolower1(ten1))
            return true;
    }
    return false;
}
void Quanly::xuatlichkham()
{
    if (soluongLK == 0)
    {
        cout << "Ko co lich kham nao trong he thong!\n";
        return;
    }
    cout << "\n=== DANH SACH LICH KHAM ===\n";
    for (int i = 0; i < soluongLK; i++)
    {
        dsLK[i].hienthilk();
        cout << "\n-----------------------------\n";
    }
    // xuatLichKhamDayDu();
}
void Quanly::loadLK()
{

    ifstream fin("LichKham.txt");
    if (!fin.is_open())
        return;

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        LichKham lk = LichKham::read(line);
        if (soluongLK < succhuaLK)
            dsLK[soluongLK++] = lk;

        string id_str = lk.getidlk();
        if (!id_str.empty() && id_str.rfind("LK", 0) == 0)
        {
            string num = id_str.substr(2);
            if (all_of(num.begin(), num.end(), ::isdigit))
            {
                int idnum = stoi(num);
                if (idnum >= next_idLK)
                    next_idLK = idnum + 1;
            }
        }
    }
    fin.close();
}
void Quanly::saveLK()
{

    ofstream fout("LichKham.txt", ios::trunc);
    if (!fout.is_open())
    {
        cerr << "0 mo duoc file LichKham.txt\n";
        return;
    }
    for (int i = 0; i < soluongLK; i++)
    {
        fout << dsLK[i].write();
    }
    fout.close();
}
bool Quanly::kiemTraTrungLich(const string &idBS, const string &ngay, const string &gio) const
{
    for (int i = 0; i < soluongLK; i++)
    {
        if (dsLK[i].getIDBS() == idBS &&
            dsLK[i].getday() == ngay &&
            dsLK[i].gettime() == gio)
        {
            return true; // Trùng lịch
        }
    }
    return false;
}
void Quanly::themlichkham()
{
    cout << "\n === NHAP THONG TIN LICH KHAM ===\n";

    // Hiển thị danh sách bác sĩ và bệnh nhân để tham khảo
    cout << "\n--- DANH SACH BAC SI ---\n";
    xuatbs();
    // cout << "\n--- DANH SACH BENH NHAN ---\n";
    // xuat();

    // Nhập thông tin trực tiếp
    string idBS, idBN, ngay, gio;

    cout << "Nhap ID bac si: ";
    getline(cin, idBS);

    // Kiểm tra bác sĩ tồn tại
    if (!timBacSiTheoID(idBS))
    {
        cout << " ID bac si khong ton tai!\n";
        return;
    }

    cout << "Nhap ID benh nhan: ";
    getline(cin, idBN);

    // Kiểm tra bệnh nhân tồn tại
    if (!timBenhNhanTheoID(idBN))
    {
        cout << " ID benh nhan khong ton tai!\n";
        return;
    }

    cout << "Nhap ngay kham (dd/mm/yyyy): ";
    getline(cin, ngay);
    cout << "Nhap gio kham (hh:mm): ";
    getline(cin, gio);

    // Kiểm tra trùng lịch
    if (kiemTraTrungLich(idBS, ngay, gio))
    {
        cout << "  BAC SI DA CO LICH KHAM VAO THOI GIAN NAY!\n";

        Doctor *bs = timBacSiTheoID(idBS);
        if (bs)
        {
            cout << "Bac si: " << bs->getTenBS() << " (ID: " << idBS << ")\n";
        }
        cout << "Thoi gian: " << gio << " - " << ngay << endl;
        cout << "Vui long chon thoi gian khac hoac bac si khac.\n";
        return;
    }

    // Tạo lịch khám mới
    if (soluongLK == succhuaLK)
    {
        int newcplk = succhuaLK * 2;
        LichKham *newdslk = new LichKham[newcplk];
        for (int i = 0; i < soluongLK; i++)
            newdslk[i] = dsLK[i];
        delete[] dsLK;
        dsLK = newdslk;
        succhuaLK = newcplk;
    }

    string maLich = LichKham::taoMaTuDong(next_idLK++);
    LichKham lk(maLich, idBN, idBS, ngay, gio);
    dsLK[soluongLK++] = lk;

    cout << " DAT LICH KHAM THANH CONG!\n";
    cout << "Ma lich: " << maLich << endl;

    // Hiển thị thông tin chi tiết
    Doctor *bs = timBacSiTheoID(idBS);
    Patient *bn = timBenhNhanTheoID(idBN);
    if (bs && bn)
    {
        cout << "Bac si: " << bs->getTenBS() << endl;
        cout << "Benh nhan: " << bn->getName() << endl;
    }
    cout << "Thoi gian: " << gio << " - " << ngay << endl;

    saveLK();
}
// void Quanly::themlichkham()
// {
//     LichKham lk;

//     cout << "\n === NHAP THONG TIN LICH KHAM ===\n";
//     lk.nhap();
//     string idBS = lk.getIDBS(); // Lấy ID bác sĩ từ lk
//     string ngay = lk.getday();  // Lấy ngày từ lk
//     string gio = lk.gettime();  // Lấy giờ từ lk
//     // Kiểm tra trùng lịch (sử dụng hàm có sẵn trong LichKham.h)
//     // if (lk.ktratrunglich(dsLK, soluongLK))
//     // {
//     //     cout << "Lich kham bi trung voi Bac si " << lk.getDT().getIDBS() << " vao " << lk.getday() << " " << lk.gettime() << endl;
//     //     return;
//     // }
//     if (kiemTraTrungLich(idBS, ngay, gio))
//     {
//         cout << "  BAC SI DA CO LICH KHAM VAO THOI GIAN NAY!\n";
//         return;
//     }
// //     Doctor *bs = timBacSiTheoID(idBS);
// //     if (bs)
// //     {
// //         cout << "Bac si: " << bs->getTenBS() << " (ID: " << idBS << ")\n";
// //     }
// //     cout << "Thoi gian: " << gio << " - " << ngay << endl;
// //     cout << "Vui long chon thoi gian khac hoac bac si khac.\n";
// //     return;
// // }
// // Tự động gán MaLich và thêm vào danh sách
// if (soluongLK == succhuaLK)
// {
//     int newcplk = succhuaLK * 2;
//     LichKham *newdslk = new LichKham[newcplk];
//     for (int i = 0; i < soluongLK; i++)
//         newdslk[i] = dsLK[i];
//     delete[] dsLK;
//     dsLK = newdslk;
//     succhuaLK = newcplk;
// }

// stringstream ss;
// ss << "LK" << setw(3) << setfill('0') << next_idLK++;
// lk.setid(ss.str());

// dsLK[soluongLK++] = lk;
// cout << "Da them lich kham thanh cong. Ma: " << lk.getidlk() << "\n";
// saveLK();
// }
void Quanly::them(Patient &p) // hàm thêm quản lý nhân viên, bác sĩ
{
    if (soluong == succhua)
    {
        int newcp = succhua * 2;
        Patient *newds = new Patient[newcp];
        for (int i = 0; i < soluong; i++)
        {
            newds[i] = ds[i];
        }
        delete[] ds;
        ds = newds;
        succhua = newcp;
    }

    stringstream ss;
    ss << "BN" << setw(3) << setfill('0') << next_idbn++; // Tạo ra "BN001", "BN002",...
    p.setID(ss.str());
    // p.setID(to_string(next_idbn++));
    ds[soluong++] = p;
}
string Quanly::tolower1(string s) const
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::tolower(c)); });
    return s;
}

bool Quanly::ktratrungten(const string &ten) const
{
    string ten1 = trim(ten);
    for (int i = 0; i < soluong; i++)
    {
        if (tolower1(trim(ds[i].getName())) == tolower1(ten1))
            return true;
    }
    return false;
}

bool Quanly::ktratrungcccd(const string &cc) const
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getcccd() == cc)
            return true;
    }
    return false;
}

bool Quanly::ktratrungsdt(const string &sdt) const
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getsdt() == sdt)
            return true;
    }
    return false;
}

void Quanly::them()
{
    // Patient p;
    // p.nhap();
    // bool ktra = false;
    // for (int i = 0; i < soluong; i++)
    // {
    //     if (ds[i].getName() == p.getName() || ds[i].getcccd() == p.getcccd())
    //     {
    //         cout << "Co nguoi trung ten. Vui long nhap ten khac... " << endl;
    //         ktra = true;
    //         break;
    //     }
    // }
    // if (!ktra)
    // {
    //     ds[soluong] = p;
    //     soluong++;
    // }
    Patient p;

    // lặp cho đến khi nhập hợp lệ (tên, cccd, sdt không trùng)
    while (true)
    {
        p.nhap(); // gọi hàm nhập từ Patient

        // kiểm tra trùng tên
        if (ktratrungten(p.getName()))
        {
            cout << "Ten benh nhan da ton tai! Vui long nhap ten khac.\n";
            // hỏi người dùng có muốn nhập lại hay hủy
            cout << "Ban muon nhap lai? (y/N): ";
            string ans;
            getline(cin, ans);
            if (ans.empty() || (ans[0] != 'y' && ans[0] != 'Y'))
                return;
            continue; // nhập lại
        }

        // kiểm tra trùng CCCD
        if (ktratrungcccd(p.getcccd()))
        {
            cout << "CCCD da ton tai! Vui long kiem tra lai.\n";
            cout << "Ban muon nhap lai? (y/N): ";
            string ans;
            getline(cin, ans);
            if (ans.empty() || (ans[0] != 'y' && ans[0] != 'Y'))
                return;
            continue;
        }

        // kiểm tra trùng SDT (tuỳ chọn)
        if (ktratrungsdt(p.getsdt()))
        {
            cout << "So dien thoai da ton tai! Vui long kiem tra lai.\n";
            cout << "Ban muon nhap lai? (y/N): ";
            string ans;
            getline(cin, ans);
            if (ans.empty() || (ans[0] != 'y' && ans[0] != 'Y'))
                return;
            continue;
        }

        // hợp lệ -> gán ID rồi thêm
        if (soluong == succhua)
        {
            int newcp = succhua * 2;
            Patient *newds = new Patient[newcp];
            for (int i = 0; i < soluong; i++)
                newds[i] = ds[i];
            delete[] ds;
            ds = newds;
            succhua = newcp;
        }

        stringstream ss;
        ss << "BN" << setw(3) << setfill('0') << next_idbn++;
        p.setID(ss.str());

        ds[soluong++] = p;
        cout << "Da them benh nhan thanh cong. ID: " << p.getID() << "\n";
        save();
        break;
    }
}
void Quanly::load()
{
    ifstream fin("BenhNhan.txt");
    if (!fin.is_open())
        return;

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        Patient p = Patient::read(line);
        if (soluong < succhua)
            ds[soluong++] = p;

        string id_str = p.getID();
        if (!id_str.empty() && id_str.rfind("BN", 0) == 0) // kiểm tra bắt đầu bằng "BN"
        {
            string num = id_str.substr(2); // Lấy phần số sau "BN"
            if (all_of(num.begin(), num.end(), ::isdigit))
            {
                int idnum = stoi(num);
                if (idnum >= next_idbn)
                    next_idbn = idnum + 1;
            }
        }
    }
    fin.close();
}
void Quanly ::xuat()
{
    for (int i = 0; i < soluong; i++)
    {
        ds[i].hienthithongtinbn();
        // ds[i].xuatdstufile("BenhNhan.txt", "BangBenhNhan.txt");
    }
    ds[0].xuatdstufile("BenhNhan.txt", "BangBenhNhan.txt");
}
void Quanly::cleanfile(const string &fname)
{
    ifstream fin(fname);
    if (!fin.is_open())
    {
        // cerr << "0 mo duoc file" << fname << "de ghi\n";
        return;
    }
    int dem = 0;
    string line;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        int ppdem = count_if(line.begin(), line.end(), [](char c)
                             { return c == '|'; });
        if (ppdem >= 5) // vai truong toi thieu
        {
            dem++;
        }
    }
    fin.clear();
    fin.seekg(0);
    // cap phat mang dong
    string *vlline = new string[dem];
    int idx = 0;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        int ppdem = count_if(line.begin(), line.end(), [](char c)
                             { return c == '|'; });
        if (ppdem >= 5)
        {
            vlline[idx++] = line;
        }
    }
    fin.close();
    ofstream fout(fname, ios::trunc);
    if (!fout.is_open())
    {
        /// cerr << "0 mo duoc file de ghi " << endl;
        delete[] vlline;
        return;
    }

    fout.close();
    delete[] vlline;
    /// cout << "Da don file " << fname << ", giu lai " << idx << " dong hop le";
}
void Quanly::save()
{
    ofstream fout("BenhNhan.txt", ios::trunc);
    if (!fout.is_open())
    {
        cerr << "0 mo duoc file\n";
        return;
    }
    for (int i = 0; i < soluong; i++)
    {
        /// ds[i].write("BenhNhan.txt");
        fout << ds[i].chuoi();
    }
    fout.close();
    /// cleanfile("BenhNhan.txt");
}
void Quanly::xoa(const string &id)
{
    int idx = -1;
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getID() == id)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "0 tim thay benh nhan co ID la: " << id << endl;
        return;
    }
    cout << "da xoa benh nhan co ID la: " << ds[idx].getID() << "- Ten: " << ds[idx].getName() << endl;
    for (int i = idx; i < soluong - 1; i++)
    {
        ds[i] = ds[i + 1];
    }
    soluong--;
    ofstream fout("BenhNhan.txt");
    for (int i = 0; i < soluong; i++)
    {
        fout << ds[i].chuoi() << endl;
    }
    fout.close();
    save();
}
void Quanly::sua(const string &id)
{
    int idx = -1;
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getID() == id)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "0 tim thay benh nhan co ID: " << id << endl;
        return;
    }
    cout << "Sua thong tin benh nhan co ID " << id << endl;
    cout << "Thong tin old: " << endl;
    ds[idx].hienthithongtinbn();
    cout << "<============================>" << endl;
    cout << "Nhap thong tin moi ( hay de trong neu muon giu nguyen )" << endl;
    string tp;
    cin.ignore();
    /// kiem tra ten
    cout << "Ten bn ( " << ds[idx].getName() << " ):";
    getline(cin, tp);
    if (!tp.empty())
        ds[idx].setTen(tp);
    /// kiem tra gioi tinh
    cout << "Gioi tinh (1: Nam, 2: Nu ) [" << ds[idx].getgt() << "]: ";
    getline(cin, tp);
    if (!tp.empty())
        ds[idx].setGT(stoi(tp));
    /// khoi tao kiem tra so dien thoai
    do
    {
        cout << "So dt ( " << ds[idx].getsdt() << " ): ";
        getline(cin, tp);
        if (tp.empty())
            break;
        if (ds[idx].Ktrasdt(tp))
        {
            ds[idx].setsdt(tp);
            break;
        }
        cout << "So dien thoai 0 hop le. Moi nhap lai\n";
    } while (true);
    /// sua cccd
    do
    {
        cout << "CCCD ( " << ds[idx].getcccd() << " ): ";
        getline(cin, tp);
        if (tp.empty())
            break;
        if (ds[idx].Ktracccd(tp))
        {
            ds[idx].setcccd(tp);
            break;
        }
        cout << "CCCD 0 hop le!. Moi nhap lai\n";
    } while (true);
    /// ktra ngay thang nam sinh
    cout << "Ngay sinh ( " << ds[idx].getngay() << " ): " << endl;
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].setngay(stoi(tp));
    }
    cout << "Thang ( " << ds[idx].getthang() << " ): ";
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].setthang(stoi(tp));
    }
    cout << "Nam ( " << ds[idx].getnam() << " ): ";
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].setnam(stoi(tp));
    }
    /// ktra dia chi
    cout << "Dia chi ( de trong neu giu nguyen )\n";
    cout << "To ( " << ds[idx].getto() << " ): " << endl;
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].setto(tp);
    }
    cout << "Phuong ( " << ds[idx].getphuong() << " ): " << endl;
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].setphuong(tp);
    }
    cout << "Thanh pho ( " << ds[idx].gettp1() << " ): " << endl;
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].settp1(tp);
    }
    cout << "Quoc gia ( " << ds[idx].getqg() << " ): " << endl;
    getline(cin, tp);
    if (!tp.empty())
    {
        ds[idx].setqg(tp);
    }
    // cap nhat file
    ofstream fout("BenhNhan.txt");
    for (int i = 0; i < soluong; i++)
    {
        fout << ds[i].chuoi();
    }
    fout.close();
    cout << "Da cap nhat thong tin benh nhan co ID " << id << "thanh cong.\n";
}
/// Bac Si

void Quanly::thembs(Doctor &d) // hàm thêm quản lý nhân viên, bác sĩ
{
    if (soluongbs == succhuabs)
    {
        int newcpbs = succhuabs * 2;
        Doctor *newdsbs = new Doctor[newcpbs];
        for (int i = 0; i < soluongbs; i++)
        {
            newdsbs[i] = dsbs[i];
        }
        delete[] dsbs;
        dsbs = newdsbs;
        succhuabs = newcpbs;
    }
    stringstream ss;
    ss << "BS" << setw(3) << setfill('0') << next_idbs++; // 001
    d.setIDBS(ss.str());
    // p.setID(to_string(next_idbn++));
    dsbs[soluongbs++] = d;
}
void Quanly::xuatbs()
{
    if (soluongbs == 0)
    {
        cout << "Khong co bs nao! \n";
        return;
    }
    for (int i = 0; i < soluongbs; i++)
    {
        // cout << "\n Bac si thu: " << i + 1 << "--- \n";
        dsbs[i].hienthithongtinbs();
        /// dsbs[i].xuatdsbstufile("BacSi.txt", "BangBacSi.txt");
    }
    dsbs[0].xuatdsbstufile("BacSi.txt", "BangBacSi.txt"); // sau khi chạy xong thì in ra 1 lần duy nhất
}
void Quanly::loadbs()
{
    ifstream fin("BacSi.txt");
    if (!fin.is_open())
        return;

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        Doctor p = Doctor::read(line);
        /// ds.push_back();
        thembs(p);
        string id_str = p.getIDBS();
        if (!id_str.empty() && id_str.rfind("BS", 0) == 0) // nếu bắt đầu bằng "BS"
        {
            string num = id_str.substr(2);
            if (all_of(num.begin(), num.end(), ::isdigit))
            {
                int idnum = stoi(num);
                if (idnum >= next_idbs)
                    next_idbs = idnum + 1;
            }
        }
    }
    fin.close();
}
void Quanly::cleanfilebs(const string &fname)
{
    ifstream fin(fname);
    if (!fin.is_open())
    {
        /// cerr << "0 mo duoc file" << fname << "de ghi\n";
        return;
    }
    int dem = 0;
    string line;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        int ppdem = count_if(line.begin(), line.end(), [](char c)
                             { return c == '|'; });
        if (ppdem >= 3) // vai truong toi thieu
        {
            dem++;
        }
    }
    fin.clear();
    fin.seekg(0);
    // cap phat mang dong
    string *vlline = new string[dem];
    int idx = 0;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        int ppdem = count_if(line.begin(), line.end(), [](char c)
                             { return c == '|'; });
        if (ppdem >= 5)
        {
            vlline[idx++] = line;
        }
    }
    fin.close();
    ofstream fout(fname, ios::trunc);
    if (!fout.is_open())
    {
        /// cerr << "0 mo duoc file de ghi " << endl;
        delete[] vlline;
        return;
    }
    fout.close();
    delete[] vlline;
    /// cout << "Da don file " << fname << ", giu lai " << idx << " dong hop le";
}
void Quanly::savebs()
{
    ofstream fout("BacSi.txt");
    if (!fout.is_open())
    {
        cerr << "0 mo duoc file\n";
        return;
    }
    for (int i = 0; i < soluongbs; i++)
    {
        dsbs[i].write();
    }
    fout.close();
    // cleanfile("BacSi.txt");
}
void Quanly::xoabs(const string &id)
{
    int idx = -1;
    for (int i = 0; i < soluongbs; i++)
    {
        if (dsbs[i].getIDBS() == id)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "0 tim thay bac si co ID la: " << id << endl;
        return;
    }
    cout << "da xoa bac si co ID la: " << dsbs[idx].getIDBS() << "- Ten: " << dsbs[idx].getTenBS() << endl;
    for (int i = idx; i < soluongbs - 1; i++)
    {
        dsbs[i] = dsbs[i + 1];
    }
    soluongbs--;
    ofstream fout("BacSi.txt");
    for (int i = 0; i < soluongbs; i++)
    {
        fout << dsbs[i].chuoibs() << endl;
    }
    fout.close();
}
// bool Quanly::kiemTraTrungLich(const string &idBS, const string &ngay, const string &gio) const
// {
//     for (int i = 0; i < soluongLK; i++)
//     {
//         if (dsLK[i].getIDBS() == idBS &&
//             dsLK[i].getday() == ngay &&
//             dsLK[i].gettime() == gio)
//         {
//             return true;
//         }
//     }
//     return false;
// }

Doctor *Quanly::timBacSiTheoID(const string &id)
{
    for (int i = 0; i < soluongbs; i++)
    {
        if (dsbs[i].getIDBS() == id)
            return &dsbs[i];
    }
    return nullptr;
}

Patient *Quanly::timBenhNhanTheoID(const string &id)
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getID() == id)
            return &ds[i];
    }
    return nullptr;
}

void Quanly::hienThiThongTinBS(const string &id)
{
    Doctor *bs = timBacSiTheoID(id);
    if (bs)
    {
        cout << "\n=== THONG TIN BAC SI ===\n";
        bs->hienthithongtinbs();
    }
    else
    {
        cout << "Khong tim thay bac si voi ID: " << id << endl;
    }
}

void Quanly::hienThiThongTinBN(const string &id)
{
    Patient *bn = timBenhNhanTheoID(id);
    if (bn)
    {
        cout << "\n=== THONG TIN BENH NHAN ===\n";
        bn->hienthithongtinbn();
    }
    else
    {
        cout << "Khong tim thay benh nhan voi ID: " << id << endl;
    }
}

void Quanly::themLichKhamVoiID()
{
    cout << "\n === DAT LICH KHAM MOI (SU DUNG ID) ===\n";

    // Hiển thị danh sách để tham khảo
    cout << "\n--- DANH SACH BAC SI ---\n";
    xuatbs();

    // cout << "\n--- DANH SACH BENH NHAN ---\n";
    // xuat();

    string idBS, idBN, ngay, gio;

    cout << "Nhap ID bac si: ";
    getline(cin, idBS);

    Doctor *bs = timBacSiTheoID(idBS);
    if (!bs)
    {
        cout << " ID bac si khong ton tai!\n";
        return;
    }

    cout << "Nhap ID benh nhan: ";
    getline(cin, idBN);

    if (!timBenhNhanTheoID(idBN))
    {
        cout << " ID benh nhan khong ton tai!\n";
        return;
    }

    cout << "Nhap ngay kham (dd/mm/yyyy): ";
    getline(cin, ngay);
    cout << "Nhap gio kham (hh:mm): ";
    getline(cin, gio);

    // Kiểm tra trùng lịch
    if (kiemTraTrungLich(idBS, ngay, gio))
    {
        cout << " BAC SI DA CO LICH KHAM VAO THOI GIAN NAY!\n";
        cout << "Vui long chon thoi gian khac hoac bac si khac.\n";
        return;
    }
    double tien = LichKham::tinhTienTheoChuyenKhoa(bs->getck());

    // Tạo lịch khám mới
    if (soluongLK == succhuaLK)
    {
        int newcplk = succhuaLK * 2;
        LichKham *newdslk = new LichKham[newcplk];
        for (int i = 0; i < soluongLK; i++)
            newdslk[i] = dsLK[i];
        delete[] dsLK;
        dsLK = newdslk;
        succhuaLK = newcplk;
    }

    string maLich = LichKham::taoMaTuDong(next_idLK++);
    LichKham lk(maLich, idBN, idBS, ngay, gio);
    dsLK[soluongLK++] = lk;

    cout << " DAT LICH THANH CONG!\n";
    cout << "Ma lich: " << maLich << endl;
    cout << "Bac si: " << bs->getTenBS() << endl;
    cout << "Chuyen khoa: ";
    switch (bs->getck())
    {
    case 1:
        cout << "Tim Mach";
        break;
    case 2:
        cout << "Noi Khoa";
        break;
    case 3:
        cout << "Ngoai Khoa";
        break;
    case 4:
        cout << "Da Lieu";
        break;
    case 5:
        cout << "Tai Mui Hong";
        break;
    case 6:
        cout << "Noi Tong Hop";
        break;
    }
    cout << "\nPhi kham: " << fixed << setprecision(0) << tien << " VND" << endl;
    cout << "Thoi gian: " << gio << " - " << ngay << endl;
    saveLK();
}

// void Quanly::xuatLichKhamDayDu()
// {
//     if (soluongLK == 0)
//     {
//         cout << "Khong co lich kham nao trong he thong!\n";
//         return;
//     }

//     cout << "\n=== DANH SACH LICH KHAM (DAY DU THONG TIN) ===\n";
//     cout << setfill(' ');
//     cout << "| " << left << setw(8) << "Ma Lich"
//          << "| " << setw(12) << "ID BS"
//          << "| " << setw(20) << "Ten Bac Si"
//          << "| " << setw(12) << "ID BN"
//          << "| " << setw(20) << "Ten Benh Nhan"
//          << "| " << setw(12) << "Ngay Kham"
//          << "| " << setw(8) << "Gio Kham"
//          << "| " << setw(12) << "Trang Thai" << "|\n";
//     cout << string(120, '-') << '\n';

//     for (int i = 0; i < soluongLK; i++)
//     {
//         Doctor *bs = timBacSiTheoID(dsLK[i].getIDBS());
//         Patient *bn = timBenhNhanTheoID(dsLK[i].getIDBN());

//         string tenBS = bs ? bs->getTenBS() : "Khong tim thay";
//         string tenBN = bn ? bn->getName() : "Khong tim thay";

//         cout << "| " << left << setw(8) << dsLK[i].getidlk()
//              << "| " << setw(12) << dsLK[i].getIDBS()
//              << "| " << setw(20) << tenBS
//              << "| " << setw(12) << dsLK[i].getIDBN()
//              << "| " << setw(20) << tenBN
//              << "| " << setw(12) << dsLK[i].getday()
//              << "| " << setw(8) << dsLK[i].gettime()
//              << "| " << setw(12) << dsLK[i].trangThai.getTrangthai() << "|\n";
//     }
//     cout << string(120, '-') << '\n';
// }
void Quanly::xuatLichKhamDayDu()
{
    if (soluongLK == 0)
    {
        cout << "Khong co lich kham nao trong he thong!\n";
        return;
    }

    cout << "\n=== DANH SACH LICH KHAM (DAY DU THONG TIN) ===\n";
    cout << setfill(' ');
    cout << "| " << left << setw(8) << "Ma Lich"
         << "| " << setw(12) << "ID BS"
         << "| " << setw(20) << "Ten Bac Si"
         << "| " << setw(12) << "ID BN"
         << "| " << setw(20) << "Ten Benh Nhan"
         << "| " << setw(12) << "Ngay Kham"
         << "| " << setw(8) << "Gio Kham"
         << "| " << setw(12) << "Trang Thai" << "|\n";
    cout << string(120, '-') << '\n';

    for (int i = 0; i < soluongLK; i++)
    {
        Doctor *bs = timBacSiTheoID(dsLK[i].getIDBS());
        Patient *bn = timBenhNhanTheoID(dsLK[i].getIDBN());

        string tenBS = bs ? bs->getTenBS() : "Khong tim thay";
        string tenBN = bn ? bn->getName() : "Khong tim thay";

        cout << "| " << left << setw(8) << dsLK[i].getidlk()
             << "| " << setw(12) << dsLK[i].getIDBS()
             << "| " << setw(20) << tenBS
             << "| " << setw(12) << dsLK[i].getIDBN()
             << "| " << setw(20) << tenBN
             << "| " << setw(12) << dsLK[i].getday()
             << "| " << setw(8) << dsLK[i].gettime()
             << "| " << setw(12) << dsLK[i].trangThai.getTrangthai() << "|\n";
    }
    cout << string(120, '-') << '\n';
}
void Quanly::thongKeChiTiet()
{
    cout << "\n=== THONG KE HE THONG ===\n";
    cout << "Tong so benh nhan: " << soluong << endl;
    cout << " Tong so bac si: " << soluongbs << endl;
    cout << " Tong so lich kham: " << soluongLK << endl;

    // Thống kê lịch khám theo trạng thái
    int hoanthanh = 0, dangcho = 0, dahuy = 0;
    for (int i = 0; i < soluongLK; i++)
    {
        string tt = dsLK[i].trangThai.getTrangthai();
        if (tt == "Hoan thanh")
            hoanthanh++;
        else if (tt == "Dang cho")
            dangcho++;
        else if (tt == "Da huy")
            dahuy++;
    }

    cout << "\n--- Trang thai lich kham ---\n";
    cout << " Hoan thanh: " << hoanthanh << endl;
    cout << " Dang cho: " << dangcho << endl;
    cout << " Da huy: " << dahuy << endl;
}
void Quanly::capNhatTrangThaiLichKham()
{
    if (soluongLK == 0)
    {
        cout << "Khong co lich kham nao trong he thong!\n";
        return;
    }

    cout << "\n=== CAP NHAT TRANG THAI LICH KHAM ===\n";
    string maLich;
    cout << "Nhap ma lich kham can cap nhat: ";
    getline(cin, maLich);

    for (int i = 0; i < soluongLK; i++)
    {
        if (dsLK[i].getidlk() == maLich)
        {
            dsLK[i].capnhatTrangThai();
            saveLK();
            cout << "Da cap nhat trang thai lich kham " << maLich << "!\n";
            return;
        }
    }
    cout << "Khong tim thay lich kham voi ma: " << maLich << endl;
}