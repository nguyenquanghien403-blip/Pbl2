#include <bits/stdc++.h>
#include "BenhNhan.h"
#include "Doctor.h"
using namespace std;
class Quanly
{
private:
    vector<Doctor> ds;
    int next_id;

public:
    Quanly();
    void load();
    void save();

    void themBN();
    void hienthi();
    void xoaBN();
};