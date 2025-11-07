#include "BenhVien.h"
#include "LichKham.h"
#include "PhongKham.h"
#include "ThongKe.h"
#include <iostream>
// Hàm hỗ trợ xóa bộ đệm nhập liệu sau khi dùng cin >>
void clear_input_buffer()
{
    if (cin.fail()) /// khi nhap sai kieu du lieu
    {
        cin.clear(); // xoa co loi
    }
    // Đảm bảo cin.ignore chỉ được gọi sau khi có cin >> hoặc getline,
    // tránh lỗi nếu bộ đệm đã trống
    if (cin.peek() != EOF)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void menubn(Quanly &ql)
{
    /// Quanly ql(10);
    int luachon;
    int lc1;
    do
    {
        cout << "\n ----- MENU CHUC NANG BENH NHAN ------\n";
        cout << "1.Them benh nhan moi\n";
        cout << "2.Xuat ds benh nhan\n";
        cout << "3.Luu ds benh nhan\n";
        cout << "4.Xoa benh nhan\n";
        cout << "5.Don dep rac(clean file)\n";
        cout << "6.Sua thong tin benh nhan\n";
        cout << "0.Thoat";
        cout << "-------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;
        cin.ignore();
        switch (luachon)
        {
        case 1:
        {
            Patient p;
            p.nhap(); // nhap thong tin benh nhan moi
            ql.them(p);
            break;
        }
        case 2:
        {
            ql.xuat(); // xuat ds hien co
            break;
        }
        case 3:
        {
            ql.save();
            break;
        }
        case 4:
        {
            string id;
            cout << "Nhap ID cua benh nhan can xoa\n";
            getline(cin, id);
            ql.xoa(id);
            ql.save();
            break;
        }
        case 5:
        {
            ql.cleanfile("BenhNhan.txt");
            break;
        }
        case 6:
        {
            string id;
            cout << "Nhap id benh nhan can tim: ";
            getline(cin, id);
            ql.sua(id);
            ql.save();
            break;
        }
        case 0:
        {
            cout << "Thoat menu\n";
            break;
        }
        default:
        {
            cout << "Lua chon 0 hop le!";
            cout << endl;
        }
        }
    } while (luachon != 0);
}
void menubs()
{
    Doctor ds[50];
    int n = 0;
    int luachon;
    do
    {
        cout << "\n===== MENU BAC SI =====\n";
        cout << "1. Nhap them thong tin bac si moi\n";
        cout << "2. Xuat danh sach bac si\n";
        cout << "3. Luu danh sach bac si vao file\n";
        cout << "4. Xoa bac si\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "===============================\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;
        cin.ignore();

        switch (luachon)
        {
        case 1:
            cout << "Nhap so luong bac si: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                cout << "\n Nhap bac si thu " << i + 1 << '\n';
                ds[i].nhapbs();
            }
            break;
        case 2:
        {
            // ifstream fout("BacSi.txt");
            // string line;
            // while (getline(fout, line))
            // {
            //     Doctor d = Doctor::read(line);
            //     d.hienthithongtinbs();
            //     d.xuatdsbstufile();
            // }
            // fout.close();
            // break;
            fstream fin("BacSi.txt");
            if (!fin.is_open())
            {
                cout << "Khong mo duoc file BacSi.txt!\n";
                break;
            }

            string line;
            while (getline(fin, line))
            {
                if (line.empty())
                    continue;
                Doctor d = Doctor::read(line);
                d.hienthithongtinbs(); // In ra màn hình
            }
            fin.close();

            Doctor temp;
            temp.xuatdsbstufile("BacSi.txt", "BangBacSi.txt");
            // cout << "Da xuat bang bac si ra file BangBacSi.txt\n";
            break;
        }
        case 3:
        {
            ofstream f("BacSi.txt", ios::app);
            for (int i = 0; i < n; i++)
            {
                f << ds[i].write();
            }
            f.close();
            cout << "Da luu danh sach bac si vao BacSi.txt\n";
            break;
        }
        case 4:
        {
            string idxoa;
            cout << "Nhap ID bac si can xoa  ";
            getline(cin, idxoa);
            bool t = false;
            for (int i = 0; i < n; i++)
            {
                if (ds[i].getIDBS() == idxoa)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        ds[j] = ds[j + 1];
                    }
                    n--;
                    t = true;
                    cout << "Da xoa bac si co ID: " << idxoa << endl;
                    break;
                }
            }
            if (!t)
            {
                cout << "Khong tim thay bac si co ID can xoa: " << idxoa << endl;
                /// break;
            }
            break;
        }
        case 0:
            cout << "Quay lai menu chinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (luachon != 0);
}
void menupk()
{
    TrangThai_ dspk[50];
    int n = 0;
    int chon;
    do
    {
        cout << "\n ------MENU PK -------\n";
        cout << "1.Nhap pk new \n";
        cout << "2.Xuat ds pk\n";
        cout << "3.Luu pk vao file\n";
        cout << "4.Doc ds pk tu file\n";
        cout << "0.Quay lai\n";
        cout << "----------------\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            if (n < 50)
            {
                cout << "\nNhap thong tin pk thu " << n + 1 << ":\n";
                dspk[n++].nhap();
            }
            else
            {
                cout << "DS da day";
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                dspk[i].hienthithongtin();
            }
            break;
        case 3:
        {
            ofstream f("PhongKham.txt", ios::app);
            for (int i = 0; i < n; i++)
            {
                f << dspk[i].getidtt() << "|" << dspk[i].gettentt() << "\n";
            }
            f.close();
            cout << "Da luu vao file\n";
            break;
        }
        case 4:
        {
            /*ifstream f("PhongKham.txt");
            string l;
            n = 0;
            while (getline(f, l) && n < 50)
            {
                stringstream ss(l);
                string id, ten;
                getline(ss, id, '|');
                getline(ss, ten, '|');
                dspk[n].setidtt(id);
                dspk[n].settentt(ten);
                n++;
            }
            f.close();
            cout << "Da doc ds pk tu file\n";
            break;*/
            // --- Đọc danh sách bác sĩ ---
            // Đọc danh sách bác sĩ trước
            ifstream fbs("Doctor.txt");
            string linebs;
            Doctor dsBS[50];
            int soBS = 0;
            while (getline(fbs, linebs))
            {
                if (!linebs.empty())
                    dsBS[soBS++] = Doctor::read(linebs);
            }
            fbs.close();

            // Đọc danh sách phòng khám
            ifstream f("PhongKham.txt");
            string line;
            n = 0;
            while (getline(f, line) && n < 50)
            {
                if (!line.empty())
                    dspk[n++].read(line, dsBS, soBS); // dùng hàm read vừa tạo
            }
            f.close();

            cout << "Da doc ds phong kham va gan bac si phu trach\n";
            break;
        }
        case 0:
            cout << "Quay lai\n";
            break;
        default:
            cout << "Lua chon 0 hop le!\n";
        }
    } while (chon != 0);
}
void MenuThongKe()
{
    ThongKe thongke;
    int choice;
    string input;

    do
    {
        cout << "\n--- MENU THONG KE / BAO CAO ---" << endl;
        cout << "1. Thong ke luot kham trong ngay" << endl;
        cout << "2. Thong ke so benh nhan trong thang" << endl;
        // Dựa vào LichKham.txt, các hàm thống kê này có thể không hoạt động chính xác
        // do định dạng file không khớp với code (ví dụ: dùng '|' thay vì ';')
        cout << "3. Tong doanh thu thang (Can co truong 'Tien' trong LichKham.txt)" << endl;
        cout << "4. Thong ke luot kham theo Bac si (theo MaBS)" << endl;
        cout << "0. Quay lai Menu chinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        clear_input_buffer();

        switch (choice)
        {
        case 1:
            cout << "Nhap ngay can thong ke (DD/MM/YYYY): ";
            getline(cin, input);
            thongke.Thongkeluotkhamtrongngay(input);
            break;
        case 2:
            cout << "Nhap thang can thong ke (VD: /10/): "; // Yêu cầu người dùng nhập định dạng tìm kiếm
            getline(cin, input);
            thongke.Thongkesobenhnhantrongthang(input);
            break;
        case 3:
            cout << "Nhap thang can tinh tong doanh thu (VD: /10/): ";
            getline(cin, input);
            thongke.Tongdoanhthuthang(input);
            break;
        case 4:
            cout << "Nhap Ma Bac si can thong ke (VD: BS01): ";
            getline(cin, input);
            thongke.Thongkebacsikham(input);
            break;
        case 0:
            cout << "Quay lai Menu chinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

// Hàm xử lý Lịch Khá (minh họa)
void MenuLichKham()
{
    int choice;
    LichKham lk;

    do
    {
        cout << "\n--- mMENU QUAN LY LICH KHAM ---" << endl;
        cout << "1. Tao LICH KHAM moi (Nhap day du thong tin)" << endl;
        cout << "2. Hien thi mot LICH KHAM minh hoa (Tu tao)" << endl;
        cout << "0. Quay lai Menu chinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        clear_input_buffer();

        switch (choice)
        {
        case 1:
            cout << "\n=== NHAP THONG TIN LICH KHAM ===" << endl;
            // LichKham::nhap() gọi cả Patient::nhap() và Doctor::nhapbs()
            lk.nhap();
            lk.hienthithongtinlk();
            // Lưu ý: Chưa có hàm lưu danh sách LichKham vào file
            break;
        case 2:
        {
            cout << "\n=== LICH KHAM MINH HOA ===" << endl;
            Doctor d_temp;
            d_temp.setIDBS("115");
            d_temp.settenbs("Bac Si Minh Hoa");
            d_temp.setck(1);

            Patient p_temp;
            p_temp.setID("010");
            p_temp.setTen("Benh Nhan Demo");

            LichKham lk_demo;
            lk_demo.setid("LK_DEMO");
            lk_demo.setday("27/10/2025");
            lk_demo.settime("14:30");
            lk_demo.setDT(d_temp);
            lk_demo.setBN(p_temp);

            lk_demo.hienthithongtinlk();
            cout << "Chuoi ghi file: " << lk_demo.write() << endl;
            break;
        }
        case 0:
            cout << "Quay lai Menu chinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

// void menulk()
// {
//     LichKham dslich[50];
//     int sl = 0;
//     int chon;
//     do
//     {
//         cout << "\n -----MENU LICH KHAM -----\n";
//         cout << "1.Nhap lich kham moi \n";
//         cout << "2.Hien thi tat ca lich kham dang co\n";
//         cout << "0.Quay lai";
//         cout << "------------------------------";
//         cout << '\n';
//         cout << "Nhap lua chon: ";
//         cin >> chon;
//         cin.ignore();
//         switch (chon)
//         {
//         case 1:
//             if (sl < 50)
//             {
//                 cout << "\nNhap lich kham thu " << sl + 1 << ":\n";
//                 dslich[sl++].nhap();
//             }
//             else
//             {
//                 cout << "DS lich kham da day!\n";
//             }
//             break;
//         case 2:
//             for (int i = 0; i < sl; i++)
//             {
//                 dslich[i].hienthithongtinlk();
//             }
//             break;
//         case 3:
//         {
//             ofstream f("LichKham.txt", ios::app);
//             for (int i = 0; i < sl; i++)
//             {
//                 f << dslich[i].write() << '\n';
//             }
//             f.close();
//             cout << "Da luu ds lich kham vao file! ";
//             cout << '\n';
//             break;
//         }
//         case 4:
//         {
//             ifstream f("LichKham.txt");
//             string l;
//             sl = 0;
//             while (getline(f, l) && sl < 50)
//             {
//                 dslich[sl++] = LichKham::read(l);
//             }
//             f.close();
//             cout << "Da doc lich kham tu file";
//             cout << '\n';
//             break;
//         }
//         case 0:
//             cout << "Quay lai!";
//             cout << '\n';
//             break;
//         default:
//             cout << "Lua chon 0 hop le! ";
//             cout << '\n';
//         }
//     } while (chon != 0);
// }
int main()
{
    Quanly ql(10); // quản lý bệnh nhân
    int luachon;

    do
    {
        cout << "\n======= MENU MAIN =======\n";
        cout << "1. Quan ly benh nhan\n";
        cout << "2. Quan ly bac si\n";
        cout << "3. Quan ly phong kham\n";
        cout << "4. Quan ly lich kham\n";
        cout << "5. Thong ke\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "==========================\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;
        cin.ignore();

        switch (luachon)
        {
        case 1:
            menubn(ql);
            break;
        case 2:
            menubs();
            break;
        case 3:
            menupk();
            break;
        case 4:
            MenuLichKham();
            break;
        case 5:
            MenuThongKe();
            break;
        case 0:
            cout << "Thoat chuong trinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (luachon != 0);

    return 0;
}