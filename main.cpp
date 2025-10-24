#include "BenhVien.h"
#include "LichKham.h"
#include "PhongKham.h"
#include <iostream>
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
            ifstream fout("BacSi.txt");
            string line;
            while (getline(fout, line))
            {
                Doctor d = Doctor::read(line);
                d.hienthithongtinbs();
            }
            fout.close();
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
    TrangThai dspk[50];
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
void menulk()
{
    LichKham dslich[50];
    int sl = 0;
    int chon;
    do
    {
        cout << "\n -----MENU LICH KHAM -----\n";
        cout << "1.Nhap lich kham moi \n";
        cout << "2.Hien thi tat ca lich kham dang co\n";
        cout << "0.Quay lai";
        cout << "------------------------------";
        cout << '\n';
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();
        switch (chon)
        {
        case 1:
            if (sl < 50)
            {
                cout << "\nNhap lich kham thu " << sl + 1 << ":\n";
                dslich[sl++].nhap();
            }
            else
            {
                cout << "DS lich kham da day!\n";
            }
            break;
        case 2:
            for (int i = 0; i < sl; i++)
            {
                dslich[i].hienthithongtinlk();
            }
            break;
        case 3:
        {
            ofstream f("LichKham.txt", ios::app);
            for (int i = 0; i < sl; i++)
            {
                f << dslich[i].write() << '\n';
            }
            f.close();
            cout << "Da luu ds lich kham vao file! ";
            cout << '\n';
            break;
        }
        case 4:
        {
            ifstream f("LichKham.txt");
            string l;
            sl = 0;
            while (getline(f, l) && sl < 50)
            {
                dslich[sl++] = LichKham::read(l);
            }
            f.close();
            cout << "Da doc lich kham tu file";
            cout << '\n';
            break;
        }
        case 0:
            cout << "Quay lai!";
            cout << '\n';
            break;
        default:
            cout << "Lua chon 0 hop le! ";
            cout << '\n';
        }
    } while (chon != 0);
}
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
            menulk();
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