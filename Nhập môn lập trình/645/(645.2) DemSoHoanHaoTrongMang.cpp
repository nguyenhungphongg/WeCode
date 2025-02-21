/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
#define MAXN 100
using namespace std;
void Input(int a[], int &n){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
bool check(int n){
    int sum = 0;
    for(int i = 1; i < n; i++) {
        if(n%i==0){
            sum += i;
        }
        if (sum == n) return true;
    }
    return false;
}
int DemSoHoanHao(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(check(a[i])) sum++;
    }
    return sum;
}
int main() {
    int a[MAXN], n;
    Input(a, n);
    // cout << check(-44);
    std::cout << DemSoHoanHao(a, n);
    return 0;
}
