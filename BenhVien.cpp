#include "BenhVien.h"
Quanly::Quanly()
{
    next_id = 01;
    load();
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
        Patient p = Patient::write(line);
        ds.push_back();

        int idsum = stoi(p.getID());
        if (idsum >= next_id)
            next_id = idsum + 1;
    }
}