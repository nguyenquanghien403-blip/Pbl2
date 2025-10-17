#include <bits/stdc++.h>
using namespace std;
#pragma once
class Doctor
{
private:
  string id_BS; /// 011
  string tenBS;
  int chuyenkhoa;
  string sdt;
  string PLV;
  static int next_ID;

public:
  Doctor()
  {
    next_ID++;
    ostringstream s;
    cout << setw(3) << " " << setfill('0') << next_ID;
    id_BS = s.str();
  };
  string getID() const { return id_BS; }
  void nhap();
  bool Ktrasdt(const string &);
  void hienthithongtinbs();
  string write();
  static Doctor read(const string &);
};