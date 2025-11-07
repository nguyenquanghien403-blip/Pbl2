#pragma once
#include <bits/stdc++.h>
#include "BenhNhan.h"
#include "BacSi.h"
using namespace std;

class TrangThai_
{
private:
    string idtt;
    string tentt;
    string Khoa;
    Doctor BacSi;
    Patient dsBN[50];
    int slgbn;

public:
    TrangThai_();
    TrangThai_(string, string);

    void nhap();
    void themBN();
    void hienthithongtin();
    string chuanhoa(string);
    void read(const string &, const Doctor dsBS[], int);

    string getidtt() const;
    string gettentt() const;
    friend ostream &operator<<(ostream &, const TrangThai_ &);
    friend istream &operator>>(istream &, TrangThai_ &);
    void setidtt(string);
    void settentt(string);
};