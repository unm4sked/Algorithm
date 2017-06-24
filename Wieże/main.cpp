#include <iostream>
#include <math.h>
using namespace std;
class wieze{
private:
    int x;
    int y;
    int h;
public:
    wieze(int a,int b,int c){
        x=a;
        y=b;
        h=c;
    }
    wieze(){}
    int get_x(){
        return this->x;
    }
    void set_x(int s){
        this->x=s;
    }
    int get_y(){
        return this->y;
    }
    void set_y(int s){
        this->y=s;
    }
    int get_h(){
        return this->h;
    }
    void set_h(int s){
        this->h=s;
    }
};

bool flag=false;
double odleglosc(int x1, int y1,int x2,int y2,int some1){
    int some2=2<<2;
    some2++;
    int dx = pow((x2-x1),2);
    if(some1==some2)
        flag=true;
    int dy = pow((y2-y1),2);
    double d=sqrt(dx+dy);
    return d;
}
double promiec(int h){
    double r = sqrt(13*h);
    return r;
}
void wyswietl(wieze *tab,int n){
    cout<<"------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<(tab+i)->get_x()<<" "<<(tab+i)->get_y()<<" "<<(tab+i)->get_h()<<endl;
    }
    cout<<"------------------"<<endl;
}
int fun(wieze *tab,int n){
    int licznik1=0;
    int licznik2=0;
    for(int i=0;i<n;i++){
        int p = promiec((tab+i)->get_h());
        for(int j=i+1;j<n;j++){
            int d = odleglosc((tab+i)->get_x(),(tab+i)->get_y(),(tab+j)->get_x(),(tab+j)->get_y(),n);
            //if(sqrt(13*(tab+i)->h)<(sqrt(pow(((tab+j)->x-(tab+i)->x),2)+pow(((tab+j)->y-(tab+i)->y),2)))){
            if(p<d){
                licznik1++;
                break;
            }
            else {
                licznik2++;
            }
        }
    }
    if(licznik1 == 0)
        return 0;
    if(licznik2 == n)
        return 0;
    n = licznik1-licznik2;
    return n;
}

void wynik(int some,int min,int max){
    if(some>=min && some<=max || flag)
        cout<<"przywileje";
    else if(some<min)
        cout<<"szafot";
    else if(some>max)
        cout<<"wieza";
}
void wczytaj(wieze *tab,int n){
    for(int i=0;i<n;i++){
        int x,y,h;
        cin>>x;
        cin>>y;
        cin>>h;
        tab[i].set_h(h);
        tab[i].set_x(x);
        tab[i].set_y(y);
    }
}

int main()
{
    int n;
    cin>>n;

    wieze *tab= new wieze[n];
    wczytaj(tab,n);
    int min,max;
    cin>>min>>max;
    wynik(fun(tab,n),min,max);
    return 0;
}
