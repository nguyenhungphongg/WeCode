/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <math.h>

void Input(double &c) { std::cin >> c; }
double pi(double c) {
    using namespace std;
    double i = 1;
    double t = 1/(2*i+1);
    // cout << t << endl;
    double Pi = 1;
    //dk dung: t > c
    while (t > c){
        Pi += pow(-1,i) * t;
        // cout << pow(-1,i) << '*' << t;
        i++;
        t = 1/(2*i+1);
    }
//###INSERT CODE HERE -
    return 4*Pi;
}

int main() {
    double c;

    Input(c);

    std::cout << "pi = " << std::fixed << std::setprecision(10) << pi(c);

    return 0;
}
