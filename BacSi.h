#include <bits/stdc++.h>
using namespace std;
class Doctor
{
private:
  string id_BS; /// 011
  string tenBS;
  int chuyenkhoa;
  string sdt;
  string PLV;

public:
  Doctor() {};
  Doctor(string id) : id_BS(id) {};
  string getID() { return id_BS; }
  void nhap();
  bool Ktrasdt(const string &);
  void hienthithongtinbs();
  string write();
  void read(const string &);
};