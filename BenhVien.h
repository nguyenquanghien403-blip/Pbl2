#include <bits/stdc++.h>
#include "BenhNhan.h"
#include "BacSi.h"
using namespace std;
#pragma once
class Quanly
{
private:
    Patient *ds;
    int succhua;
    int soluong;
    int next_idbn;
    int next_idbs;

public:
    Quanly(int cp = 10);
    ~Quanly();
    void them(Patient &);
    void load();
    void xuat();
    void save();

    /// void themBN();
    void hienthi();
    void xoa(const string &);
    void cleanfile(const string &);
};