#include "BenhVien.h"
#include "LichKham.h"
#include "PhongKham.h"
#include "ThongKe.h"
#include <iostream>
#include <limits> // Cần cho numeric_limits
using namespace std;

// --- Khai báo nguyên mẫu hàm (FUNCTION PROTOTYPES) ---
void clear_input_buffer();
void menubn(Quanly &ql);
void menubs(Quanly &ql); // Đã thêm &ql
void menulk(Quanly &ql); // Đã thêm &ql
void menupk();
void menutk();

// Hàm hỗ trợ xóa bộ đệm nhập liệu sau khi dùng cin >>
void clear_input_buffer()
{
    if (cin.fail()) /// khi nhap sai kieu du lieu
    {
        cin.clear(); // xoa co loi
    }
    // Đảm bảo cin.ignore chỉ được gọi sau khi có cin >> hoặc getline,
    // tránh lỗi nếu bộ đệm đã trống
    if (cin.peek() != EOF)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Định nghĩa hàm menubn giữ nguyên
void menubn(Quanly &ql)
{
    /// Quanly ql(10);
    int luachon;
    int lc1;
    do
    {
        cout << "\n ----- MENU CHUC NANG BENH NHAN ------\n";
        cout << "1.Them benh nhan moi\n";
        cout << "2.Xuat ds benh nhan\n";
        cout << "3.Luu ds benh nhan\n";
        cout << "4.Xoa benh nhan\n";
        cout << "5.Don dep rac(clean file)\n";
        cout << "6.Sua thong tin benh nhan\n";
        cout << "0.Quay lai\n";
        cout << "---------------------------------------\n";
        cout << "Nhap lua chon: ";
        if (!(cin >> luachon))
        {
            clear_input_buffer();
            luachon = -1; // Đặt giá trị không hợp lệ
            continue;
        }
        clear_input_buffer();

        switch (luachon)
        {
        case 1:
            ql.them();
            break;
        case 2:
            ql.xuat();
            break;
        case 3:
            ql.save();
            break;
        case 4:
        {
            cout << "Nhap ma benh nhan can xoa: ";
            string id;
            getline(cin, id);
            ql.xoa(id);
            break;
        }
        case 5:
            ql.cleanfile("BenhNhan.txt");
            break;
        case 6:
        {
            cout << "Nhap ma benh nhan can sua: ";
            string id;
            getline(cin, id);
            ql.sua(id);
            break;
        }
        case 0:
            cout << "Quay lai!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long nhap lai...\n";
            break;
        }
    } while (luachon != 0);
}

// Định nghĩa hàm menubs (ĐÃ CẬP NHẬT)
void menubs(Quanly &ql)
{
    int luachon;
    do
    {
        cout << "\n ----- MENU CHUC NANG BAC SI ------\n";
        cout << "1.Them bac si moi\n";
        cout << "2.Xuat danh sach bac si\n";
        cout << "3.Luu danh sach bac si\n";
        cout << "4.Xoa bac si\n";
        cout << "5.Don dep rac(clean file)\n";
        cout << "6.Kiem tra trung ten bac si\n"; // <--- Chức năng mới
        cout << "0.Quay lai\n";
        cout << "------------------------------------\n";
        cout << "Nhap lua chon: ";
        if (!(cin >> luachon))
        {
            clear_input_buffer();
            luachon = -1;
            continue;
        }
        clear_input_buffer();

        switch (luachon)
        {
        case 1:
        {
            Doctor bs;
            bs.nhapbs(); // Giả định nhapbs() nhập tên và các thông tin khác

            // **[THỰC HIỆN CHỨC NĂNG TRÙNG TÊN]**
            if (ql.ktratrungtenbs(bs.getTenBS()))
            {
                cout << "=> LOI: Ten bac si da ton tai trong he thong! Vui long nhap lai.\n";
            }
            else
            {
                ql.thembs(bs);
            }
            break;
        }
        case 2:
            ql.xuatbs();
            break;
        case 3:
            ql.savebs();
            break;
        case 4:
        {
            cout << "Nhap ma bac si can xoa: ";
            string id;
            getline(cin, id);
            ql.xoabs(id);
            break;
        }
        case 5:
            ql.cleanfilebs("BacSi.txt");
            break;
        case 6: // <--- [CHỨC NĂNG MỚI] KIỂM TRA TRÙNG TÊN BÁC SĨ
        {
            cout << "Nhap ten bac si muon kiem tra trung: ";
            string ten;
            getline(cin, ten);
            if (ql.ktratrungtenbs(ten))
            {
                cout << "=> KET QUA: Ten bac si '" << ten << "' da ton tai trong he thong!\n";
            }
            else
            {
                cout << "=> KET QUA: Ten bac si '" << ten << "' chua ton tai trong he thong.\n";
            }
            break;
        }
        case 0:
            cout << "Quay lai!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long nhap lai...\n";
            break;
        }
    } while (luachon != 0);
}

// Định nghĩa hàm menulk (ĐÃ CẬP NHẬT)
// void menulk(Quanly &ql)
// {
//     int luachon;
//     do
//     {
//         cout << "\n ----- MENU CHUC NANG LICH KHAM ------\n";
//         cout << "1.Them lich kham moi\n";
//         cout << "2.Xuat danh sach lich kham\n";
//         cout << "3.Luu danh sach lich kham (Xuat ra LichKham.txt)\n"; // <--- Chức năng mục tiêu
//         cout << "4.Tai danh sach lich kham\n";
//         cout << "0.Quay lai\n";
//         cout << "-------------------------------------\n";
//         cout << "Nhap lua chon: ";
//         if (!(cin >> luachon))
//         {
//             clear_input_buffer();
//             luachon = -1;
//             continue;
//         }
//         clear_input_buffer();

//         switch (luachon)
//         {
//         case 1:
//             ql.themlichkham();
//             break;
//         case 2:
//             ql.xuatlichkham();
//             break;
//         case 3:
//             ql.saveLK(); // **<--- GỌI HÀM LƯU RA FILE LICHKHAM.TXT**
//             cout << "=> Da luu danh sach lich kham vao file LichKham.txt.\n";
//             break;
//         case 4:
//             ql.loadLK();
//             cout << "=> Da tai danh sach lich kham.\n";
//             break;
//         case 0:
//             cout << "Quay lai!\n";
//             break;
//         default:
//             cout << "Lua chon khong hop le! Vui long nhap lai...\n";
//             break;
//         }
//     } while (luachon != 0);
// }
void menulk(Quanly &ql)
{
    int luachon;
    do
    {
        cout << "\n ----- MENU CHUC NANG LICH KHAM ------\n";
        cout << "1. Them lich kham moi (su dung ID)\n";
        cout << "2. Them lich kham (su dung nhap)\n";
        cout << "3. Xuat danh sach lich kham (thong tin day du)\n";
        cout << "4. Xuat danh sach lich kham (thong tin co ban)\n";
        cout << "5. Cap nhat trang thai lich kham\n";
        cout << "6. Thong ke chi tiet he thong\n";
        cout << "7. Luu danh sach lich kham\n";
        cout << "8. Tai danh sach lich kham\n";
        cout << "9. Tim kiem thong tin bac si/benh nhan theo ID\n";
        cout << "0. Quay lai\n";
        cout << "-------------------------------------\n";
        cout << "Nhap lua chon: ";
        if (!(cin >> luachon))
        {
            clear_input_buffer();
            luachon = -1;
            continue;
        }
        clear_input_buffer();

        switch (luachon)
        {
        case 1:
            ql.themLichKhamVoiID(); // Sử dụng hàm mới
            break;
        case 2:
            ql.themlichkham(); // Sử dụng hàm cũ
            break;
        case 3:
            ql.xuatLichKhamDayDu(); // Hiển thị đầy đủ thông tin
            break;
        case 4:
            ql.xuatlichkham(); // Hiển thị cơ bản
            break;
        case 5:
            ql.capNhatTrangThaiLichKham();
            break;
        case 6: //  GỌI HÀM THỐNG KÊ CHI TIẾT
            ql.thongKeChiTiet();
            break;
        case 7:
            ql.saveLK();
            cout << " Da luu danh sach lich kham!\n";
            break;
        case 8:
            ql.loadLK();
            cout << " Da tai danh sach lich kham!\n";
            break;
        case 9:
        {
            int choice;
            cout << "1. Tim bac si\t2. Tim benh nhan: ";
            cin >> choice;
            clear_input_buffer();
            if (choice == 1)
            {
                string id;
                cout << "Nhap ID bac si: ";
                getline(cin, id);
                ql.hienThiThongTinBS(id);
            }
            else if (choice == 2)
            {
                string id;
                cout << "Nhap ID benh nhan: ";
                getline(cin, id);
                ql.hienThiThongTinBN(id);
            }
        }
        break;
        case 0:
            cout << "Quay lai!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long nhap lai...\n";
            break;
        }
    } while (luachon != 0);
}
// void menulk(Quanly &ql)
// {
//     int luachon;
//     do
//     {
//         cout << "\n ----- MENU CHUC NANG LICH KHAM ------\n";
//         cout << "1. Them lich kham moi (su dung ID)\n";
//         cout << "2. Xuat danh sach lich kham (thong tin day du)\n";
//         cout << "3. Xuat danh sach lich kham (thong tin co ban)\n";
//         cout << "4. Cap nhat trang thai lich kham\n";
//         cout << "5. Xoa lich kham\n";
//         cout << "6. Luu danh sach lich kham\n";
//         cout << "7. Tai danh sach lich kham\n";
//         cout << "8. Tim kiem thong tin bac si/benh nhan theo ID\n";
//         cout << "0. Quay lai\n";
//         cout << "-------------------------------------\n";
//         cout << "Nhap lua chon: ";
//         if (!(cin >> luachon))
//         {
//             clear_input_buffer();
//             luachon = -1;
//             continue;
//         }
//         clear_input_buffer();

//         switch (luachon)
//         {
//         case 1:
//             ql.themLichKhamVoiID();
//             break;
//         case 2:
//             ql.xuatLichKhamDayDu();
//             break;
//         case 3:
//             ql.xuatlichkham();
//             break;
//         case 4:
//             // Code cập nhật trạng thái
//             break;
//         case 5:
//             // Code xóa lịch khám
//             break;
//         case 6:
//             ql.saveLK();
//             cout << " Da luu danh sach lich kham!\n";
//             break;
//         case 7:
//             ql.loadLK();
//             cout << " Da tai danh sach lich kham!\n";
//             break;
//         case 8:
//         {
//             int choice;
//             cout << "1. Tim bac si\t2. Tim benh nhan: ";
//             cin >> choice;
//             clear_input_buffer();
//             if (choice == 1)
//             {
//                 string id;
//                 cout << "Nhap ID bac si: ";
//                 getline(cin, id);
//                 ql.hienThiThongTinBS(id);
//             }
//             else if (choice == 2)
//             {
//                 string id;
//                 cout << "Nhap ID benh nhan: ";
//                 getline(cin, id);
//                 ql.hienThiThongTinBN(id);
//             }
//         }
//         break;
//         case 0:
//             cout << "Quay lai!\n";
//             break;
//         default:
//             cout << "Lua chon khong hop le! Vui long nhap lai...\n";
//             break;
//         }
//     } while (luachon != 0);
// }
// Định nghĩa hàm menupk (giữ nguyên, nếu bạn có định nghĩa)
void menupk()
{
    TrangThai_ dspk[50];
    int n = 0;
    int chon;
    do
    {
        cout << "\n ------MENU PK -------\n";
        cout << "1.Nhap pk new \n";
        cout << "2.Xuat ds pk\n";
        cout << "3.Luu pk vao file\n";
        cout << "4.Doc ds pk tu file\n";
        cout << "0.Quay lai\n";
        cout << "----------------\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            if (n < 50)
            {
                cout << "\nNhap thong tin pk thu " << n + 1 << ":\n";
                dspk[n++].nhap();
            }
            else
            {
                cout << "DS da day";
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                dspk[i].hienthithongtin();
            }
            break;
        case 3:
        {
            ofstream f("PhongKham.txt", ios::app);
            for (int i = 0; i < n; i++)
            {
                f << dspk[i].getidtt() << "|" << dspk[i].gettentt() << "\n";
            }
            f.close();
            cout << "Da luu vao file\n";
            break;
        }
        case 4:
        {
            /*ifstream f("PhongKham.txt");
            string l;
            n = 0;
            while (getline(f, l) && n < 50)
            {
                stringstream ss(l);
                string id, ten;
                getline(ss, id, '|');
                getline(ss, ten, '|');
                dspk[n].setidtt(id);
                dspk[n].settentt(ten);
                n++;
            }
            f.close();
            cout << "Da doc ds pk tu file\n";
            break;*/
            // --- Đọc danh sách bác sĩ ---
            // Đọc danh sách bác sĩ trước
            ifstream fbs("Doctor.txt");
            string linebs;
            Doctor dsBS[50];
            int soBS = 0;
            while (getline(fbs, linebs))
            {
                if (!linebs.empty())
                    dsBS[soBS++] = Doctor::read(linebs);
            }
            fbs.close();

            // Đọc danh sách phòng khám
            ifstream f("PhongKham.txt");
            string line;
            n = 0;
            while (getline(f, line) && n < 50)
            {
                if (!line.empty())
                    dspk[n++].read(line, dsBS, soBS); // dùng hàm read vừa tạo
            }
            f.close();

            cout << "Da doc ds phong kham va gan bac si phu trach\n";
            break;
        }
        case 0:
            cout << "Quay lai\n";
            break;
        default:
            cout << "Lua chon 0 hop le!\n";
        }
    } while (chon != 0);
}
void menuThongKe()
{
    ThongKe thongke;
    int choice;
    string input;

    do
    {
        cout << "\n--- MENU THONG KE / BAO CAO ---" << endl;
        cout << "1. Thong ke luot kham trong ngay" << endl;
        cout << "2. Thong ke so benh nhan trong thang" << endl;
        cout << "3. Tong doanh thu thang" << endl;
        cout << "4. Thong ke luot kham theo Bac si" << endl;
        cout << "5. Thong ke trang thai lich kham" << endl; // Mới
        cout << "6. Thong ke doanh thu theo bac si" << endl;
        cout << "0. Quay lai Menu chinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        clear_input_buffer();

        switch (choice)
        {
        case 1:
            cout << "Nhap ngay can thong ke (dd/mm/yyyy): ";
            getline(cin, input);
            thongke.Thongkeluotkhamtrongngay(input);
            break;
        case 2:
            cout << "Nhap thang can thong ke (VD: 12): ";
            getline(cin, input);
            thongke.Thongkesobenhnhantrongthang(input);
            break;
        case 3:
            cout << "Nhap thang can tinh doanh thu (VD: 12): ";
            getline(cin, input);
            thongke.Tongdoanhthuthang(input);
            break;
        case 4:
            cout << "Nhap Ma Bac si can thong ke (VD: BS001): ";
            getline(cin, input);
            thongke.Thongkebacsikham(input);
            break;
        case 5:
            thongke.ThongkeTrangThai();
            break;
        case 6:
        {
            string maBS;
            cout << "Nhap Ma Bac si can thong ke doanh thu: ";
            getline(cin, maBS);
            thongke.ThongkedoanhthutheoBacSi(maBS);
            break;
        }
        case 0:
            cout << "Quay lai Menu chinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }

        if (choice != 0)
        {
            cout << "\nNhan de tiep tuc";
            cin.get();
        }
    } while (choice != 0);
}
// Định nghĩa hàm menutk (giữ nguyên, nếu bạn có định nghĩa)
// void menuThongKe()
// {
//     ThongKe thongke;
//     int choice;
//     string input;

//     do
//     {
//         cout << "\n--- MENU THONG KE / BAO CAO ---" << endl;
//         cout << "1. Thong ke luot kham trong ngay" << endl;
//         cout << "2. Thong ke so benh nhan trong thang" << endl;
//         // Dựa vào LichKham.txt, các hàm thống kê này có thể không hoạt động chính xác
//         // do định dạng file không khớp với code (ví dụ: dùng '|' thay vì ';')
//         cout << "3. Tong doanh thu thang (Can co truong 'Tien' trong LichKham.txt)" << endl;
//         cout << "4. Thong ke luot kham theo Bac si (theo MaBS)" << endl;
//         cout << "0. Quay lai Menu chinh" << endl;
//         cout << "Nhap lua chon: ";
//         cin >> choice;
//         clear_input_buffer();

//         switch (choice)
//         {
//         case 1:
//             cout << "Nhap ngay can thong ke (DD/MM/YYYY): ";
//             getline(cin, input);
//             thongke.Thongkeluotkhamtrongngay(input);
//             break;
//         case 2:
//             cout << "Nhap thang can thong ke (VD: /10/): "; // Yêu cầu người dùng nhập định dạng tìm kiếm
//             getline(cin, input);
//             thongke.Thongkesobenhnhantrongthang(input);
//             break;
//         case 3:
//             cout << "Nhap thang can tinh tong doanh thu (VD: /10/): ";
//             getline(cin, input);
//             thongke.Tongdoanhthuthang(input);
//             break;
//         case 4:
//             cout << "Nhap Ma Bac si can thong ke (VD: BS01): ";
//             getline(cin, input);
//             thongke.Thongkebacsikham(input);
//             break;
//         case 0:
//             cout << "Quay lai Menu chinh." << endl;
//             break;
//         default:
//             cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
//         }
//     } while (choice != 0);
// }

void MenuLichKham()
{
    LichKham dsLich[100];
    int soLich = 0;
    int choice;

    do
    {
        cout << "\n=== MENU QUAN LY LICH KHAM ===\n";
        cout << "1. Nhap lich kham moi\n";
        cout << "2. Hien thi danh sach lich kham\n";
        cout << "3. Luu danh sach vao file\n";
        cout << "4. Doc danh sach tu file\n";
        cout << "5. Cap nhat trang thai lich kham\n";
        cout << "6. Xoa lich kham\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "===============================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (soLich < 100)
            {
                cout << "\nNhap lich kham thu " << soLich + 1 << ":\n";
                dsLich[soLich].nhap();
                dsLich[soLich].setid(dsLich[soLich].taoMaTuDong(soLich));
                soLich++;
            }
            else
                cout << "Danh sach lich kham da day!\n";
            break;

        case 2:
            for (int i = 0; i < soLich; i++)
            {
                cout << "\n--- Lich kham thu " << i + 1 << " ---";
                dsLich[i].hienthilk();
            }
            break;

        case 3:
            ghifileLichKham(dsLich, soLich, "LichKham.txt");
            cout << "Da luu danh sach vao LichKham.txt\n";
            break;

        case 4:
        {
            ifstream f("LichKham.txt");
            string line;
            soLich = 0;
            while (getline(f, line) && soLich < 100)
            {
                dsLich[soLich++] = LichKham::read(line);
            }
            f.close();
            cout << "Da doc " << soLich << " lich kham tu file.\n";
            break;
        }

        case 5:
        {
            string id;
            cout << "Nhap ma lich kham can cap nhat trang thai: ";
            getline(cin, id);
            bool found = false;
            for (int i = 0; i < soLich; i++)
            {
                if (dsLich[i].getidlk() == id)
                {
                    dsLich[i].capnhatTrangThai();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Khong tim thay ma lich kham!\n";
            break;
        }

        case 6:
        {
            string ma;
            cout << "Nhap ma lich kham can xoa: ";
            getline(cin, ma);
            xoalich(dsLich, soLich, ma);
            break;
        }

        case 0:
            cout << "Quay lai menu chinh...\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

// Hàm main (ĐÃ SỬA LỖI GỌI HÀM)
int main()
{
    Quanly ql(10); // quản lý bệnh nhân (và các đối tượng khác)
    int luachon;

    do
    {
        cout << "\n======= MENU MAIN =======\n";
        cout << "1. Quan ly benh nhan\n";
        cout << "2. Quan ly bac si\n";
        //  cout << "3. Quan ly phong kham\n";
        cout << "3. Quan ly lich kham\n";
        cout << "4. Thong ke\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "==========================\n";
        cout << "Nhap lua chon: ";
        if (!(cin >> luachon))
        {
            clear_input_buffer();
            luachon = -1;
            continue;
        }
        clear_input_buffer();

        switch (luachon)
        {
        case 1:
            menubn(ql);
            break;
        case 2:
            menubs(ql);
            break;
        // case 3:
        //     // menupk();
        //     break;
        case 3:
            menulk(ql);
            break;
        case 4:
            menuThongKe();
            break;
        case 0:
            cout << "Thoat chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long nhap lai...\n";
        }
    } while (luachon != 0);

    return 0;
}