#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <sstream>
#include "LichKham.h"
using namespace std;
class ThongKe
{
public:
    ThongKe();
    void Thongkeluotkhamtrongngay(const string &ngay);
    void Thongkesobenhnhantrongthang(const string &thang);
    void Tongdoanhthuthang(const string &thang);
    void Thongkebacsikham(const string &maBaSi);
    void ThongkeTrangThai(); // Thêm hàm mới
    void ThongkedoanhthutheoBacSi(const string &);
};
