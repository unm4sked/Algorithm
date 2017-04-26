#include <iostream>

using namespace std;



void scal(int *tab, int l, int s, int p,int *pom);
void sortowanie(int *tab,int l, int p,int *pom);
inline int bezwzgledna(int x);
void wyswietl(int *tab, int n);


int main()
{
    int *tab,n;
    int *pom;

      cin>>n;
      tab = new int[n];
      pom = new int[n];

      for(int i = 0;i < n;i++)
        cin>>tab[i];

      sortowanie(tab,0,n-1,pom);
      wyswietl(tab,n);

      return 0;
}

void scal(int *tab, int l, int s, int p,int *pom)
{

  for(int i = l;i<=p; i++)
    pom[i] = tab[i];
  int j = s+1,i = l;
  for(int k = l;k <= p;k++){
  if(i <= s)
    if(j <= p)
         if(pom[j]<pom[i]){
             tab[k] = pom[j];
             ++j;
         }
         else{
             tab[k] = pom[i];
             ++i;
         }
    else{
        tab[k] = pom[i];
        ++i;
    }
  else{
      tab[k] = pom[j];
      ++j;
  }
  }
}
void sortowanie(int *tab,int l, int p,int *pom)
{
  if(p == l) return;
  else {
      int s = (p + l)/2;

      sortowanie(tab, l, s,pom);
      sortowanie(tab, s+1, p,pom);
      scal(tab, l, s, p,pom);
  }
}

inline int bezwzgledna(int x){
    return x>0?x:-x;
}

void wyswietl(int *tab, int n){
    int j = 1;
    bool flaga = 1;
    while(flaga){
    for(int i = 0;i < n-1;i++){
        if(bezwzgledna(tab[i] - tab[i+1]) == j){
            if(flaga)
                cout<<j<<endl;
            flaga = 0;
            cout<<tab[i]<<" "<<tab[i+1]<<endl;
        }
    }

        j++;
    }
}

