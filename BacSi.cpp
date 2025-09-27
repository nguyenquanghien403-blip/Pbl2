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
void Doctor::nhap()
{
    cout << "Nhap ten bac si: ";
    getline(cin, tenBS);
    do
    {
        cout << "So dien thoai: ";
        cin >> sdt;
        if (!Ktrasdt(sdt))
            cout << "So dien thoai khong hop le!\nVui long nhap lai.....\n";
    } while (!Ktrasdt(sdt));
    cout << "Nhap chuyen khoa: " << '\n';
    cout << "1. Khoa tim mach\n";
    cout << "2. Noi Khoa\n";
    cout << "3. Ngoai khoa\n";
    cout << "4. Da lieu\n";
    cout << "5. Tai mui hong\n";
    cout << "Nhap lua chon cua ban tu (1->5): ";
    /// chuyen nganh khoa : khoa noi khoa ngoai khoa kham benh
    cin >> chuyenkhoa;
    switch (chuyenkhoa)
    {
    case 0:
        cout << "Khoa tim mach" << endl;
        break;
    case 2:
        cout << "Noi khoa" << endl;
        break;
    case 3:
        cout << "Ngoai khoa" << endl;
        break;
    case 4:
        cout << "Da lieu" << endl;
        break;
    case 5:
        cout << "Tai mui hong" << endl;
        break;
    default:
        cout << "Khong co khoa hop le!\n";
        break;
    }
}
string Doctor::write()
{
    stringstream s;
    s << tenBS << "|" << sdt << "|" << chuyenkhoa << "|" << endl;
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
    c.chuyenkhoa = stoi(ck); // định dạng về kiểu int
    return c;
}
void Doctor::hienthithongtinbs()
{
    cout << " Ho va ten bac si: " << tenBS << endl;
    cout << " So dien thoai: " << sdt << endl;
    switch (chuyenkhoa)
    {
    case 0:
        cout << " Khoa tim mach" << endl;
        break;
    case 2:
        cout << " Noi khoa" << endl;
        break;
    case 3:
        cout << " Ngoai khoa" << endl;
        break;
    case 4:
        cout << " Da lieu" << endl;
        break;
    case 5:
        cout << " Tai mui hong" << endl;
        break;
    default:
        cout << " Khong co khoa hop le!\n";
        break;
    }
}
