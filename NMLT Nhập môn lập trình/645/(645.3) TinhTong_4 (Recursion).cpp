/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
do
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;

void TinhTong_4(int &n, float &S){
    if (n == 0) return;
    S += n*n;
    int e = n-1;
    TinhTong_4(e,S);
}
//###INSERT CODE HERE -

int main(){
    int n;
    float S=0;
    std::cin >> n;
    TinhTong_4(n, S);
    std::cout << S;
    return 0;
}
