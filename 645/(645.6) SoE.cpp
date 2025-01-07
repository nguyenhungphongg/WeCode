#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double ABS(double v) {
    return (v > 0 ? v : -v);
}

// Tính giai thừa
double GiaiThua(int n) {
    if (n==0) return 1;
    return n*GiaiThua(n-1);
}

long double ELuyThuaX(int x, double c) {
    int i = 1;
    double EMuX = 1;
    double t = pow(x, i) / GiaiThua(i);
    // cout << "#"<< (ABS(t) >c) << endl;
    while (ABS(t)>= c) {
        EMuX += t;
        i++;
        t = pow(x, i) / GiaiThua(i);
    }
    return EMuX;
}

void Input(double &c) {
    cin >> c;
}

void Input(int &x) {
    cin >> x;
}

int main() {
    double c; // Độ chính xác epsilon
    int x;         // Giá trị x

    Input(x);
    Input(c);

    // Tính giá trị e^x và hiển thị
    std::cout << "e^" << x << " = " << std::fixed << std::setprecision(10)
              << ELuyThuaX(x, c) << endl;

    return 0;
}
