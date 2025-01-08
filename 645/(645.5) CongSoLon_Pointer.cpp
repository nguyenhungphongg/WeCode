/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cstring>
#define MAX 200

struct SOLON {
    int *so;
    int n;
};
#include <string>
using namespace std;
void output(SOLON* out){
    int SL = MAX - out->n;
    // cout << demChuSo(out->n) << endl;
    // cout << SL;
    for(int i = SL+1; i <= MAX; i++) {
        cout << out->so[i];
    }
    cout << endl;
    // cout << out->n;
    // cout << "&";
}
int demChuSo(int n){
    int dem = 0;
    while(n!=0){
        dem++;
        n /= 10;
    }
    return dem;
}
void truyenVaoMang(int* arr, int &n){
    string s;
    cin >> s;
    int j = MAX;
    n = s.length();
    int k = 0;
    for(int i = n-1; i >= 0; i--) {
        arr[j-k] = s[i] - '0';
        k++;
    }
    // cout << a.n << "$" << endl;
}
void input(SOLON &a){
    a.so = new int[MAX+1]{};
    // a.n = demChuSo(a.n);
    truyenVaoMang(a.so, a.n);
}
SOLON* input(){
    SOLON *b = new SOLON;
    b->so = new int[MAX+1]{};
    truyenVaoMang(b->so, b->n);
    // b->n = demChuSo(b->n);
    return b;
}
SOLON Plus(SOLON Big, SOLON Small){
    int nho = 0;
    int last = MAX; // MAX la phan tu cuoi cung
    int first = MAX - Big.n+1;
    // cout << last << "#" << endl;
    // cout << first << "#" << endl;
    SOLON ketqua;
    ketqua.so = new int[MAX+1]{};
    ketqua.n = Big.n;
    // cout << Big.n << "&" << endl;
    for(int i = last; i >= first-1  ; i--) {
        // cout << i << endl;
        ketqua.so[i] = Big.so[i] + Small.so[i] + nho;
        if (nho > 0 && i == first -1)
            ketqua.n++;
        if (nho > 0) nho--;
        if (ketqua.so[i] >= 10){
            ketqua.so[i] -= 10;
            nho++;
        }
        // cout << Big.so << "$" << endl;
    }
    return ketqua;
}
SOLON Cong(SOLON A, SOLON &b){
    return (A.n >= b.n ? Plus(A,b) : Plus(b,A));
}
//###INSERT CODE HERE -
int main() {
    SOLON a, *b, S;
    input(a);
    b=input();
    S=Cong(a, *b);
    output(&a);
    output(b);
    output(&S);
    return 0;
}
