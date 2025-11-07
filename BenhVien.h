#include <bits/stdc++.h>
#include "BenhNhan.h"
#include "BacSi.h"
using namespace std;
#pragma once
class Quanly
{
private:
    Patient *ds;
    Doctor *dsbs;
    int succhua;
    int succhuabs;
    int soluong;
    int soluongbs;
    int next_idbn;
    int next_idbs;

public:
    Quanly(int cp = 10, int cpbs = 10);
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
};