#include <bits/stdc++.h>
#include "LichKham.h"
LichKham::LichKham()
{
    MaLich = GioKham = NgayKham = "";
}

void LichKham::nhap()
{
    cout << "\n Nhap ma lich kham: ";
    getline(cin, MaLich);
    cout << "\n Nhap ngay Kham (dd/mm/yyyy): ";
    getline(cin, NgayKham);
    cout << "\n Nhap gio kham: ";
    getline(cin, GioKham);
    cout << "\n Nhap bac si kham: ";
    BacSi.nhapbs();
    cout << "\n Nhap thong tin benh nhan: ";
    BenhNhan.nhap();
    cout << "\n Nhập thông tin trang thai lich kham: ";
    Trangthai.nhap();
}
void LichKham::hienthithongtinlk()
{
    cout << "\n === LICH KHAM ===";
    cout << "\n ma lich: " << MaLich;
    cout << "\n ngay kham: " << NgayKham;
    cout << "\n gio kham: " << GioKham;
    cout << "\n bac si: ";
    BacSi.hienthithongtinbs();
    cout << "\n benh nhan: ";
    BenhNhan.hienthithongtinbn();
    /*cout << "\n phong kham: ";
    Phongkham.hienthithongtinpk();*/
    cout << "\n trang thai: ";
    Trangthai.hienthithongtin();
}
string LichKham::write() const
{
    stringstream ss;
    ss << MaLich << "|" << NgayKham << "|" << GioKham << "|" << BacSi.getIDBS() << "|" << BenhNhan.getID() << "|" << Trangthai << "\n";
    return ss.str();
}
LichKham LichKham::read(const string &line)
{
    LichKham lk;
    stringstream ss(line);
    string tk;
    getline(ss, lk.MaLich, '|');
    getline(ss, lk.NgayKham, '|');
    getline(ss, lk.GioKham, '|');

    string idbs, idbn;
    getline(ss, idbs, '|');
    getline(ss, idbn, '|');
    // getline(ss, lk.Trangthai, '|');

    lk.BacSi.setIDBS(idbs);
    lk.BenhNhan.setID(idbn);
    return lk;
}
string LichKham::getidlk() const
{
    return MaLich;
}
string LichKham::getday() const
{
    return NgayKham;
}
string LichKham::gettime() const
{
    return GioKham;
}
void LichKham::setid(const string &id)
{
    MaLich = id;
}
void LichKham::setday(const string &day)
{
    NgayKham = day;
}
void LichKham::settime(const string &gio)
{
    GioKham = gio;
}
Patient &LichKham::getBN()
{
    return BenhNhan;
}
void LichKham::setBN(const Patient &bn)
{
    BenhNhan = bn;
}
Doctor &LichKham::getDT()
{
    return BacSi;
}
void LichKham::setDT(const Doctor &bs)
{
    BacSi = bs;
}