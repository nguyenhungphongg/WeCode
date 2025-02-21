#include <iostream>
#include <string>
using namespace std;
const int gia = 5000;
const int giaVP = 100000;
/* file input.txt:
2
Nguyen Hung Phong
2006
1000000
30
Nguyen Anh Duy
2006
2000000
50
2
Tran Khanh An
2008
30
Mr Pip
2008
30
*/
struct Basic{
    string hoTen;
    int namSinh;
};
struct SX{
    Basic coBan;
    int luongCanBan;
    int soSanPham;
    int tongLuong;

};
struct VP{
    Basic coBan;
    int soNgayLamViec;
    int tongLuong;
};

void nhap(SX arrSX[], int &slSX, VP arrVP[], int &slVP);
void inNV(SX arrSX[], int slSX, VP arrVP[], int slVP);
void tinhTongLuong(SX arrSX[], int slSX, VP arrVP[], int slVP, int &Max, int &trenhat);
void luongLonNhat(SX arrSX[], int slSX, VP arrVP[], int slVP, int &Max, int &trenhat);
void youngestAndRichest(SX arrSX[], int slSX, VP arrVP[], int slVP, int &Max, int &trenhat);
int main()
{
    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w", stdout);
    SX arrSX[100]; int n = 0;
    VP arrVP[100]; int m = 0;
    int LuongMax = 0;
    int youngest = 0;
    //cout << "So luong NVVP (duoi 100): "; cin >> m;
    nhap(arrSX,n,arrVP,m);
    inNV(arrSX,n,arrVP,m);
    tinhTongLuong(arrSX,n,arrVP,m, LuongMax,youngest);
    luongLonNhat(arrSX,n,arrVP,m, LuongMax,youngest);
    youngestAndRichest(arrSX,n,arrVP,m, LuongMax,youngest);
    return 0;
}
//khai bao prototype
void nhap(SX arrSX[], int &slSX, VP arrVP[], int &slVP){
    //cout << sizeof(arrSX);
    cout << "So luong NVSX (duoi 100): " << endl; cin >> slSX;
    cin.ignore();
    for(int i = 0; i < slSX; i++){
        getline(cin, arrSX[i].coBan.hoTen);
        cin >> arrSX[i].coBan.namSinh;
        cin >> arrSX[i].luongCanBan;
        cin >> arrSX[i].soSanPham;
        cin.ignore();
    }
    cout << "So luong NVVP (duoi 100): "; cin >> slVP;
    cin.ignore();
    for(int i = 0; i < slVP; i++){
        getline(cin, arrVP[i].coBan.hoTen);
        cin >> arrVP[i].coBan.namSinh;
        cin >> arrVP[i].soNgayLamViec;
        cin.ignore();
    }
}
void inNV(SX arrSX[], int slSX, VP arrVP[], int slVP){
    cout << endl << "Xuat ra thong tin vua nhap: " << endl;
    for(int i = 0; i < slSX; i++){
        cout << "Ho ten: " << arrSX[i].coBan.hoTen << endl;
        cout << "Nam Sinh: " << arrSX[i].coBan.namSinh << endl;
        cout << "Luong can ban: " << arrSX[i].luongCanBan << endl;
        cout << "So san pham: " << arrSX[i].soSanPham << endl;
        cout << endl;
    }
    for(int i = 0; i < slVP; i++){
        cout << "Ho ten: " << arrVP[i].coBan.hoTen << endl;
        cout << "Nam Sinh: " << arrVP[i].coBan.namSinh << endl;
        cout << "So ngay lam viec: " << arrVP[i].soNgayLamViec << endl;
        cout << endl;
    }
}
void tinhTongLuong(SX arrSX[], int slSX, VP arrVP[], int slVP, int &Max, int &trenhat){
    int sum = 0;
    for(int i = 0; i < slSX; i++){
        arrSX[i].tongLuong =  arrSX[i].luongCanBan + arrSX[i].soSanPham * gia;
        sum += arrSX[i].tongLuong;
        if (arrSX[i].tongLuong > Max) Max = arrSX[i].tongLuong;
        if (arrSX[i].coBan.namSinh > trenhat) trenhat = arrSX[i].coBan.namSinh;
    }
    for(int i = 0; i < slVP; i++){
        arrVP[i].tongLuong = arrVP[i].soNgayLamViec * giaVP;
        sum += arrVP[i].tongLuong;
        if (arrVP[i].tongLuong > Max) Max = arrVP[i].tongLuong;
        if (arrVP[i].coBan.namSinh > trenhat) trenhat = arrVP[i].coBan.namSinh;
    }
    cout << endl << "Tong luong:" << sum;
}
void luongLonNhat(SX arrSX[], int slSX, VP arrVP[], int slVP, int &Max, int &trenhat){
    cout << endl << "Luong lon nhat la: " << Max << endl;
    for(int i = 0; i < slSX; i++){
        if (arrSX[i].tongLuong == Max)
            cout <<arrSX[i].coBan.hoTen << endl;
    }
    for(int i = 0; i < slVP; i++){
        if (arrVP[i].tongLuong == Max)
            cout <<arrVP[i].coBan.hoTen << endl;
    }
}
void youngestAndRichest(SX arrSX[], int slSX, VP arrVP[], int slVP, int &Max, int &trenhat){
    cout << endl << "Tuoi tre nhat la: " << trenhat << endl;
    for(int i = 0; i < slSX; i++)
        if (arrSX[i].tongLuong == Max && arrSX[i].coBan.namSinh == trenhat)
            cout << arrSX[i].coBan.hoTen << endl;
    for(int i = 0; i < slVP; i++)
        if (arrVP[i].tongLuong == Max && arrVP[i].coBan.namSinh == trenhat)
            cout << arrVP[i].coBan.hoTen << endl;
}
