#include <iostream>
#include <string.h>
using namespace std;
#pragma once
class Patient
{
private:
    string id_bn;
    string tenBN;
    int gioitinh;
    string sdtbn;
    string cccd;
    int ngay, thang, nam;
    string diachi_to, diachi_phuong, diachi_tp, diachi_qg;

public:
    void them();
    void nhap();
    void hienthithongtinbn() const;
    bool Ktrasdt(const string &);
    bool Ktracccd(const string &);
    bool Ktrangaythangnamsinh(int, int, int);
    void write(const string &) const;
    static Patient read(const string &);
    string getName() const;
    void setID(const string &);
    string getID() const;
    string chuoi() const;
    void xuatdstufile(const string &);
};
