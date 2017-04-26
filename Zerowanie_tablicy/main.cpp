#include <iostream>

using namespace std;

void utworz(bool **&tab,int n,int m){
    int i;
    tab = new bool *[n];
    for(i =0;i<n;i++)
    {
       tab[i]= new bool[m];
    }

    for(i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>tab[i][j];
        }
    }
}

void zmien(bool **tab,int x, int y, int n, int m){
   if(x>=0 && x<=n-1 && y>=0 && y<=m-1 ) tab[x][y]==0?tab[x][y]=1:tab[x][y]=0;
   if(x>=0 && x<=n-1 && y-1>=0 && y-1<=m-1 )tab[x][y-1]==0?tab[x][y-1]=1:tab[x][y-1]=0;
   if(x>=0 && x<=n-1 && y+1>=0 && y+1<=m-1 ) tab[x][y+1]==0?tab[x][y+1]=1:tab[x][y+1]=0;
   if(x+1>=0 && x+1<=n-1 && y>=0 && y<=m-1 ) tab[x+1][y]==0?tab[x+1][y]=1:tab[x+1][y]=0;
   if(x-1>=0 && x-1<=n-1 && y>=0 && y<=m-1 ) tab[x-1][y]==0?tab[x-1][y]=1:tab[x-1][y]=0;
}


void zwolnij(bool **tab,int size){
    int i;
    for( i=0;i<size;i++){
        delete [] tab[i];
    }
    delete [] tab;
}

int main()
{

    int n,m;
    cin>>n>>m;
    bool **tab;

   utworz(tab,n,m);
   int c=0;
   for(int i=0;i<n-1;i++){
       for(int j=0;j<m;j++){
           if(tab[i][j]==1){
               zmien(tab,i+1,j,n,m);
               c++;
           }
       }
   }
   bool flags = false;
   for(int i=0;i<m;i++){
       if(tab[n-1][i]==1){
          flags = true;

       }
   }
   if(flags) cout<<"niemozliwe"; else cout<<c;
   zwolnij(tab,n);
    return 0;
}

