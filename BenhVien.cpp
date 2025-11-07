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
Quanly::Quanly(int cp, int cpbs)
{

    succhua = cp;
    succhuabs = cpbs;
    soluong = 0;
    soluongbs = 0;
    next_idbn = 1;
    next_idbs = 1;
    dsbs = new Doctor[succhuabs];
    ds = new Patient[succhua];
    // cleanfile("BenhNhan.txt");
    //  0 cleanfile("Doctor.txt");
    load();
    loadbs();
}
Quanly::~Quanly()
{
    delete[] ds;
    delete[] dsbs;
}
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
    ss << setw(3) << setfill('0') << next_idbn++; // 001
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
        ss << setw(3) << setfill('0') << next_idbn++;
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
        /// ds.push_back();
        // them(p);
        if (soluong < succhua)
            ds[soluong++] = p;
        string id_str = p.getID();
        if (!id_str.empty() && all_of(id_str.begin(), id_str.end(), ::isdigit)) /// neu id trong hoac rong se bo qua
        {
            int idsum = stoi(id_str);
            if (idsum >= next_idbn)
                next_idbn = idsum + 1;
        }
    }
    fin.close();
}
void Quanly ::xuat()
{
    for (int i = 0; i < soluong; i++)
    {
        ds[i].hienthithongtinbn();
        ds[i].xuatdstufile("BenhNhan.txt", "BangBenhNhan.txt");
    }
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
        ds[i].write("BenhNhan.txt");
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
    cleanfile("BacSi.txt");
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
