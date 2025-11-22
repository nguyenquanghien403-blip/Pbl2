#include <bits/stdc++.h>
#include "ThongKe.h"

ThongKe::ThongKe() {}

void ThongKe::Thongkeluotkhamtrongngay(const string &ngay)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Khong the mo file LichKham.txt\n";
        return;
    }

    string dong;
    int dem = 0;

    while (getline(file, dong))
    {
        if (dong.empty())
            continue;

        stringstream ss(dong);
        string MaLich, idBN, idBS, Ngaykham, Giokham, Trangthai;

        // Đọc theo định dạng: MaLich|idBN|idBS|Ngaykham|Giokham|Trangthai
        getline(ss, MaLich, '|');
        getline(ss, idBN, '|');
        getline(ss, idBS, '|');
        getline(ss, Ngaykham, '|');
        getline(ss, Giokham, '|');
        getline(ss, Trangthai, '|');

        if (Ngaykham == ngay)
            dem++;
    }

    cout << "So luot kham trong ngay " << ngay << " la: " << dem << endl;
    file.close();
}

void ThongKe::Thongkesobenhnhantrongthang(const string &thang)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Khong the mo file LichKham.txt\n";
        return;
    }

    string dong;
    int dem = 0;

    while (getline(file, dong))
    {
        if (dong.empty())
            continue;

        stringstream ss(dong);
        string MaLich, idBN, idBS, Ngaykham, Giokham, Trangthai;

        getline(ss, MaLich, '|');
        getline(ss, idBN, '|');
        getline(ss, idBS, '|');
        getline(ss, Ngaykham, '|');
        getline(ss, Giokham, '|');
        getline(ss, Trangthai, '|');

        // Tìm tháng trong chuỗi ngày (định dạng dd/mm/yyyy)
        if (Ngaykham.find("/" + thang + "/") != string::npos)
            dem++;
    }

    cout << " So benh nhan trong thang " << thang << " la: " << dem << endl;
    file.close();
}

void ThongKe::Tongdoanhthuthang(const string &thang)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Khong the mo file LichKham.txt\n";
        return;
    }

    string dong;
    double Tongtien = 0;
    int count = 0;

    while (getline(file, dong))
    {
        if (dong.empty())
            continue;

        stringstream ss(dong);
        string MaLich, idBN, idBS, Ngaykham, Giokham, Trangthai;

        getline(ss, MaLich, '|');
        getline(ss, idBN, '|');
        getline(ss, idBS, '|');
        getline(ss, Ngaykham, '|');
        getline(ss, Giokham, '|');
        getline(ss, Trangthai, '|');

        // Tính tiền dựa trên trạng thái (giả lập)
        if (Ngaykham.find("/" + thang + "/") != string::npos)
        {
            if (Trangthai == "Hoan thanh")
            {
                Tongtien += 300000; // Giả định 300k/lượt khám hoàn thành
                count++;
            }
        }
    }

    cout << " Tong doanh thu thang " << thang << " la: "
         << fixed << setprecision(0) << Tongtien << " VND ("
         << count << " luot kham hoan thanh)" << endl;
    file.close();
}

void ThongKe::Thongkebacsikham(const string &maBaSi)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << " Khong the mo file LichKham.txt\n";
        return;
    }

    string dong;
    int dem = 0;

    while (getline(file, dong))
    {
        if (dong.empty())
            continue;

        stringstream ss(dong);
        string MaLich, idBN, idBS, Ngaykham, Giokham, Trangthai;

        getline(ss, MaLich, '|');
        getline(ss, idBN, '|');
        getline(ss, idBS, '|');
        getline(ss, Ngaykham, '|');
        getline(ss, Giokham, '|');
        getline(ss, Trangthai, '|');

        if (idBS == maBaSi)
            dem++;
    }

    cout << " Bac si " << maBaSi << " da kham " << dem << " luot" << endl;
    file.close();
}

// Hàm thống kê mới - Thống kê theo trạng thái
void ThongKe::ThongkeTrangThai()
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "Khong the mo file LichKham.txt\n";
        return;
    }

    string dong;
    int hoanthanh = 0, dangcho = 0, dahuy = 0;

    while (getline(file, dong))
    {
        if (dong.empty())
            continue;

        stringstream ss(dong);
        string MaLich, idBN, idBS, Ngaykham, Giokham, Trangthai;

        getline(ss, MaLich, '|');
        getline(ss, idBN, '|');
        getline(ss, idBS, '|');
        getline(ss, Ngaykham, '|');
        getline(ss, Giokham, '|');
        getline(ss, Trangthai, '|');

        if (Trangthai == "Hoan thanh")
            hoanthanh++;
        else if (Trangthai == "Dang cho")
            dangcho++;
        else if (Trangthai == "Da huy")
            dahuy++;
    }

    cout << "\n THONG KE TRANG THAI LICH KHAM:\n";
    cout << " Hoan thanh: " << hoanthanh << endl;
    cout << " Dang cho: " << dangcho << endl;
    cout << " Da huy: " << dahuy << endl;
    cout << " Tong so: " << (hoanthanh + dangcho + dahuy) << endl;

    file.close();
}
void ThongKe::ThongkedoanhthutheoBacSi(const string &maBaSi)
{
    ifstream file("LichKham.txt");
    if (!file.is_open())
    {
        cout << "0 the mo file LichKham.txt\n";
        return;
    }

    string dong;
    double Tongtien = 0;
    int dem = 0;

    while (getline(file, dong))
    {
        if (dong.empty())
            continue;

        stringstream ss(dong);
        string MaLich, idBN, idBS, Ngaykham, Giokham, Trangthai, strTien;

        getline(ss, MaLich, '|');
        getline(ss, idBN, '|');
        getline(ss, idBS, '|');
        getline(ss, Ngaykham, '|');
        getline(ss, Giokham, '|');
        getline(ss, Trangthai, '|');
        getline(ss, strTien, '|');

        if (idBS == maBaSi && Trangthai == "Hoan thanh")
        {
            try
            {
                double tien = stod(strTien);
                Tongtien += tien;
                dem++;
            }
            catch (...)
            {
                // Bỏ qua nếu có lỗi
            }
        }
    }

    cout << "Doctor" << maBaSi << ":\n";
    cout << "Tong doanh thu: " << fixed << setprecision(0) << Tongtien << " VND\n";
    cout << "So luot kham hoan thanh: " << dem << endl;

    file.close();
}