#define deb(xx) cout << #xx << " " << xx << endl;
#include <iostream>
using namespace std;
#define MAX 100
#define min(x,y) (x > y) ? y : x

int B[MAX], C[MAX];
void Merge(int A[], int B[], int C[],int nB, int nC, int k){
    int p, ib, ic, pb, pc;
    p = pb = pc = ib = ic = 0; //k chinh la so luong phan tu phai chia cung luc
    int kb = min(k,nB), kc = min(k, nC);
    while(nB > 0 && nC > 0){
        if(B[pb + ib] <= C[pc+ic]){
            A[p++] = B[pb+ib]; ib++;
            if(ib == kb){ //neu nhu da di het mang, thi bat dau them vao nhung phan tu o cuoi
                while(ic < kc){
                    A[p++] = C[pc+ic]; ic++;
                }
                pb += kb; pc += kc; ib = ic = 0; nB -= kb; nC -= kc;
                kb = min(k, nB); kc = min(k, nC);
            }
        } else {
            A[p++] = C[pc+ic]; ic++;
            if(ic == kc){ //neu nhu da di het mang, thi bat dau them vao nhung phan tu o cuoi
                while(ib < kb){
                    A[p++] = B[pb+ib]; ib++;
                }
                pb += kb; pc += kc; ib = ic = 0; nB -= kc; nC -= kc;
                kb = min(k, nB); kc = min(k, nC);
            }
            }
        }
    }
void MergeSort(int A[], int N){
    int p, pb, pc, k=1, i;
    while(k < N){
        p=pb=pc=0;
        while(p < N){
            for(i=0; i<k && p<N; i++ ) B[pb++] = A[p++];
            for(i=0; i<k && p<N; i++ ) C[pc++] = A[p++];
        }
        Merge(A,B,C,pb,pc,k);
        k *= 2;
    }
}
void Output(int a[],int n)
{
     for (int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int A[] = {12, 2, 8, 5, 1, 6, 4, 15} ;
    int N=8;
    MergeSort(A,N);
    Output(A,N);
    return 0;
}

