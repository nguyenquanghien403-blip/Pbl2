#include <bits/stdc++.h>
#include "BenhNhan.h"
#include "BacSi.h"
#include "LichKham.h"
using namespace std;
#pragma once
class Quanly
{
private:
    Patient *ds;
    Doctor *dsbs;
    LichKham *dsLK;
    int succhua;
    int succhuaLK;
    int succhuabs;
    int soluong;
    int soluongLK;
    int soluongbs;
    int next_idbn;
    int next_idbs;
    int next_idLK;

public:
    Quanly(int cp = 10, int cpbs = 10, int cplk = 10);
    ~Quanly();
    void them(Patient &);
    void them();
    void load();
    void xuat();
    void save();

    /// void themBN();
    void hienthi();
    void sua(const string &);
    void xoa(const string &);
    void cleanfile(const string &);
    /// Bac Si
    void thembs(Doctor &);
    void xuatbs();
    void savebs();
    void loadbs();
    void xoabs(const string &);
    void cleanfilebs(const string &);
    string trim(const string &) const;
    string tolower1(string) const;

    // bool kiemTraTrungLich(const string &idBS, const string &ngay, const string &gio) const;
    bool ktratrungten(const string &ten) const;
    bool ktratrungcccd(const string &cccd) const;
    bool ktratrungsdt(const string &sdt) const;
    bool ktratrungtenbs(const string &ten) const;

    void themlichkham();
    void xuatlichkham();
    void saveLK();
    void loadLK();
    bool kiemTraTrungLich(const string &idBS, const string &ngay, const string &gio) const;
    Doctor *timBacSiTheoID(const string &id);
    Patient *timBenhNhanTheoID(const string &id);
    void hienThiThongTinBS(const string &id);
    void hienThiThongTinBN(const string &id);
    void themLichKhamVoiID(); // Hàm mới để thêm lịch khám với ID
    void xuatLichKhamDayDu(); // Hàm hiển thị lịch khám đầy đủ thông tin
    void thongKeChiTiet();
    void capNhatTrangThaiLichKham();
};