#include "Bacsi.h"
bool Ktrasdt(const string &p)
{
    /// so dien thoai co 10 so
    /// luc dau bat dau co
    if (p.length() != 10)
        return false;
    if (p[0] != '0')
        return false;
    for (char c : p)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}
void Doctor::nhap()
{
    cin >> id_BS;
    cout << "Nhap ten bac si: ";
    getline(cin, tenBS);
    cin.ignore();
    cout << "So dien thoai";
    getline(cin, sdt);
    do
    {
        if (!Ktrasdt(sdt))
            cout << "So dien thoai khong hop le!\nVui long nhap lai.....";
    } while (!Ktrasdt(sdt));
    cout << "Nhap chuyen khoa: ";
    /// chuyen nganh khoa : khoa noi khoa ngoai khoa kham benh
    cout << "Chuyen nganh: ";
    getline(cin, chuyenkhoa);
    cin.ignore();
    cout << " chon phong ban" << '\n';
    cout << "Lua chon tu 1-9" << '\n';
    // cout<<""
    int Khoa = 5;
    switch (Khoa)
    {
    case 1:
        cout << "Khoa tim mach";
    case 2:
        cout << "Noi khoa";
    case 3:
        cout << "Ngoai khoa";
    case 4:
        cout << "Da lieu";
    case 5:
        cout << "Tai mui hong";
    default:
        cout << "Khong co khoa hop le!\n";
    }
}
void Doctor::hienthithongtinbs()
{
    cout << " Ho va ten bac si: " << tenBS << endl;
    cout << " Chuyen khoa: " << chuyenkhoa << endl;
    cout << " So dien thoai: " << sdt << endl;
}