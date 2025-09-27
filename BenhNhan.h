#include <iostream>
#include <string.h>
using namespace std;
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
    void nhap();
    void hienthithongtinbn();
    bool Ktrasdt(const string &);
    bool Ktracccd(const string &);
    bool Ktrangaythangnamsinh(int, int, int);
    string write();
    static Patient read(const string &);
};
