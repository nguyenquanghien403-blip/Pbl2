#include <iostream>
#include <string.h>
using namespace std;
class Patient
{
private:
    string id_bn;
    string tenBN;
    string gioitinh;
    string sdtbn;
    string cccd;
    int ngay, thang, nam;
    string diachi_to, diachi_phuong, diachi_tp, diachi_qg;

public:
    void nhap();
    void hienthithongtinbn();
    bool Ktrasdt(const string &);
    bool Ktracccd(const string &);
    bool Ktrangaythangnamsinh(int, int, int);
};
class Doctor
{
private:
    string tenBS;
    string chuyenkhoa;
    int sdtbs;
    string phongLV;

public:
    void nhap();
    void hienthithongtinbs();
};
class Lichkham
{
private:
    int ngaykham;
    int giokham;
    string trangthai;

public:
    void nhap();
    void hienthithongtinlichkham();
};
class Phongkham
{
private:
    string tenPhong;
    string tenKhoa;

public:
    void nhap();
    void hienthithongtinphongkham();
};
class Benhan
{
};
class User
{
private:
    int maND;
    string ten;
    string gioitinh;
    int ngaysinh, thangsinh, namsinh;
    string diachi;

public:
    void nhap();
    void hienthithongtinUser();
};
class Hoadon
{
private:
    int tongtien;
    string noidung;
};