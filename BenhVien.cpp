#include "BenhVien.h"
/*Quanly::Quanly()
{
    next_id = 01;
    load();
}*/
Quanly::Quanly(int cp)
{

    succhua = cp;
    soluong = 0;
    next_idbn = 1;

    ds = new Patient[succhua];
    cleanfile("BenhNhan.txt");
    load();
}
Quanly::~Quanly()
{
    delete[] ds;
}
void Quanly::them(Patient &p) // hàm thêm quản lý nhân viên, bác sĩ
{
    if (soluong == succhua)
    {
        int newcp = succhua * 2;
        Patient *newds = new Patient[newcp];
        for (int i = 0; i < soluong; i++)
        {
            newds[i] = ds[i];
        }
        delete[] ds;
        ds = newds;
        succhua = newcp;
    }
    stringstream ss;
    ss << setw(3) << setfill('0') << next_idbn++; // 001
    p.setID(ss.str());
    // p.setID(to_string(next_idbn++));
    ds[soluong++] = p;
}
void Quanly::load()
{
    ifstream fin("BenhNhan.txt");
    if (!fin.is_open())
        return;

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        Patient p = Patient::read(line);
        /// ds.push_back();
        them(p);
        string id_str = p.getID();
        if (!id_str.empty() && all_of(id_str.begin(), id_str.end(), ::isdigit)) /// neu id trong hoac rong se bo qua
        {
            int idsum = stoi(id_str);
            if (idsum >= next_idbn)
                next_idbn = idsum + 1;
        }
    }
    fin.close();
}
void Quanly ::xuat()
{
    for (int i = 0; i < soluong; i++)
    {
        ds[i].hienthithongtinbn();
    }
}
void Quanly::cleanfile(const string &fname)
{
    ifstream fin(fname);
    if (!fin.is_open())
    {
        cerr << "0 mo duoc file" << fname << "de ghi\n";
        return;
    }
    int dem = 0;
    string line;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        int ppdem = count_if(line.begin(), line.end(), [](char c)
                             { return c == '|'; });
        if (ppdem >= 5) // vai truong toi thieu
        {
            dem++;
        }
    }
    fin.clear();
    fin.seekg(0);
    // cap phat mang dong
    string *vlline = new string[dem];
    int idx = 0;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }
        int ppdem = count_if(line.begin(), line.end(), [](char c)
                             { return c == '|'; });
        if (ppdem >= 5)
        {
            vlline[idx++] = line;
        }
    }
    fin.close();
    ofstream fout(fname, ios::trunc);
    if (!fout.is_open())
    {
        cerr << "0 mo duoc file de ghi " << endl;
        delete[] vlline;
        return;
    }
    for (int i = 0; i < idx; i++)
    {
        fout << vlline[i] << '\n';
    }
    fout.close();
    delete[] vlline;
    cout << "Da don file " << fname << ", giu lai " << idx << "dong hop le";
}
void Quanly::save()
{
    ofstream fout("BenhNhan.txt");
    if (!fout.is_open())
    {
        cerr << "0 mo duoc file\n";
        return;
    }
    for (int i = 0; i < soluong; i++)
    {
        ds[i].write("BenhNhan.txt");
    }
    fout.close();
    cleanfile("BenhNhan.txt");
}
void Quanly::xoa(const string &id)
{
    int idx = -1;
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getID() == id)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "0 tim thay benh nhan co ID la: " << id << endl;
        return;
    }
    cout << "da xoa benh nhan co ID la: " << ds[idx].getID() << "- Ten: " << ds[idx].getName() << endl;
    for (int i = idx; i < soluong - 1; i++)
    {
        ds[i] = ds[i + 1];
    }
    soluong--;
    ofstream fout("BenhNhan.txt");
    for (int i = 0; i < soluong; i++)
    {
        fout << ds[i].chuoi() << endl;
    }
    fout.close();
}