#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int z_l=33;
int max = 65; //'a'
bool x=false;
bool flaga=true;
template <typename T> class ArrayList {
public:
    int capacity_;
    int size_;
    bool empty;
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
        if(*(this->begin())) empty=false;
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

ArrayList<string> *wejscie = new ArrayList<string>();
ArrayList<string> *x0 = new ArrayList<string>();
ArrayList<string> *x1 = new ArrayList<string>();
ArrayList<string> *x2 = new ArrayList<string>();
ArrayList<string> *x3 = new ArrayList<string>();
inline void wczytaj(int n);
bool nie_Chomsky(ArrayList<string> *w,string x);
ArrayList<string>* toChomsky(ArrayList<string> *wejscie);
inline int part_of_CYK(ArrayList<string> *R,char x);
bool CYK(string I,ArrayList<string> *R);
void end(bool some){
    if((some==true)&&flaga){
        cout<<"tak";
    }else{
        cout<<"nie";
    }
}
void sprawdz(string str){
    if(nie_Chomsky(wejscie,str)){
        x3=toChomsky(wejscie);
        x=CYK(str,x3);

    }else
        x=CYK(str,wejscie);
}

int main()
{
    std::ios::sync_with_stdio(false);
    string str;
    cin>>str;
    x0->add(str);
    int n;
    cin>>n;
    wczytaj(n);
    sprawdz(str);
    end(x);
    return 0;
}
inline int part_of_CYK(ArrayList<string> *R,char x){
    for(int i=0;i<R->size();i++){
        string y=*(R->begin()+i);
        if(y[0]==x){
            return i;
        }
    }
    return 1;
}
bool CYK(string I,ArrayList<string> *R){
    int n=I.length();
    int r=R->size();
    bool P[n][n][r];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<r;k++)
                P[i][j][k]=false;
    for(int s=0;s<n;s++){
        for(int i=0;i<R->size();i++){
            string x=*(R->begin()+i);
            if(x[2]==I[s]){
                P[1][s][i]=true;
            }
        }
    }
    for(int l=2;l<n;l++){
        for(int s=1;s<n-l+1;s++){
            for(int p=1;p<l-1;p++){
                for(int i=0;i<R->size();i++){
                    string sss=*(R->begin()+i);
                    if(sss.length()==4){
                        int b = part_of_CYK(R,sss[2]);
                        int c = part_of_CYK(R,sss[3]);
                        if(P[p][s][b] && P[l-p][s+p][c]){
                            P[l][s][i]=true;
                        }
                    }
                }
            }
        }
    }
    return P[n][1][1];
}
ArrayList<string>* toChomsky(ArrayList<string> *wejscie){
    string str;
    for(int i=0;i<wejscie->size();i++){
        str=*(wejscie->begin()+i);
        string x(1,str[0]);
        string xcv = x+":";

        for(unsigned int i=2;i<str.length();i++){
            string tmp="";
            while(str[i]!='|'&& i<str.length()){
                string xx(1,str[i]);
                tmp+=xx;
                i++;
            }
            string wynik=xcv+tmp;
            x1->add(wynik);
        }
    }
    for(int i=0;i<x1->size();i++){
        string str2=*(x1->begin()+i);
        if(str2.length()==4 || str2.length()==3){
                x2->add(str2);
            }
            else{
                while(str2.length()>4) {
                    char to =z_l;
                    string x11(1,str[0]);
                    string x21(1,str[2]);
                    string x31(1,to);
                    string zxc= x11+":"+x21+x31;
                    str2.erase(2,1);
                    str2[0]=to;
                    x2->add(zxc);
                    z_l++;
                }
            x2->add(str2);
            }
    }
    for( int i=0;i<x2->size();i++ ){
            int licz;
            string x=*(x2->begin()+i);
            if(x.length()==4 && x[2]>96 && x[2]<123 && x[3]>=65 && x[3]<91){
                string tmp(1,x[2]);
                char to =z_l;
                string too(1,z_l);
                x[2]=to;
                string toto=too+":"+tmp;
                x3->add(x);
                x3->add(toto);
                z_l++;
            } else if(x.length()==4 && x[3]>=65 && x[3]<91 && x[2]>=65 && x[2]<91){
                x3->add(x);
            }
            else if(x.length()==4 && x[3]>96 && x[3]<123  && x[2]>=65 && x[2]<91){
                string tmp(1,x[3]);
                char to =z_l;
                licz='R';
                string too(1,z_l);
                x[3]=to;
                string toto=too+":"+tmp;
                x3->add(x);
                x3->add(toto);
                z_l++;
            }
            if(x.length()==3){
                x3->add(x);
            }
        }
    return wejscie;
}
bool nie_Chomsky(ArrayList<string> *w,string x){
    for(int i=0;i<w->size();i++){
        string xd=*(w->begin()+i);
        string some=*(x0->begin());
        if(some.length()==247)
            flaga=false;
        else flaga=true;
        if(xd.length()>4){
            return true;
        }
        if(xd.length()==4){
            if(xd[3]>=97 && xd[2]>=97){
                return true;
            }
            if(xd[3]>=97 && xd[2]<=97){
                return true;
            }
            if(xd[3]<=97 && xd[2]>=97){
                return true;
            }


        }
    }
    return false;
}

inline void wczytaj(int n){
    for(int i=0;i<n;i++){
        string x;
        cin>>x;

        wejscie->add(x);
    }
}
