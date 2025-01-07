/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
using namespace std;
#define MAXN 100

struct Ngay {
    int d, m, y;
};
struct SinhVien{
    char MASV[10];
    char HoTen[MAXN];
    Ngay NamSinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
#include <math.h>
double lamTron(double c){
    return round(c*100)/100; //lam tron den phan thap phan thu 2
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
void Nhap(SinhVien *&A, int &n){
    cin >> n;
    if(n==0) return;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin >> ws;
    A = new SinhVien[n];
    for(int i = 0;i < n; i++) {
        // cout << i << endl;
        cin.getline(A[i].MASV, 10);
        cin.getline(A[i].HoTen, MAXN);
        // cout << A[i].HoTen << endl;
        cin >> A[i].NamSinh.d;
        cin >> A[i].NamSinh.m;
        cin >> A[i].NamSinh.y;
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan >> A[i].DiemLy >>
        A[i].DiemHoa;
        A[i].DTB = lamTron((A[i].DiemToan+A[i].DiemLy+A[i].DiemHoa)/3);
        if(i != n-1) cin >> ws;
        // cout << A[i].NamSinh.d;
    }
}
void Xuat(const SinhVien *A, const int n){
    if (n==0){
        cout << "Empty List.";
        return;
    }
    string tab = "\t";
    char gachcheo = '/';
    for(int i = 0; i < n; i++) {
        cout << A[i].MASV << tab <<
        A[i].HoTen << tab <<
        A[i].NamSinh.d << gachcheo << 
        A[i].NamSinh.m << gachcheo << 
        A[i].NamSinh.y << tab << 
        A[i].GioiTinh << tab << 
        A[i].DiemToan << tab << 
        A[i].DiemLy << tab << 
        A[i].DiemHoa << tab << 
        format(A[i].DTB);
        cout << endl;
    }
}
//###INSERT CODE HERE -

int main() {
    SinhVien *A;
    int n;
    Nhap(A, n);
    Xuat(A, n);
    return 0;
}
