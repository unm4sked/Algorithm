#define ERR -1
#define MIN_INT -2147483647
#define MAX_INT 2147483647
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Node {
public:
    int info;
    int liczb;
    struct Node* tcwcz;
    struct Node* nastep;
};
 Node* front = NULL;
 Node* pr = NULL;
class Que{
public:
    Que(){}
    void E(int x) {
        Node * temp = new Node();
        temp->nastep = NULL;
        temp->tcwcz =NULL;
        temp->liczb++;
        temp->info =x;
        if((front==NULL) &&(temp->liczb) && (pr==NULL) ){
            front = temp;
            pr =  temp;
            pr->liczb++;
        }
        pr->nastep = temp;
        pr->tcwcz=pr->nastep;
        pr = temp;
    }

    void D() {
        Node* temp = front;
        if(front == NULL) {
            //ITS EMPTY;
        }
        if(front == pr) {
            front = NULL;
            pr = NULL;
        }
        else {
            front = front->nastep;
        }
        delete temp;
    }
    bool e()
    {
        if(front == NULL)
            return true;
        else return false;
    }

    int F() {
        if(front == NULL) {
            //empty
            return MIN_INT;
        }
        return front->info;
    }
};

struct Wierzcholek {
    int odleglosc;
    int pxx;
};

template <typename T> class ArrayList {
public:
    int capacity_;
    int size_;
    T* data_;


    ArrayList () : ArrayList(16) {}

    explicit ArrayList (int capacity) : capacity_(16), size_(0) {
        while (capacity > capacity_) {
            capacity_ *= 2;
        }

        data_ = new T[capacity_];
    }

    ArrayList<T> (const ArrayList<T> & that) : capacity_(that.capacity_), size_(that.size_) {
        data_ = new T[capacity_];
        memcpy(data_, that.data_, sizeof(T) * size_);
    }



    ~ArrayList() {
        delete[] data_;
    }


    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    void add (T const& value) {
        if (size_ + 1 <= capacity_) {
            data_[size_] = value;
            ++size_;
        }
        else {
            capacity_ *= 2;

            T* newData_ = new T[capacity_];
            memcpy(newData_, data_, sizeof(T) * size_);

            delete[] data_;
            data_ = newData_;

            data_[size_] = value;
            ++size_;
        }
    }


    T* begin () {
        return data_;
    }


    T* end () {
        return data_ + size_;
    }


};

class Graf {
public:

    int n;
    Wierzcholek *w;
    ArrayList<int> *k;
    Graf(int pn) {
        n = pn;
        w = new Wierzcholek[n*2];
        k = new ArrayList<int>[n*2];
    }
    void Krawedz(int a, int b) {
        if(a!=b){
            k[a].add(b);
            k[b].add(a);
        }
    }
    void BFS(int a) {
        int b = a;
        bool is=false;
        Que *q = new Que();
        int i=0;
        while(i < n) {
            w[i].odleglosc = ERR;
            w[i].pxx = ERR;
            i++;
        }
        w[a].odleglosc = 0;
       q->E(a);
        while (!q->e()) {
            int c = q->F();
            q->D();
            int *i=k[c].begin();
            while (i != k[c].end()){
                int value1= *i;
                if (w[value1].odleglosc != ERR){

                    bool ie=q->e();
                    if(is && ie){
                        w[value1].odleglosc = w[b].odleglosc;
                        w[value1].pxx = b;
                        q->E(value1);
                    }
                }
                else if(w[value1].odleglosc == ERR){
                    w[value1].odleglosc = w[c].odleglosc + 1;
                    w[value1].pxx = c;
                    q->E(value1);
                }

                i++;
            }
        }
    }

};

int main() {
    int a, b;
    int n,m;
    cin>>n>>m;
    Graf *g = new Graf(n);
    int i=0;
    while (m>i) {
        cin >> a >> b;
        g->Krawedz(a, b);
        i++;
    }

    int p1,p2,tmp;
    cin>>p1>>p2;
    bool p1_p2=false;
    int c,x1,x2;
    string wy="";
    cin>>c;
    for (int i = 0; i < c; i++) {
        cin>>tmp;
        g->BFS(p1);
        x1=g->w[tmp].odleglosc;

        g->BFS(p2);
        x2=g->w[tmp].odleglosc;

        if((x1==ERR) && (x2==ERR)){
            cout<<"Brak połączenia z wierzchołkiem "<<tmp;
            return 0;
        }

        else if((x1==ERR) && (x2!=ERR)){
            wy+="2 ";
            p1_p2=false;
            p2=tmp;
        }

        else if((x1!=ERR) && (x2==ERR)){
            wy+="1 ";
            p1_p2=true;
            p1=tmp;
        }

        else if(x1<x2){
            wy+="1 ";
            p1_p2=true;
            p1=tmp;
        }
        else if(x1>x2){
            wy+="2 ";
            p1_p2=false;
            p2=tmp;
        }
        else{
            if(p1_p2){
                 wy+="2 ";
                 p1_p2=false;
                 p2=tmp;
            }
            else{
                 wy+="1 ";
                 p1_p2=true;
                 p1=tmp;
            }
        }
    }
    cout<<wy;
    return 0;
}
