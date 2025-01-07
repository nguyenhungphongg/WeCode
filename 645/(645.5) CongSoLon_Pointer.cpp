#include <iostream>
#define MAX 200
using namespace std;

struct SOLON {
    int *so;
    int n;
};
using namespace std;
int demChuSo(long long n) {
    if (n == 0) return 1;
    int d = 0;
    while (n != 0) {
        d++;
        n /= 10;
    }
    return d;
}

void input(SOLON &a) {
    string num;
    cin >> num;
    a.n = num.length();
    a.so = new int[MAX]{};
    for (int i = 0; i < a.n; i++) {
        a.so[i] = num[i] - '0';
    }
}

SOLON* input() {
    SOLON *a = new SOLON;
    string num;
    cin >> num;
    a->n = num.length();
    a->so = new int[MAX]{};
    for (int i = 0; i < a->n; i++) {
        a->so[i] = num[i] - '0';
    }
    return a;
}

void output(SOLON *a) {
    for(int i = 0; i < a->n; i++) {
        cout << a->so[i];
    }
    cout << endl;
}
SOLON Plus(SOLON Big, SOLON Small){

}
void Reverse(SOLON v){
    int left = 0;
    int right = v.n - 1;
    while(left<right){
        swap(v.so[left], v.so[right]);
        left++;
        right--;
    }
}
SOLON Cong(a,*b){

    SOLON ketqua = (a.n > b.n ? Plus(a,b) : Plus(b,a))
}
main() {
    SOLON a, *b, S;
    input(a);
    b = input();
    S = Cong(a, *b);
    output(&a);
    output(b);
    output(&S);
    return 0;
}
