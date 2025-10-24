#include "Bacsi.h"
int Doctor::next_ID = 10;
bool Doctor::Ktrasdt(const string &p)
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
void Doctor::nhapbs()
{
    cout << "Nhap ten bac si: ";
    getline(cin, tenBS);
    string tp;
    do
    {
        cout << "So dien thoai: ";
        getline(cin, tp);
        if (!Ktrasdt(tp))
        {
            cout << "So dien thoai khong hop le! Vui long nhap lai .... \n";
        }
    } while (!Ktrasdt(tp));
    sdt = tp;
    cout << "Nhap chuyen khoa: \n";
    cout << "1.Khoa tim mach\n2.Noi khoa\n3.Ngoai khoa\n4.Da lieu\n5.Tai mui hong\n";
    int ck = 0;
    do
    {
        cout << "Nhap lua chon chuyen khoa (1 - 5): ";
        getline(cin, tp);
        try
        {
            ck = stoi(tp);
        }
        catch (...) /// kiem tra bat loi
        {
            ck = 0;
        }
        if (ck < 1 || ck > 5)
            cout << "Lua chon khong hop le.Nhap lai\n";
    } while (ck < 1 || ck > 5);
    chuyenkhoa = ck;
    /// chuyen nganh khoa : khoa noi khoa ngoai khoa kham benh
}
string Doctor::write()
{
    stringstream s;
    s << id_BS << "|" << tenBS << "|" << sdt << "|" << chuyenkhoa << "|" << endl;
    return s.str();
}
Doctor Doctor::read(const string &p)
{
    stringstream s(p);
    string token;
    Doctor c;
    getline(s, c.tenBS, '|');
    getline(s, c.sdt, '|');
    string ck;
    getline(s, ck, '|');
    if (!ck.empty() && all_of(ck.begin(), ck.end(), ::isdigit))
    {
        c.chuyenkhoa = stoi(ck); // định dạng về kiểu int
    }
    else
        c.chuyenkhoa = 0; // gtri mac dinh
    return c;
}
void Doctor::hienthithongtinbs()
{
    cout << "ID Bac si: " << id_BS << endl;
    cout << " Ho va ten bac si: " << tenBS << endl;
    cout << " So dien thoai: " << sdt << endl;
    cout << " Chuyen khoa: ";
    switch (chuyenkhoa)
    {
    case 1:
        cout << " Khoa Tim Mach" << endl;
        break;
    case 2:
        cout << " Noi Khoa" << endl;
        break;
    case 3:
        cout << " Ngoai Khoa" << endl;
        break;
    case 4:
        cout << " Da Lieu" << endl;
        break;
    case 5:
        cout << " Tai Mui Hong" << endl;
        break;
    case 6:
        cout << " Noi Tong Hop" << endl;
        break;
    default:
        cout << " Khong co khoa hop le!\n";
        break;
    }
    cout << endl;
}
string Doctor::getIDBS() const
{
    return id_BS;
}
string Doctor::getTenBS() const
{
    return tenBS;
}
string Doctor::getsdtbs() const
{
    return sdt;
}
int Doctor::getck() const
{
    return chuyenkhoa;
}
void Doctor::setIDBS(string i_d)
{
    id_BS = i_d;
}
void Doctor::settenbs(string ten)
{
    tenBS = ten;
}
void Doctor::setsdt(string sodt)
{
    sdt = sodt;
}
void Doctor::setck(int c_k)
{
    chuyenkhoa = c_k;
}
string Doctor::chuoibs() const
{
    stringstream ss;
    ss << id_BS << "|" << tenBS << "|" << chuyenkhoa << "|" << sdt << endl;
    return ss.str();
}