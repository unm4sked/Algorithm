#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string int2str(int i){
    ostringstream ss;
    ss << i;
    string str =ss.str();
    return str+" ";
}
//---------------LISTA------------------------
struct node{
public:
    int value;
    node * next;
    node(){
        next = 0;
    }
};

class List{
public:
    node * first;

    List(){
        first = 0 ;
    }

    void  dodaj(int x){
        node * n = new node;
        n->value=x;
        if(first==0){
            first=n;
        }
        else{
            node * tmp = first;
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp->next=n;
            n->next=0;
        }

    }

    void wyswietl_liste(){
        while(this->first){
            cout<<" "<<this->first->value;
            this->first=this->first->next;
        }
        cout<<" ";
    }
};

//----------------DRZEWA----------------------------------
class Wierzcholek{
public:
    string klucz;
    Wierzcholek * ojciec;
    Wierzcholek * Lsyn;
    Wierzcholek * Psyn;
    string l="";
    int ostatni=0;

    Wierzcholek(string klucz){
        this->klucz=klucz;
        ojciec=NULL;
        Lsyn = NULL;
        Psyn = NULL;
    }
};

class Drzewo{
public:
    Wierzcholek * Korzen;
    Drzewo(){
        Korzen=NULL;
    }

    void InOrder(Wierzcholek * x){

        if(x){
            InOrder(x->Lsyn);
            cout<<x->klucz<<" => "<<x->l<<endl;
            InOrder(x->Psyn);
        }
    }

     Wierzcholek * wyszukajIteracyjnie(string klucz,int j){
         Wierzcholek *x =this->Korzen;
         while(x!=NULL){
             if(x->klucz==klucz){
                 if(x->ostatni!=j)
                     x->l+=int2str(j); // !!!!
                 x->ostatni=j;
                 return x;
             }
             else if(x->klucz>klucz){
                 x=x->Lsyn;
             }
             else {
                 x=x->Psyn;
             }
         }
         return x;
     }

     Wierzcholek * wyszukaj(Wierzcholek *x,string klucz,int j){
            if(x==NULL){
                return x;
            }
            else if(x->klucz==klucz){
                if(x->ostatni!=j)
                    x->l+=int2str(j);
                x->ostatni=j;
                return x;
            }
            else if(x->klucz > klucz){
                wyszukaj(x->Lsyn,klucz,j);
            }
            else{
                wyszukaj(x->Psyn,klucz,j);
            }
        }

     void dodaj(string k,int i){

         Wierzcholek  *p = Korzen;
         Wierzcholek *poprz =NULL;
         while (p!=NULL) {
            poprz=p;
            if(k > p->klucz){
                p=p->Psyn;
            }
            else p=p->Lsyn;
         }
         if(Korzen==0) {
             this->Korzen = new Wierzcholek(k);
             Korzen->l+=int2str(i);
             Korzen->ostatni=i;
         }
         else if(k>poprz->klucz){
             poprz->Psyn= new Wierzcholek(k);
             poprz->Psyn->l+=int2str(i);
             poprz->Psyn->ostatni=i;
         }
         else {
             poprz->Lsyn=new Wierzcholek(k);
             poprz->Lsyn->l+=int2str(i);
             poprz->Lsyn->ostatni=i;
         }

     }
};
//---------------------Pozostale-funkcje----------------------
bool operator > (const string &a,const string &b){
    bool flags = false;
    for(unsigned int i=0;i<a.size() && i<b.size();i++)
    {

        if(a[i]<b[i]){
            flags=true;
            break;
        }
    }

    return flags;
}



//--------------------------------------------------
int main()
{
    Drzewo *d1 = new Drzewo();
    string tmp;
    int n,m;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>tmp;
            if(d1->wyszukajIteracyjnie(tmp,i+1)){

            }
            else d1->dodaj(tmp,i+1);
        }
    }
    d1->InOrder(d1->Korzen);
    return 0;
}
