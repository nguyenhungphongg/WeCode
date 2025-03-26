#include <bits/stdc++.h>

using namespace std;

/* input
10
88
13
0
11
6
-2
-45
100
910
10000
*/
struct NODE{
    int data;
    NODE *pNext;
};

struct LIST{
    NODE *pHead, *pTail;
};

void khoiTao(LIST &l){ //2. khởi tạo một danh sách liên kết
    l.pHead = l.pTail = NULL;
}
NODE* GetNode(int x){ // Tạo ra một NODE trong LIST
    NODE *p = new NODE;
    if (p == NULL)
        return NULL; //ko có bộ nhớ để cấp phát
    p->data = x;
    p->pNext = NULL;
    return p;
}
// thêm node p vào đầu danh sách
void addHead(LIST &l, NODE *p){
    if (l.pHead == NULL){ //nếu đầu danh sách là NULL, danh sách rỗng
         l.pHead = l.pTail = p; //p chính là đầu và cuối
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
//thêm node p vào cuối danh sách
void addTail(LIST &l, NODE *p){
    if (l.pHead == NULL){ //nếu đầu danh sách là NULL, danh sách rỗng
         l.pHead = l.pTail = p; //p chính là đầu và cuối
    }
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
//5. nhập dữ liệu cho danh sách
void Input(LIST &l){
    int n; cout << "So luong node: " ; cin >> n;
    while(n--){
        int x; cin >> x;
        NODE *p = GetNode(x);
        addTail(l, p);
    }
}
void Output(LIST &l){
    //for(int i = 0; i < n; i++)
    if (l.pHead == NULL){
        cout << "Danh sach rong.\n";
    }
    for(NODE *p = l.pHead; p != NULL ; p = p->pNext)
        cout << p->data << " " ;
    cout << "\n";
}
void timMax(LIST &l){
    int Max = l.pHead->data;
    for(NODE *p = l.pHead->pNext; p; p = p->pNext){ // bắt đầu từ phần tử 1
        Max = (p->data > Max ? p->data : Max);
    }
    cout << "Phan tu lon nhat la: " << Max << endl;
}
void HoanVi(int &a, int &b){
    int Temp = b;
    b = a;
    a = Temp;
}
void Sort(LIST &l){
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        for(NODE *j = p->pNext; j != NULL; j = j->pNext){
            if(p->data > j->data){
                HoanVi(p->data, j->data);
            }
        }
    }
    cout << "Mang sau khi sap xep:\n";
    Output(l);
}
void GiaiPhong(LIST &l){
    NODE *p;
    while(l.pHead != NULL){
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
    cout << "Da giai phong LIST\n";
}
void addAfterQ(LIST &l, NODE *Q, NODE *P){
    //THÊM P VÀO PHÍA SAU Q
    for(NODE *p  = l.pHead; p != NULL; p = p->pNext){
        if(p == Q){
            NODE *behind = p->pNext;
            p->pNext = P;
            P->pNext = behind;
        }
    }
    cout << "Mang sau khi addAfterQ:\n";
    Output(l);
}
NODE* layDiaChi(LIST &l, int x){
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        if (!x--){
            return p;
        }
    }
}
NODE* searchData(LIST &l, int x){
    for(NODE *p = l.pHead; p; p=p->pNext){
        if(p->data == x){
            return p;
        }
    }
    return NULL;
}
void removeHead(LIST &l){
    if(l.pHead != NULL){
        NODE *p = l.pHead;
        l.pHead = p->pNext;
        if(l.pHead == NULL){
            l.pTail = NULL;
        }
        delete p;
    }
    cout << "Sau khi removeHead:\n";
    Output(l);
}
//cần 1 giá trị x nếu như muốn biết giá trị của AfterQ là gì
void removeAfterQ(LIST &l, NODE *Q){ //chính xác hơn thì dùng bool, trả về 1 nếu xoá đc, trả về 0 nếu k xoá đc
    NODE *p;
    if(Q != NULL){ //nếu Q ko phải là NODE cuối cùng
        p = Q->pNext; //p là NODE cần xoá vì nó nằm sau Q
        if(p != NULL){ //nếu p cũng ko phải là NULL
            if(p == l.pTail) //kiểm tra nếu p là cuối cuối cùng thì cập nhật Tail
                l.pTail = Q; //cập nhật Tail hiện tại là Q
            Q->pNext = p->pNext; //thay đổi hướng của con trỏ hiện tại thành con trỏ phía sau p
            delete p; //xoá p
        }
    }
    //cout << "Mang sau khi removeAfterQ:\n";
    Output(l);
}

void RemoveX(LIST &l, int x){
    NODE *Q, *p;
    Q = NULL;
    p = l.pHead;
    while (p!=NULL && p->data!=x) {
        Q = p;
        p = p->pNext;
    }

    if (p == NULL) return; // Tìm không thấy x
    if (Q != NULL) removeAfterQ(l, Q);
    else removeHead(l);
    cout << "Mang sau khi RemoveX\n";
    Output(l);
}
void XoaCuoi(LIST &l){
    NODE *prev;
    for(NODE *p = l.pHead; p; p=p->pNext){
        if(p==l.pTail){
            l.pTail = prev;
            prev->pNext = NULL;
            delete p;
        }
        prev = p;
    }
    delete prev;
    cout << "Mang sau khi xoa cuoi:\n";
    Output(l);
}
int main()
{
    freopen("input","r",stdin);
    LIST l;
    khoiTao(l);
    Input(l);
    Output(l);

    timMax(l);

    Sort(l);

    NODE *P = new NODE;
    P->data = -98;

    addAfterQ(l, layDiaChi(l,3), P);
    NODE* searcH = searchData(l, 910);
    cout << searcH << " " << searcH->data << "\n" ;

    removeHead(l);
    cout << "Mang sau khi removeAfterQ:\n";
    removeAfterQ(l,searcH);

    RemoveX(l,-2);

    XoaCuoi(l);

    GiaiPhong(l);
    Output(l);
    return 0;
}
