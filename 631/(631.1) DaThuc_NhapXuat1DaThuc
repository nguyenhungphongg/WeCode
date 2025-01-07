#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct DATHUC {
    double *somu;
    int ssomu;
};

bool tatcabang0 = true;

DATHUC* Nhap() {
    int n;
    cin >> n;
    DATHUC *Mang = new DATHUC;
    double first1;
    int second;
    cin >> first1 >> second;
    Mang->somu = new double[second + 1]{};
    Mang->somu[second] = first1;
    Mang->ssomu = second;
    if(first1 != 0) tatcabang0 = false;
    for (int i = 1; i < n; i++) {
        double Nheso;
        int Nsomu;
        cin >> Nheso >> Nsomu;
        if (Nheso != 0) tatcabang0 = false;
        Mang->somu[Nsomu] += Nheso;
    }
    return Mang;
}

void Xuat(DATHUC B) {
    double second = B.ssomu;
    if (tatcabang0 == true) {
        cout << 0;
        return;
    }
    bool dautien = true;
    for (int i = second; i >= 0; i--) {
        double Heso = B.somu[i];
        if(Heso!=0){
            if(dautien == false && Heso >0) cout << '+';
            if (i>1){//mu lon hon 1
                if(Heso==1) cout << "x^"<< i;
                else if (Heso==-1)cout << "-x^" << i;
                else cout << Heso << "x^" << i;
            } else if (i==1){ //mu bang 1
                if(Heso==1) cout << "x";
                else if (Heso==-1)cout << "-x";
                else cout << Heso << "x";
            } else {// mu bang 0
                cout << Heso;
            }
        dautien = false;
        }
    }
}
double TinhDaThuc(DATHUC A, double x) {
    int second = A.ssomu;
    double sum = 0;
    for (int i = 0; i <= second; i++) {
        double Heso = A.somu[i];
        sum += Heso * pow(x,i);
    }
    return sum;
}

int main() {
    DATHUC *B;
    B = Nhap();
    cout << "Da thuc vua nhap la: ";
    Xuat(*B);

    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
