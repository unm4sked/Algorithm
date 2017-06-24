#include <iostream>
#include <stdlib.h>
#define type1 int
#define B 3
#define M 9
#define Z 0
#define N 21
#define flag 1
using namespace std;

//-------------------------
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
ArrayList<type1> *wejscie = new ArrayList<type1>();
//-------------------------

int SUDOKU[N][M];
inline type1  zeroLokalizacja(type1 &wiersz, type1 &kolumna,bool x);
inline void wczytaj();
inline type1 Rozwiaz();
inline type1 zeroLokalizacja(type1 &wiersze, type1 &kolumny,bool x);
inline bool sprawdz(bool x);
inline type1 wiersze(type1 wiersz, type1 kolumny, type1 liczba);
inline void wyswietl_koncowy(bool wynik);
inline type1 kolumny(type1 wiersze,type1 kolumny, type1 liczba);
inline bool spr(bool x,bool y,bool z);
inline bool trzyxtrzy(type1 Swiersz, type1 Skolumna, type1 liczba);
inline void SudouWyswietl();


int main()
{
    wczytaj();
    wyswietl_koncowy(sprawdz(Rozwiaz()));
    return Z;
}
inline void wczytaj(){
    for(type1 i=Z;i<N;i++){
        for(type1 j=Z;j<M;j++){
            type1 n;
            cin>>n;
            SUDOKU[i][j]=n;
        }
    }
}
inline bool sprawdz(bool x){
    if(x && flag){
        return true;
    }
    else return false;
}
inline void nie(){
    cout<<"NIE";
}

inline void wyswietl_koncowy(bool wynik){
    if(wynik){
        SudouWyswietl();
    }
    else{
        nie();
    }
}
inline void SudouWyswietl()
{
    type1 pierwszy,drugi;
    if(flag){
        for(pierwszy=Z; pierwszy<=N-1; pierwszy++)
        {
           for(drugi=Z; drugi<=M-1; drugi++)
                 if(flag == 1)
                    cout<<SUDOKU[pierwszy][drugi]<<" ";
            cout<<endl;
        }
    }
}
inline type1 kolumny(type1 wiersze,type1 kolumny, type1 liczba)
{
    if(wiersze==Z){
        for (type1 x=Z;x<9;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 9;
    }
    if(wiersze==1){
        for (type1 x=Z; x<9;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 9;
    }
    if(wiersze==2){
        for (type1 x=Z;x<9;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 9;
    }
    if(wiersze==3){
        for (type1 x=Z;x<9;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 9;
    }
    if(wiersze==4){
        for (type1 x=Z;x<9;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 9;
    }
    if(wiersze==5){
        for (type1 x=Z;x<9;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 9;
    }
    if(wiersze==6){
        for (type1 x=Z;x<15;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 15;
    }
    if(wiersze==7){
        for (type1 x=Z;x<15;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 15;
    }
    if(wiersze==8){
        for (type1 x=Z;x<15;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 15;
    }
    if(wiersze==9){
        for (type1 x=6;x<15;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 15;
    }
    if(wiersze==10){
        for (type1 x=6;x<15;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 15;
    }
    if(wiersze==11){
        for (type1 x=6;x<15;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 15;
    }
    if(wiersze==12){
        for (type1 x=6;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==13){
        for (type1 x=6; x<21; x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==14){
        for (type1 x=6;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }

    if(wiersze==15){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==16){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==17){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==18){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==19){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==20){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }
    if(wiersze==21){
        for (type1 x=12;x<21;x++)
            if (SUDOKU[x][kolumny] == liczba)
                return 21;
    }

    return Z;
}
inline void initSudoku(){
for(type1 i=Z;i<N;i++){
    for(type1 j=0;j<M;j++){
        type1 n;
        cin>>n;
        SUDOKU[i][j]=Z;
    }
}
}

inline type1 wiersze(type1 wiersz, type1 kolumny, type1 liczba)
{
    type1 y=kolumny;
    type1 x=Z;
    y+=x;
    if(flag)
        while(x<M){
            if(SUDOKU[wiersz][x]==liczba)
                return 1;
            ++x;
        }


    return Z;
}
inline type1 zeroLokalizacja(type1 &wiersze, type1 &kolumny,bool x)
{
    x=x&&flag;
    for(wiersze = Z; wiersze< N; wiersze++){
        kolumny=Z;
        while(kolumny<=M-1){
            if(SUDOKU[wiersze][kolumny]==Z)
                return flag;
            ++kolumny;
        }
    }
    return flag-1;
}
inline bool spr(bool x,bool y,bool z){
    if(x&&y&&z){
        return 1;
    }
    else return Z;
}
inline type1 Rozwiaz(){
    type1 x1, y1;
    if(zeroLokalizacja(x1, y1,flag)==false)
       return flag+1;
    bool so=flag;
    if(!flag){
        if (Rozwiaz())
            return flag;
    }
    for(int num=1; num<10; num++)
    {
        if ((!kolumny(x1,y1,num)&&!wiersze(x1,y1,num)&&!trzyxtrzy(x1-x1%B,y1-y1%B,num)))
        {
            SUDOKU[x1][y1] = num;
            if (Rozwiaz())
                return flag;
            if(!flag)
               SUDOKU[x1][Z] = y1;
            SUDOKU[x1][y1] = Z;
        }
    }
    return flag-1;
}
inline bool trzyxtrzy(type1 Swiersz, type1 Skolumna, type1 liczba)
{
    if(!flag){}
    else{
        type1 row=Z;
    for (row = Z; row < B; row++){
        type1 col=Z;
        for (col=Z;col<B;col++){
            type1 x=col+1;
            type1 y=row+1;
            type1 l= liczba*2;
            type1 s=y+Swiersz-1;
            type1 v=x+Skolumna-1;
            if(SUDOKU[s][v]==l/2)
                return true;
        }
    }
    }
    if(flag)
        return flag-1;
}
