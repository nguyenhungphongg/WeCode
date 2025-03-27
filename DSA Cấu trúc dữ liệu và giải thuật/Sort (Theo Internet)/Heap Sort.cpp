#include <bits/stdc++.h>

#define Vec vector<float>
#define trigger <
// >: từ bé đến lớn
// <: từ lớn đến bé
using namespace std;
/*input
10
-9 3 44 10 0 89 93 12 15.5 20.25
*/
/*
Các nốt ko phải nốt lá là các phần tử có chỉ số từ 0 => n/2 - 1 trong 1 Max Heap

Để xây dựng 1 Max Heap, phảu xét 3 nốt ko phải là nốt lá.

Nếu là nốt lá thì nốt tại đó ko có con nào
Nếu ko phải là nốt lá thì nốt tại đó có ít nhất 1 con

Các nốt ko phải nốt là là từ 0 => n/2 - 1

Heap Sort:
Sau khi xây xong Max Heap thì lần lượt hoán vị phần tử lớn nhất (HIỆN TẠI của cả mảng) với phần tử cuối cùng trong mảng
*/
void Heapify(Vec &mang, int i, int n){ // là thao tác để xây dựng 1 Max Heap
    // n là vị trí tối đa mà Heapify có thể chạm đến, truyền n nhỏ hơn để "tạm thời" bỏ qua các nhánh đã được sort (trong hàm heapsort)
    int largest = i;
    int left = 2 * i + 1; //nút bên trái
    int right = 2 * i + 2; // nút bên phải
    if (left < n && mang[left] trigger mang[largest]) // nếu nút bên trái lớn hơn arr[largest], cập nhật largest là chỉ số (ko phải value)
        largest = left;
    if (right < n && mang[right] trigger mang[largest])
        largest = right;
    if (largest != i) // nếu largest đã bị thay đổi, tức là cần phải swap
    {
        swap(mang[i], mang[largest]);
        Heapify(mang, largest, n);
    }
}
void print(Vec mang){
    for(auto i : mang) cout << i << ' ';
    cout << "\n";
}
void HeapSort(Vec &mang){
    // bước 1. xây dựng max heap (hoặc min heap)
    int n = mang.size();
    for(int i = n / 2 - 1; i >= 0; i--)
        Heapify(mang,i, n);
    cout << "Sau khi Heapify lan dau toan bo mang\n";
    print(mang);
    for(int i = n - 1; i >= 0; i--){//i chính là phần tử cuối cùng chưa được sắp xếp
        swap(mang[0], mang[i]); //hoán đổi phần từ to nhất là mang[0] và phần tử cuối cùng
        Heapify(mang, 0 , i); //sau khi hoán đổi phần tử to nhất, bây giờ mang[0] ko phải là phần tử to nhất, tái kích hoạc Heapify để tìm phần tử
        //lớn nhất trong các nốt còn lại trong Max Heap
    }

}

int main(){
    freopen("input","r",stdin);
    Vec mang;
    int n; cin >> n;
    while(n--){
        float temp; cin >> temp;
        mang.push_back(temp);
    }
    HeapSort(mang);
    cout << "Mang sau khi HeapSort:\n";
    print(mang);
    return 0;
}
