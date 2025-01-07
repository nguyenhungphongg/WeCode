/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
do
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;

int TinhTong_4(int n){
    if (n == 1) return 1;
    return (n*n+TinhTong_4(n-1));
}
//###INSERT CODE HERE -

int main(){
    int n;
    std::cin >> n;
    std::cout << TinhTong_4(n);
    return 0;
}
