#include <bits/stdc++.h>
#include "BacSi.h"
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