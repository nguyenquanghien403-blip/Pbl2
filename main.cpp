#include "BenhVien.h"
#include <iostream>
int main()
{
    Quanly ql(10);
    int luachon;
    do
    {
        cout << "\n ----- MENU CHUC NANG ------\n";
        cout << "1.Them benh nhan moi\n";
        cout << "2.Xuat ds benh nhan\n";
        cout << "3.Luu ds benh nhan\n";
        cout << "4.Xoa benh nhan\n";
        cout << "5.Don dep rac(clean file)\n";
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
    return 0;
}