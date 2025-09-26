#include "BenhNhan.h"
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

void Patient::nhap()
{
    cout << "Ten benh nhan: ";
    getline(cin, tenBN);
    int gioitinh;
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
    cout << "Can cuoc cong dan: " << cccd << endl;
    cout << " Ngay: " << ngay << " Thang " << thang << " Nam " << nam << endl;
    cout << " Dia chi: " << endl;
    cout << "-To: " << diachi_to << endl;
    cout << "-Phuong: " << diachi_phuong << endl;
    cout << "-Thanh pho: " << diachi_tp << endl;
    cout << "-Quoc gia: " << diachi_qg << endl;
}
void Doctor::nhap()
{
    getline(cin, tenBS);
    getline(cin, chuyenkhoa);
    cin >> sdtbs;
    cin.ignore();
    getline(cin, phongLV);
}
void Doctor::hienthithongtinbs()
{
    cout << "Ten bac si: " << tenBS << endl;
    cout << "Chuyen khoa: " << chuyenkhoa << endl;
    cout << "So dien thoai cua bac si: " << sdtbs << endl;
}
void Lichkham::nhap()
{
    cin >> ngaykham;
    cin >> giokham;
    cin.ignore();
    getline(cin, trangthai);
}
void Lichkham::hienthithongtinlichkham()
{
    cout << "Ngay kham: " << ngaykham << endl;
    cout << "Gio kham: " << giokham << endl;
    cout << "trang thai: " << trangthai << endl;
}
void Phongkham::nhap()
{
    getline(cin, tenPhong);
    getline(cin, tenKhoa);
}
void Phongkham::hienthithongtinphongkham()
{
    cout << "Ten phong: " << tenPhong << endl;
    cout << "ten khoa: " << tenKhoa << endl;
}
