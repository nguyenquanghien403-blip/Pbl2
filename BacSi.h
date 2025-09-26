#include <bits/stdc++.h>
using namespace std;
class Doctor
{
private:
  string id_BS;
  string tenBS;
  string chuyenkhoa;
  string sdt;
  string PLV;

public:
  void nhap();
  bool Ktrasdt(const string &);
  void hienthithongtinbs();
};