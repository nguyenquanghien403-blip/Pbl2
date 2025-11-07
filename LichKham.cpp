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
bool LichKham::ktratrunglich(const LichKham *ds, int soluong) const
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].BacSi.getIDBS() == BacSi.getIDBS() &&
            ds[i].NgayKham == NgayKham &&
            ds[i].GioKham == GioKham)
        {
            return true; // trùng lịch
        }
    }
    return false;
}
void LichKham::capnhatTrangThai()
{
    cout << "\nCap nhat trang thai (1.Hoan thanh 2.Da huy 3.Dang cho): ";
    int chon;
    cin >> chon;
    cin.ignore();
    switch (chon)
    {
    case 1:
        Trangthai.setTrangthai("Hoan thanh");
        break;
    case 2:
        Trangthai.setTrangthai("Da huy");
        break;
    case 3:
        Trangthai.setTrangthai("Dang cho");
        break;
    default:
        cout << "Lua chon khong hop le!\n";
        break;
    }
}
void timkiemLichKham(LichKham *ds, int soluong, const string &key)
{
    string keylower = key;
    transform(keylower.begin(), keylower.end(), keylower.begin(), ::tolower);
    for (int i = 0; i < soluong; i++)
    {
        string tenbs = ds[i].BacSi.getTenBS();
        string tenbn = ds[i].BenhNhan.getName();
        transform(tenbs.begin(), tenbs.end(), tenbs.begin(), ::tolower);
        transform(tenbn.begin(), tenbn.end(), tenbn.begin(), ::tolower);

        if (ds[i].MaLich == key || tenbs.find(keylower) != string::npos || tenbn.find(keylower) != string::npos)
        {
            ds[i].hienthithongtinlk();
        }
    }
}
void sapxepLichTheoNgay(LichKham *ds, int soluong)
{
    for (int i = 0; i < soluong - 1; i++)
    {
        for (int j = i + 1; j < soluong; j++)
        {
            if (ds[i].getday() > ds[j].getday())
            {
                swap(ds[i], ds[j]);
            }
        }
    }
}
void xoalich(LichKham *ds, int &soluong, const string &ma)
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getidlk() == ma)
        {
            for (int j = i; j < soluong - 1; j++)
            {
                ds[j] = ds[j + 1];
            }
            soluong--;
            cout << "Da xoa lich kham co ma: " << ma << endl;
            return;
        }
    }
    cout << "Khong tim thay ma lich kham!\n";
}
void thongkeLich(LichKham *ds, int soluong)
{
    int hoanthanh = 0, dahuy = 0, dangcho = 0;
    for (int i = 0; i < soluong; i++)
    {
        string tt = ds[i].Trangthai.getTrangthai();
        if (tt == "Hoan thanh")
            hoanthanh++;
        else if (tt == "Da huy")
            dahuy++;
        else
            dangcho++;
    }
    cout << "\n=== Thong ke lich kham ===\n";
    cout << "Hoan thanh: " << hoanthanh << endl;
    cout << "Da huy: " << dahuy << endl;
    cout << "Dang cho: " << dangcho << endl;
}
string LichKham::taoMaTuDong(int stt)
{
    stringstream ss;
    ss << "LK" << setw(3) << setfill('0') << stt + 1;
    return ss.str();
}
void ghifileLichKham(LichKham *ds, int soluong, const string &filename)
{
    ofstream f(filename);
    if (!f.is_open())
    {
        cout << "Khong mo duoc file!\n";
        return;
    }
    for (int i = 0; i < soluong; i++)
    {
        f << ds[i].write();
    }
    f.close();
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