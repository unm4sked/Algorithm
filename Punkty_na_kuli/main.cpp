#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define WARTOSC_POM 300000 //pomocnicza tablica
#define TMP_ORTODROMA 0.01745329
#define TMP_ORTODROMA2 6371000.0
#define _RAD 1.666
//~W pierwszej linii dana jest liczba punktów. Mieści sie ona w przedziale od 2 do 100 000 włącznie.~

using namespace std;

class punkt{
public:
//    double dlugosc_stopnie;
//    double dlugosc_minuty;
//    double szerokosc_stopnie;
//    double szerokosc_minuty;
//    char dlugosc_znak;
//    char szerokosc_znak;
//    string kod;

    string kod;
    float dlugosc;
    float szerokosc;
    punkt(){

    }
    ~punkt(){

    }
};
float ortodroma(punkt p1,punkt p2);
void wczytaj(int n, punkt *tab);
inline string abc(string a,string b);
float brut_force(punkt *tab,int n);
inline bool Xwedlug (const punkt & a, const punkt & b);
inline bool Ywedlug (const punkt & a, const punkt & b);
inline void upd_ans (const punkt & a, const punkt & b);
void rec (punkt *a,int l, int r,int n);
float mindist;
pair<string, string> result; //zmienna globalna w której będzie znajdował się ostat
//=========================================
int main()
{
    //START
    std::ios::sync_with_stdio(false);
    int _liczba_punktow,n;
    float sfera;
    cin>>_liczba_punktow;
    n=_liczba_punktow;
    cin>>sfera;
    punkt *_punkt_tab = new punkt[_liczba_punktow];
    wczytaj(_liczba_punktow,_punkt_tab);
    sort(_punkt_tab, _punkt_tab+_liczba_punktow, &Xwedlug);
    mindist = 200000000;
    rec(_punkt_tab,0,( _liczba_punktow-1),n);
    //cout<<"---------------"<<endl;
    //brut_force(tab,n);
    //cout<<abc(v,x);
    //cout<<"---------------"<<endl;
    //cout<<abc(ansa,ansb);
    cout<<result.first<<" "<<result.second;
    //cout<<"---------------"<<endl;
    //delete _punkt_tab;
    //END

}
//=========================================
float ortodroma(punkt p1,punkt p2){

    float x1 = ((float)p1.szerokosc)*(TMP_ORTODROMA);
    float x2 = ((float)p2.szerokosc)*(TMP_ORTODROMA);
    float zxcv1 = (abs(p1.szerokosc-(float)p2.szerokosc))*(TMP_ORTODROMA);
    float zxcv2 = (abs(p1.dlugosc-(float)p2.dlugosc))*(TMP_ORTODROMA);
    float some = (sin((float)zxcv1/2.0))*(sin((float)zxcv1/2.0))+(cos(x1))*(cos(x2))*(sin((float)zxcv2/2.0))*(sin((float)zxcv2/2.0));
    if((TMP_ORTODROMA2)*(2.0/1.0*atan2(sqrt((float)some),sqrt(1.0-(float)some)))<0){
        return 0;
    }
    return (TMP_ORTODROMA2)*(2.0/1.0*atan2(sqrt((float)some),sqrt(1.0-(float)some)));

}
//=========================================
void wczytaj(int n, punkt *tab){
    int i=0;
    float tmp1,tmp2;
    string znak;
    do{

        cin>>tab[i].kod;
        if(tab[i].kod.length()>3 || tab[i].kod.length()<3){
            //error
        }
        cin>>tmp1;
        cin>>tmp2;
        tmp2=((float)_RAD*(float)tmp2);
        cin>>znak;
        if(!(znak=="S" || znak=="N" || znak=="W" || znak=="S")){
            // blad
        }
        tab[i].szerokosc=((float)tmp1+((float)tmp2/100));
        if(znak=="S"){
            tab[i].szerokosc=((-1)*((float)tmp1+(tmp2/100)));
        }else tab[i].szerokosc=((float)tmp1+((float)tmp2/100));

        cin>>tmp1;
        cin>>tmp2;
        tmp2=(_RAD*(float)tmp2);
        cin>>znak;
        tab[i].dlugosc=((float)tmp1+((float)tmp2/100));
        if(znak=="W"){
            tab[i].dlugosc=((-1)*((float)tmp1+((float)tmp2/100)));
        }else tab[i].dlugosc=((float)tmp1+((float)tmp2/100));

        i++;
    }while(i<n);
}
//=========================================
inline string abc(string a,string b){
    if(a<b) return a+" "+b;
    else return b+" "+a;
}
//=========================================
inline float brut_force(punkt *tab,int n){
        int i=0;
        int j=0;
        double min = 2147483646;
        string s1="";
        string s2="";
        while(i<n){
            while(j<n){
                if(ortodroma(tab[i],tab[j])<0){
                    return 0;
                }

                if(ortodroma(tab[i],tab[j])<min){
                    min = ortodroma(tab[i],tab[j]);
                    s1=tab[i].kod;
                    s2=tab[j].kod;
                }
                j++;
            }
            i++;
        }
        return min;
}
//=========================================
inline bool Xwedlug (const punkt & a, const punkt & b) {
    bool t1= !(a.szerokosc >= b.szerokosc);
    bool t2= !(a.szerokosc != b.szerokosc);
    bool t3= a.dlugosc < b.dlugosc;
    bool r = t1 || t2 && t3;
    return r;
}
//=========================================
inline bool Ywedlug (const punkt & a, const punkt & b) {
    bool t=true;
    bool f=false;
    if(a.dlugosc < b.dlugosc)
        return t;
    else return f;
}
//=========================================
inline void odleglosc(const punkt & a, const punkt & b) {
    double dist = ortodroma(a,b);
    if (dist < mindist)
        mindist = dist,  result.first = a.kod,  result.second = b.kod;
}
//=========================================
void rec (punkt *_punkt_tab,int left_index, int right_index,int n) {
    if (right_index - left_index <= 3) {
        for (int i=left_index; i<=right_index; ++i)
            for (int j=i+1; j<=right_index; ++j)
                odleglosc(_punkt_tab[i], _punkt_tab[j]);
        sort(_punkt_tab+left_index, _punkt_tab+right_index+1, &Ywedlug);
        return;
    }
    int mid_index;
    mid_index = (left_index+right_index)/2;
    float midx = _punkt_tab[mid_index].szerokosc;
    rec(_punkt_tab,left_index,mid_index,n);
    rec(_punkt_tab,mid_index+1, right_index,n);
    static punkt _pomocnicza_tab[WARTOSC_POM];
    merge(_punkt_tab+left_index, _punkt_tab+mid_index+1, _punkt_tab+mid_index+1,
          _punkt_tab+right_index+1, _pomocnicza_tab, &Ywedlug);
    copy (_pomocnicza_tab, _pomocnicza_tab+right_index-left_index+1, _punkt_tab+left_index);

    int xxx = 0;
    for (int i=left_index; i<=right_index; i=i+1)
        if (abs (_punkt_tab[i].szerokosc - midx) < mindist) {
            for (int j=xxx-1; j>=0 && _punkt_tab[i].dlugosc - _pomocnicza_tab[j].dlugosc < mindist; --j)
                odleglosc(_punkt_tab[i], _pomocnicza_tab[j]);
            _pomocnicza_tab[xxx++] = _punkt_tab[i];
        }
}
//=========================================
