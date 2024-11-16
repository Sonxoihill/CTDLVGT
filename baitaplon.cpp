#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CauThu {
private:
    string ten;
    int tuoi;
    int soBanThang;
    int soPhutThiDau;

public:
    CauThu() {}

    CauThu(string ten, int tuoi, int soBanThang, int soPhutThiDau) {
        this->ten = ten;
        this->tuoi = tuoi;
        this->soBanThang = soBanThang;
        this->soPhutThiDau = soPhutThiDau;
    }

    friend istream& operator>>(istream& in, CauThu& ct) {
        cout << "Nhap ten cau thu: ";
        in.ignore();
        getline(in, ct.ten);
        cout << "Nhap tuoi: ";
        in >> ct.tuoi;
        cout << "Nhap so ban thang: ";
        in >> ct.soBanThang;
        cout << "Nhap so phut thi dau: ";
        in >> ct.soPhutThiDau;
        return in;
    }

    friend ostream& operator<<(ostream& out, const CauThu& ct) {
        out << "Ten: " << ct.ten << "\n";
        out << "Tuoi: " << ct.tuoi << "\n";
        out << "So ban thang: " << ct.soBanThang << "\n";
        out << "So phut thi dau: " << ct.soPhutThiDau << "\n";
        return out;
    }

    bool operator<(const CauThu& a) {
        return soBanThang < a.soBanThang;
    }

    int getSoBanThang() {
        return soBanThang;
    }

    string getTen() {
        return ten;
    }
};

class DanhSachCauThu {
private:
    vector<CauThu> ds;

public:
    void nhap() {
        int n;
        cout << "Nhap so luong cau thu: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            CauThu ct;
            cin >> ct;
            ds.push_back(ct);
        }
    }

    void xuat() {
        for (int i = 0; i < ds.size(); i++) {
            cout << ds[i] << "\n";
        }
    }

    void sapXep() {
        sort(ds.begin(), ds.end());
    }

    void timMax() {
        if (ds.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        CauThu maxCauThu = ds[0];
        for (int i = 1; i < ds.size(); ++i) {
            if (ds[i].getSoBanThang() > maxCauThu.getSoBanThang()) {
                maxCauThu = ds[i];
            }
        }
        cout << "Cau thu co so ban thang lon nhat:\n" << maxCauThu << "\n";
    }

    void timMin() {
        if (ds.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        CauThu minCauThu = ds[0];
        for (int i = 1; i < ds.size(); ++i) {
            if (ds[i].getSoBanThang() < minCauThu.getSoBanThang()) {
                minCauThu = ds[i];
            }
        }
        cout << "Cau thu co so ban thang nho nhat:\n" << minCauThu << "\n";
    }

    void timKiem(const string& ten) {
        for (int i = 0; i < ds.size(); i++) {
            if (ds[i].getTen() == ten) {
                cout << ds[i] << "\n";
                return;
            }
        }
        cout << "Khong tim thay cau thu.\n";
    }

    void xoa(string ten) {
        for (int i=0; i < ds.size(); i++) {
            if (ds[i].getTen() == ten) {
                ds.erase(ds.begin() + i);
                cout << "Da xoa cau thu " << ten << "\n";
                return;
            }
        }
        cout << "Khong tim thay cau thu.\n";
    }

    void them(CauThu ct) {
        ds.push_back(ct);
    }
};

class App {
private:
    DanhSachCauThu danhSach;

public:
    void menu() {
        int luachon;
        do {
            cout << "1. Nhap danh sach cau thu\n";
            cout << "2. Xuat danh sach cau thu\n";
            cout << "3. Sap xep danh sach cau thu\n";
            cout << "4. Tim cau thu ghi ban nhieu nhat\n";
            cout << "5. Tim cau thu ghi ban it nhat\n";
            cout << "6. Tim kiem cau thu\n";
            cout << "7. Xoa cau thu\n";
            cout << "8. Them cau thu\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> luachon;
            switch (luachon) {
                case 1:
                    danhSach.nhap();
                    break;
                case 2:
                    danhSach.xuat();
                    break;
                case 3:
                    danhSach.sapXep();
                    cout << "Danh sach da duoc sap xep.\n";
                    break;
                case 4:
                    danhSach.timMax();
                    break;
                case 5:
                    danhSach.timMin();
                    break;
                case 6: {
                    string ten;
                    cout << "Nhap ten cau thu can tim: ";
                    cin.ignore();
                    getline(cin, ten);
                    danhSach.timKiem(ten);
                    break;
                }
                case 7: {
                    string ten;
                    cout << "Nhap ten cau thu can xoa: ";
                    cin.ignore();
                    getline(cin, ten);
                    danhSach.xoa(ten);
                    break;
                }
                case 8: {
                    string ten;
                    int tuoi, soBanThang, soPhutThiDau;
                    cout << "Nhap ten cau thu: ";
                    cin.ignore();
                    getline(cin, ten);
                    cout << "Nhap tuoi: ";
                    cin >> tuoi;
                    cout << "Nhap so ban thang: ";
                    cin >> soBanThang;
                    cout << "Nhap so phut thi dau: ";
                    cin >> soPhutThiDau;
                    CauThu ct(ten, tuoi, soBanThang, soPhutThiDau);
                    danhSach.them(ct);
                    cout << "Da them cau thu.\n";
                    break;
                }
                case 0:
                    cout << "Thoat chuong trinh.\n";
                    break;
                default:
                    cout << "Lua chon khong hop le.\n";
                    break;
            }
        } while (luachon != 0);
    }
};

int main() {
    App app;
    app.menu();
    return 0;
}
