#include <bits/stdc++.h>
#include "PhongKham.h"
TrangThai_::TrangThai_()
{
    idtt = "";
    tentt = "";
    Khoa = "";
    slgbn = 0;
}
TrangThai_::TrangThai_(string id, string ten)
{
    idtt = id;
    tentt = ten;
    Khoa = "";
    slgbn = 0;
}
void TrangThai_::nhap()
{
    cout << " Nhap ma phong kham: ";
    getline(cin, idtt);
    cout << " Nhap ten phong kham; ";
    getline(cin, tentt);
    cout << " Nhap ten khoa: ";
    getline(cin, Khoa);
    cout << " Nhap thong tin bac si phu trach: \n";
    BacSi.nhapbs();
}
void TrangThai_::themBN()
{
    if (slgbn < 50)
    {
        cout << "\n Nhap thong tin benh nhan thu " << slgbn + 1 << ": ";
        dsBN[slgbn++].nhap();
    }
    else
    {
        cout << "\nPhong kham da day ";
    }
}
void TrangThai_::hienthithongtin()
{
    cout << "\n ==== PHONG KHAM ===";
    cout << "\n Ma phong: " << idtt;
    cout << "\n Ten phong: " << tentt;
    cout << "\n Ten khoa: " << Khoa;
    cout << "\n Bac si phu trach: ";
    cout << '\n';
    BacSi.hienthithongtinbs();
    /// cout << '\n';
    cout << "\n Danh sach benh nhan (" << slgbn << "): ";
    for (int i = 0; i < slgbn; i++)
        dsBN[i].hienthithongtinbn();
}
string TrangThai_::chuanhoa(string s)
{
    // Bỏ khoảng trắng
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    // Đưa về chữ thường
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
void TrangThai_::read(const string &line, const Doctor dsBS[], int soLuongBS)
{
    stringstream s(line);
    getline(s, idtt, '|');
    getline(s, tentt, '|');
    getline(s, Khoa, '|');

    // Gán bác sĩ phù hợp theo khoa
    for (int i = 0; i < soLuongBS; i++)
    {
        string tenKhoa;
        switch (dsBS[i].getck())
        {
        case 1:
            tenKhoa = "Tim Mach";
            break;
        case 2:
            tenKhoa = "Noi Khoa";
            break;
        case 3:
            tenKhoa = "Ngoai Khoa";
            break;
        case 4:
            tenKhoa = "Da Lieu";
            break;
        case 5:
            tenKhoa = "Tai Mui Hong";
            break;
        case 6:
            tenKhoa = "Noi Tong Hop";
            break;
        }
        if (chuanhoa(tenKhoa) == chuanhoa(Khoa))
        {
            BacSi = dsBS[i];
            BacSi.setIDBS("BS" + to_string(i + 1)); // tạo ID tự động
            break;
        }
    }
    cout << "DEBUG Khoa = [" << Khoa << "], gan BacSi = " << BacSi.getTenBS() << endl;
}

ostream &operator<<(ostream &out, const TrangThai_ &tt)
{
    out << tt.idtt << ", " << tt.tentt;
    return out;
}
istream &operator>>(istream &in, TrangThai_ &tt)
{
    cout << "Nhap ma trang thai: ";
    getline(in, tt.idtt);
    cout << "Nhap ten trang thai: ";
    getline(in, tt.tentt);
    return in;
}
string TrangThai_::getidtt() const
{
    return idtt;
}
string TrangThai_::gettentt() const
{
    return tentt;
}
void TrangThai_::setidtt(string id)
{
    idtt = id;
}
void TrangThai_::settentt(string ten)
{
    tentt = ten;
}