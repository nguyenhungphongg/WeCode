/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct SinhVien {
    char *MASV;
    char *HoTen;
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
#include <math.h>
double lamTron(double c){
    return round(c*100)/100; //lam tron den phan thap phan thu 2
}
void Nhap(SinhVien *&A){
    A = new SinhVien;
    A->MASV = new char[10]; 
    A->HoTen = new char[100];
    cin.getline(A->MASV, 10); //cout << A->MASV;
    cin.getline(A->HoTen, 100); //cout << A->HoTen;
    cin.getline(A->NgaySinh,12); //cout << A-> NgaySinh;
    cin >> A->GioiTinh;
    cin >> A->DiemToan >> A->DiemLy >> A->DiemHoa;
    A->DTB = lamTron((A->DiemToan + A->DiemLy + A->DiemHoa)/3);
    // cout << A->GioiTinh; //cin.ignore();
    // cout << A->DiemToan << A->DiemLy << A->DiemHoa;
}
string format(double num){
    string a = to_string(num);
    string b;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '.'){
            if(a[i+1] == '0') break;
            if(a[i+2] !='0'){
                b.push_back(a[i]);
                b.push_back(a[i+1]);
                b.push_back(a[i+2]);
                break;
            }
            if(a[i+1] != '0' && a[i+2] == '0'){
                b.push_back(a[i]);
                b.push_back(a[i+1]);
                break;
            }
        }
        b.push_back(a[i]);
    }
    return b;
}
void Xuat(SinhVien A){
    string tab = "\t";
    cout << A.MASV << tab << A.HoTen << tab << 
    A.NgaySinh << tab << A.GioiTinh << tab << format(A.DiemToan) << tab << format(A.DiemLy) 
    << tab << format(A.DiemHoa) << tab << format(A.DTB);
}
//###INSERT CODE HERE -

int main() {
    SinhVien *A;
    Nhap(A);
    Xuat(*A);
    return 0;
}
