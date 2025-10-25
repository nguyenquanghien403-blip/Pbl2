#include <bits/stdc++.h>
#include "ThongKe.h"

ThongKe::ThongKe()
{
}
void ThongKe::Thongkeluotkhamtrongngay(const string &ngay)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "0 the mo file LichKham.txt\n";
        return;
    }

    string dong;
    int dem = 0;

    while (getline(file, dong))

    {
        stringstream ss(dong);
        string Ma, Ngaykham, Benhnhan, Bacsi, Phong, Trangthai, Tien;

        getline(ss, Ma, ';');
        getline(ss, Ngaykham, ';');
        getline(ss, Benhnhan, ';');
        getline(ss, Bacsi, ';');
        getline(ss, Phong, ';');
        getline(ss, Trangthai, ';');
        getline(ss, Tien, ';');
        if (Ngaykham == ngay)
            dem++;
    }
    cout << "So luot kham trong ngay la " << ngay << "la: " << dem << endl;
    file.close();
}
void ThongKe::Thongkesobenhnhantrongthang(const string &thang)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Không thể mở file LichKham.txt\n";
        return;
    }
    string dong;
    int dem = 0;
    while (getline(file, dong))
    {
        stringstream ss(dong);
        string Ma, Ngaykham, Benhnhan, Bacsi, Phong, Trangthai, Tien;

        getline(ss, Ma, ';');
        getline(ss, Ngaykham, ';');
        getline(ss, Benhnhan, ';');
        getline(ss, Bacsi, ';');
        getline(ss, Phong, ';');
        getline(ss, Trangthai, ';');
        getline(ss, Tien, ';');
        if (Ngaykham.find(thang) != string::npos)
            dem++;
    }
    cout << " So benh nhan trong thang " << thang << " la: " << dem << endl;
    file.close();
}

void ThongKe::Tinhhoadontungngay(const string &ngay)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Không thể mở file LichKham.txt\n";
        return;
    }
    string dong;
    double Tongtien = 0;
    while (getline(file, dong))
    {
        stringstream ss(dong);
        string Ma, Ngaykham, Benhnhan, Bacsi, Phong, Trangthai, Tien;

        getline(ss, Ma, ';');
        getline(ss, Ngaykham, ';');
        getline(ss, Benhnhan, ';');
        getline(ss, Bacsi, ';');
        getline(ss, Phong, ';');
        getline(ss, Trangthai, ';');
        getline(ss, Tien, ';');

        if (Ngaykham == ngay && !Tien.empty())
            Tongtien += stod(Tien);
    }
    cout << "Tong tien thu trong ngay " << ngay << " la: " << Tongtien << "VND ";
    file.close();
}
void ThongKe::Tongdoanhthuthang(const string &thang)

{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Không thể mở file LichKham.txt\n";
        return;
    }
    string dong;
    double Tongtien = 0;
    while (getline(file, dong))
    {
        stringstream ss(dong);
        string Ma, Ngaykham, Benhnhan, Bacsi, Phong, Trangthai, Tien;

        getline(ss, Ma, ';');
        getline(ss, Ngaykham, ';');
        getline(ss, Benhnhan, ';');
        getline(ss, Bacsi, ';');
        getline(ss, Phong, ';');
        getline(ss, Trangthai, ';');
        getline(ss, Tien, ';');
        if (Ngaykham.find(thang) != string::npos && !Tien.empty())
            Tongtien += stod(Tien);
    }
    cout << " Tong doanh thu thang " << thang << "la: " << Tongtien << " VND ";
    file.close();
}
void ThongKe::Thongkebacsikham(const string &maBaSi)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Không thể mở file LichKham.txt\n";
        return;
    }
    string dong;
    int dem = 0;
    while (getline(file, dong))
    {
        stringstream ss(dong);
        string Ma, Ngaykham, Benhnhan, Bacsi, Phong, Trangthai, Tien;

        getline(ss, Ma, ';');
        getline(ss, Ngaykham, ';');
        getline(ss, Benhnhan, ';');
        getline(ss, Bacsi, ';');
        getline(ss, Phong, ';');
        getline(ss, Trangthai, ';');
        getline(ss, Tien, ';');
        if (Bacsi == maBaSi)
            dem++;
    }
    cout << " Bac si " << maBaSi << " da kham " << dem << " luot ";
    file.close();
}
