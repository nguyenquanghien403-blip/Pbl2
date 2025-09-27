#include "BenhNhan.h"
#include <bits/stdc++.h>
bool Patient::Ktrasdt(const string &p)
{
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
bool Patient::Ktracccd(const string &cid)
{
    if (cid.length() != 12)
        return false;
    for (char pid : cid)
    {
        if (pid < '0' || pid > '9')
            return false;
    }
    return true;
}
bool Patient::Ktrangaythangnamsinh(int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12)
        return false;
    if (ngay < 1 || ngay > 31)
        return false;
    /// CÁC THÁNG CÓ 30 NGÀY
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
    {
        return ngay <= 30;
    }
    bool namnhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    if (thang == 2)
    {
        return ngay <= (namnhuan ? 29 : 28);
    }
    return true;
}

string Patient::write()
{
    stringstream s;
    s << tenBN << "|" << gioitinh << "|" << sdtbn << "|" << cccd << "|" << ngay << "|" << thang << "|" << nam << "|" << diachi_to << "|" << diachi_phuong << "|" << diachi_tp << "|" << diachi_qg << endl;
    return s.str();
}
Patient Patient::read(const string &p)
{
    stringstream s(p);
    string token;
    Patient c;
    getline(s, c.tenBN, '|');
    getline(s, c.sdtbn, '|');
    /*string ck;
    getline(s, ck, '|');
    c.chuyenkhoa = stoi(ck); // định dạng về kiểu int*/
    cin >> c.gioitinh;
    cout << '|';
    getline(s, c.cccd, '|');
    cin >> c.ngay;
    cout << '|';
    cin >> c.thang;
    cout << '|';
    cin >> c.nam;
    cout << '|';
    getline(s, c.diachi_to, '|');
    getline(s, c.diachi_phuong, '|');
    getline(s, c.diachi_tp, '|');
    getline(s, c.diachi_qg, '|');
    return c;
}
void Patient::nhap()
{
    cout << "Ten benh nhan: ";
    getline(cin, tenBN);
    cout << "Chon gioi tinh:\n";
    cout << "1. Nam\n";
    cout << "2. Nu\n";
    cout << "Nhap lua chon (1 hoac 2): ";
    cin >> gioitinh;
    cout << "Gioi tinh: ";
    switch (gioitinh)
    {
    case 1:
        cout << "Nam" << endl;
        break;
    case 2:
        cout << "Nu" << endl;
        break;
    default:
        cout << "0 hop le" << endl;
    }
    do
    {
        cout << "Nhap so dien thoai: ";
        cin >> sdtbn;
        if (!Ktrasdt(sdtbn))
        {
            cout << "So dien thoai khong hop le!\nVui long nhap lai...." << endl;
        }
    } while (!Ktrasdt(sdtbn));
    do
    {
        cout << "Can cuoc cong dan: ";
        cin >> cccd;
        if (!Ktracccd(cccd))
        {
            cout << "Can cuoc cong dan khong hop le!\nVui long nhap lai...." << endl;
        }
    } while (!Ktracccd(cccd));
    do
    {
        cout << "- Ngay: ";
        cin >> ngay;
        cout << "- Thang: ";
        cin >> thang;
        cout << "- Nam: ";
        cin >> nam;
        if (!Ktrangaythangnamsinh(ngay, thang, nam))
        {
            cout << "Ngay - thang - nam sinh khong hop le!\nVui long nhap lai.... " << endl;
        }
    } while (!Ktrangaythangnamsinh(ngay, thang, nam));
    cin.ignore();
    cout << "Nhap to: ";
    getline(cin, diachi_to);
    cout << "Nhap phuong: ";
    getline(cin, diachi_phuong);
    cout << "Nhap thanh pho: ";
    getline(cin, diachi_tp);
    cout << "Nhap quoc gia: ";
    getline(cin, diachi_qg);
}
void Patient::hienthithongtinbn()
{
    cout << "Ten benh nhan: " << tenBN << endl;
    cout << "So dien thoai: " << sdtbn << endl;
    cout << " Gioi tinh: " << gioitinh << endl;
    cout << "Can cuoc cong dan: " << cccd << endl;
    cout << " Ngay: " << ngay << " Thang " << thang << " Nam " << nam << endl;
    cout << " Dia chi: " << endl;
    cout << "-To: " << diachi_to << endl;
    cout << "-Phuong: " << diachi_phuong << endl;
    cout << "-Thanh pho: " << diachi_tp << endl;
    cout << "-Quoc gia: " << diachi_qg << endl;
}
