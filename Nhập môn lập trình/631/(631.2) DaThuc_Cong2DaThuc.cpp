#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct DATHUC {
    double *soMu;
    int soMuLonNhat;
};

bool checkIfZero(DATHUC A) {
    for (int i = 0; i <= A.soMuLonNhat; i++) {
        if (A.soMu[i] != 0) return false;
    }
    return true;
}

DATHUC* Nhap() {
    int n;
    cin >> n;

    DATHUC *Mang = new DATHUC;
    Mang->soMuLonNhat = 0;
    Mang->soMu = new double[101]{}; // Tạo kích thước lớn hơn để đảm bảo không lỗi.

    for (int i = 0; i < n; i++) {
        double temp1; // Hệ số
        int temp2;    // Số mũ
        cin >> temp1 >> temp2;

        Mang->soMu[temp2] += temp1;
        
        if (temp2 > Mang->soMuLonNhat) {
            Mang->soMuLonNhat = temp2;
        }
    }
    return Mang;
}

void Xuat(DATHUC A) {
    if (checkIfZero(A)) {
        cout << 0;
        return;
    }

    bool dautien = true;
    for (int i = A.soMuLonNhat; i >= 0; i--) {
        double HeSo = A.soMu[i];
        if (HeSo != 0) {
            if (!dautien && HeSo > 0) cout << '+';

            if (i > 1) {
                if (HeSo == 1) cout << "x^" << i;
                else if (HeSo == -1) cout << "-x^" << i;
                else cout << HeSo << "x^" << i;
            } else if (i == 1) {
                if (HeSo == 1) cout << "x";
                else if (HeSo == -1) cout << "-x";
                else cout << HeSo << "x";
            } else {
                cout << HeSo;
            }
            dautien = false;
        }
    }
}

DATHUC CongLai(DATHUC *Big, DATHUC *Small) {
    int bacLonNhat = Big->soMuLonNhat;
    DATHUC kqua;
    kqua.soMuLonNhat = bacLonNhat;
    kqua.soMu = new double[bacLonNhat + 1]{};

    for (int i = 0; i <= Small->soMuLonNhat; i++) {
        kqua.soMu[i] = Small->soMu[i];
    }
    for (int i = 0; i <= Big->soMuLonNhat; i++) {
        kqua.soMu[i] += Big->soMu[i];
    }
    return kqua;
}

DATHUC Tong2DaThuc(DATHUC *A, DATHUC *B) {
    return (A->soMuLonNhat > B->soMuLonNhat ? CongLai(A, B) : CongLai(B, A));
}

int main() {
    DATHUC *A, *B;
    A = Nhap();
    B = Nhap();
    cout << "Da thuc A: "; Xuat(*A);
    cout << "\nDa thuc B: "; Xuat(*B);
    cout << "\nA+B = ";
    Xuat(Tong2DaThuc(A, B));
    return 0;
}
