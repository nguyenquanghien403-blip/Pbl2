#pragma once
#include <bits/stdc++.h>
#include "BenhVien.h"
#include "BenhNhan.h"
#include "BacSi.h"
// #include "PhongKham.h"
#include "TrangThai.h"
using namespace std;
class LichKham
{
public:
    string MaLich;
    string id_bn;
    string id_bs;
    int MaPhongKham;
    string Phongkham;
    string NgayKham;
    string GioKham;
    string note;
    static int next_id;
    Patient BenhNhan;
    Doctor BacSi;
    TrangThai Trangthai;

public:
    LichKham();
    // LichKham(int, int, int, int, const string &, const string &);
    void nhap();
    void hienthilk() const;
    /*int layMalich() const;
    int layMaBN() const;
    int layMaPhong() const;
    string layNgayKham() const;
    string LayGioKham() const;

    string ghiDong() const;
    static LichKham docDong(const string &);*/
    string write() const;
    static LichKham read(const string &); /// doc tu file

    string getidlk() const;
    string getday() const;
    string gettime() const;

    void setid(const string &);
    void setday(const string &);
    void settime(const string &);

    Patient &getBN();
    Doctor &getDT();

    void setBN(const Patient &);
    void setDT(const Doctor &);
    void hienthithongtinlk();

    bool ktratrunglich(const LichKham *, int) const; // kiểm tra trùng
    void capnhatTrangThai();                         // cập nhật trạng thái
    static void timkiemLichKham(LichKham *, int, const string &);
    static void sapxepLichTheoNgay(LichKham *, int);
    // void xoalich(LichKham *, int &, const string &);
    static void thongkeLich(LichKham *, int);
    // void ghifileLichKham(LichKham *, int, const string &);
    static string taoMaTuDong(int stt); // sinh mã tự động
};
void xoalich(LichKham *, int &, const string &);
void ghifileLichKham(LichKham *, int, const string &);