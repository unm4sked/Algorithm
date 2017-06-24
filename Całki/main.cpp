#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#define LICZNIK 100000000
using namespace std;

double fxx(int stopien,double* st,double x){
    double fx=0.0;
    for(int j=0;j<stopien;j++){
        fx+=(double)pow(x,j)*(double)(st[j]);
    }
    return fx*1.0;
}

double trapezy(double *tab,double xp,double xk,int stopien){
    const int N=1000;
    double s=0.0;
    double dx = ((double)xk - (double)xp / N*1.0);
    //cout<<"[";
    //for(int i=0;i<stopien;i++){
    //    cout<<tab[i]<<", ";
    //}
    //cout<<"]"<<endl;
    for(int i = 1; i < N; i++)
        s +=(double)fxx(stopien,tab,(double)xp + i * (double)dx);
     s = (s + ((double)fxx(stopien,tab,(double)xp) + (double)fxx(stopien,tab,(double)xk)) / 2) * (double)dx;
     //cout<<"trapezy: "<<s<<endl;
     return s/1.0;
}

double Eexp(double a , double prawa, double lewa){
    double x;
    double y;
    int k=0;
    for(int i=0;i<LICZNIK;i++){
        x=(double)lewa+((double)rand()/RAND_MAX)*(prawa-lewa);
        y=(double)rand()/RAND_MAX;
        if(exp((-1)*a*pow(x,2))>y)
            k++;
    }
    double pole=(double)prawa-lewa;
    //cout<<k<<endl;
    //cout<<pole<<endl;
    return (double)((double)k/(double)LICZNIK)*(double)pole/1.0;
}
double trap_exp(double a , double xk, double xp){
    const int N=1000;
    double s=0.0;
    double dx = ((double)xk - (double)xp) / N*1.0;
    for(int i = 1; i < N; i++)
        s += (double)exp(-a*pow(xp + i * (double)dx,2));
     s = (s + ((double)exp(-a*pow((double)xp,2)) + (double)exp(-a*pow((double)xk,2))) / 2) * (double)dx;

     return s/1.0;
}

double Wielomian(double* st,double lewa,double prawa,int stopien){
    //cout<<"Wszedl fo f"<<endl;
    double x;
    double y;
    int k=0;
    double sx=0;
    //cout<<st[0]<<endl;
    for(int i=0;i<LICZNIK;i++){
        x=((double)rand()*(prawa-lewa))/RAND_MAX+lewa;
        y=rand()%200-100;
        double fx=0;

        fx=fxx(stopien,st,x);
        sx+=fx;
        if(fx>y)
            k++;
    }
    cout<<"k: "<<k<<endl;
    //cout<<fixed<<"1 sx: "<<sx<<endl;
    double pole=prawa-lewa*200;
    sx=sx*pole/LICZNIK;
    //cout<<fixed<<"2 sx: "<<sx<<endl;

    double xcv = (double)((double)k/(double)LICZNIK)*(double)pole;
    //cout<<"w fun: "<<xcv<<endl;
    return sx;
}

double wielomiany_monte(double* st,double xp,double xk,int stopien){
    double s  = 0;
    double  dx = xk - xp;
    for(int i = 1; i <= LICZNIK; i++)
        s += fxx(stopien,st,xp+((double)rand()/(double)(RAND_MAX)*dx));
      s = dx * s / LICZNIK;

    return s;
}


int main()
{

    vector<double> finish;
    srand(time(NULL));
    for(int i=3;i<43;i++) rand();
    int n;
    cin>>n;
    string znak;
    int stopien;
    double lewa;
    double prawa;
    double a;
    double wynik;
    for(int i=0;i<n;i++){
        cin>>znak;
        if(znak=="E"){
            cin>>a;
            cin>>lewa;
            cin>>prawa;
            wynik=(double)trap_exp(a,(double)prawa,(double)lewa)/1.0;

            finish.push_back((double)wynik);
        }
        else if(znak=="C"){
            cin>>stopien;
            double *st = new double[stopien];
            for(int j=0;j<stopien;j++){
                double tmp;
                cin>>tmp;
                st[j]=tmp;
            }
            cin>>lewa;
            cin>>prawa;

            wynik=(double)wielomiany_monte(st,(double)lewa,(double)prawa,stopien);

            finish.push_back((double)wynik);
            delete [] st;
        }
    }
    vector<double>::iterator it = finish.begin();
    for(it = finish.begin(); it!= finish.end(); it++ ){
        double tmp=*it;
        tmp = (double)(round(tmp*100)/(double)100);
        if(!tmp)
            cout<<0<<endl;
        else
            cout<<tmp<<endl;
    }


    return 0;
}
