#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
using namespace std;
struct node{
public:
    string value;
    node * next;
    node(){
        next = 0;
    }
};

class stack{
private:
    node *top;
public:
    stack(){top=0;}
    void push(string s){
        node* nowy;
        nowy = new node;
        nowy->value=s;
        nowy->next=NULL;
        if(top!=0)
            nowy->next=top;
        top=nowy;
    }
    string pop(){
        node *tmp;
        if(top!=NULL){
            tmp=top;
            string el = top->value;
            top=top->next;
            delete tmp;
            return el;
        }
        return "";
    }

    string toop(){

        string el=top->value;
        return el;
    }
    bool isEmpty(){
        if(top==NULL)
            return true;
        else return false;
    }
};

class List{
public:
    node * first;

    List(){
        first = 0 ;
    }

    void  dodaj(string x){
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

    bool isEmpty(){
        if(first==NULL)
            return true;
        else return false;
    }
};
struct nodeInt{
public:
    int value;
    nodeInt * next;
    nodeInt(){
        next = 0;
    }
};

class stackInt{
private:
    nodeInt *top;
public:
    stackInt(){top=0;}
    void push(int s){
        nodeInt* nowy;
        nowy = new nodeInt;
        nowy->value=s;
        nowy->next=NULL;
        if(top!=0)
            nowy->next=top;
        top=nowy;
    }
    int pop(){
        nodeInt *tmp;
        if(top!=NULL){
            tmp=top;
            int el = top->value;
            top=top->next;
            delete tmp;
            return el;
        }
        return 0;
    }

    int toop(){

        int el=top->value;
        return el;
    }
    bool isEmpty(){
        if(top==NULL)
            return true;
        else return false;
    }
};
//=====================================
struct nodeChar{
public:
    int value;
    nodeChar * next;
    nodeChar(){
        next = 0;
    }
};

class stackChar{
private:
    nodeChar *top;
public:
    stackChar(){top=0;}
    void push(int s){
        nodeChar* nowy;
        nowy = new nodeChar;
        nowy->value=s;
        nowy->next=NULL;
        if(top!=0)
            nowy->next=top;
        top=nowy;
    }
    int pop(){
        nodeChar *tmp;
        if(top!=NULL){
            tmp=top;
            int el = top->value;
            top=top->next;
            delete tmp;
            return el;
        }
        return 0;
    }

    char toop(){

        int el=top->value;
        return el;
    }
    bool isEmpty(){
        if(top==NULL)
            return true;
        else return false;
    }
};
inline bool isOperator(char x){

    if(x=='m' || x=='d' || x=='+' || x=='*' || x=='~' || x=='/' ||  x=='^')
        return true;
    else return false;
}
inline int p(char s){
    if(s=='^') return 3;
    if(s=='m' || s=='d' || s=='*' || s=='/') return 2;
    if(s=='+' || s=='~') return 1;
    else return 0;
}

inline bool isLeftBraket(char s){
    if(s=='['||s=='('||s=='{')
        return true;
    else return false;
}
inline bool isRightBraket(char s){
    if(s==']'||s==')'||s=='}')
        return true;
    else return false;
}

string postfix(string input){

    string tmp;
    string output="";

    stackChar *st = new stackChar();

    unsigned int i=0;
    while(i<input.length()){
        tmp = "";
        while(input[i]!=' ' && i<input.length()){
            tmp += input[i];
            i++;
        }
        if(isdigit(tmp[0]) || tmp[0]=='-'){
            output+=tmp;
            output+=' ';
        }
        else if(st->isEmpty() && isOperator(tmp[0]))
            st->push(tmp[0]);
        else if(isLeftBraket(tmp[0]))
            st->push(tmp[0]);
        else if(isRightBraket(tmp[0])){
            while(!isLeftBraket(st->toop())){
                output+=st->pop();
                output+=' ';
            }
            st->pop();
        }
        else if(isOperator(tmp[0])){
            while(!st->isEmpty() && p(st->toop())>=p(tmp[0])){
                output+=st->pop();
                output+=' ';
            }
            st->push(tmp[0]);
        }
        i++;
    }
    while(!st->isEmpty()){
        output+=st->pop();
        output+=' ';
    }
    return output;
}
inline bool zgodne(char char1,char char2){
    if(char1 == '{' && char2 =='}')
        return true;
    else if(char1 == '[' && char2 ==']')
        return true;
    else if(char1 == '(' && char2 ==')')
        return true;
    else return false;
}

bool nawiasy_ERROR(string s){
    stackChar *nawiasy = new stackChar();
    int i=0;
    while(s[i]){
        if(isLeftBraket(s[i])){
            nawiasy->push(s[i]);
        }else if(isRightBraket(s[i])){
            if(nawiasy->isEmpty()){
                return true;
            }else{
                if(!zgodne(nawiasy->pop(),s[i])){
                    return true;
                }
            }

        }
        i++;
    }
    if(!nawiasy->isEmpty()) {
        return true;
    }


    delete nawiasy;
    return false;
}

inline bool isNumber(char s)
{
    if(s=='-') return true;
    if(isdigit(s))return true;
    else return false;
}

bool skladnia_ERROR(string s){
    if(isOperator(s[0])) return true;
    if(isOperator(s[s.length()-1])) return true;
    int i=1;
    while(s[i-2]){
        if(s[i]==' '){
            if(isOperator(s[i-1]) && isOperator(s[i+1]))
                return true;
            if(isOperator(s[i-1]) && isRightBraket(s[i+1]))
                return true;
            if(isNumber(s[i-1])  && (isLeftBraket(s[i+1])|| isNumber(s[i+1])))
                return true;
            if(isLeftBraket(s[i-1]) && (isRightBraket(s[i+1])||isOperator(s[i+1])))
                return true;
            if(isRightBraket(s[i-1]) && (isNumber(s[i+1])||isLeftBraket(s[i+1])))
                return true;
        }
        i++;
    }
    return false;


}

int main(){
    int n;
    string test="";
    cin>>n;
    string temp="";
    for(int i=0;i<n;i++){

        cin>>temp;
        test+=temp;
        if(i!=n-1)
            test+=' ';
    }
    if(nawiasy_ERROR(test)){
        cout<<"bledne nawiasy";
        return 0;
    }
    if(skladnia_ERROR(test)){
        cout<<"bledna skladnia";
        return 0;
    }

    string napis = postfix(test);
    stackInt *st =new stackInt();
    int z1=0;
    int z2=0;
    unsigned int i=0;
    while(i<napis.length()){
        string tmp="";
        while(i<napis.length() && napis[i]!=' '){
            tmp+=napis[i];
            i++;
        }
        if((isdigit(tmp[0]) || tmp[0]=='-')){
            st->push(atoi(tmp.c_str()));
        }
        else{
            if(tmp[0]=='*'){
                z1=st->pop();
                z2=st->pop();
                st->push(z1*z2);
            }
            else if(tmp[0]=='+'){
                z1=st->pop();
                z2=st->pop();
                st->push(z1+z2);
            }
            else if(tmp[0]=='~'){
                z1=st->pop();
                z2=st->pop();
                st->push(z2-z1);
            }
            else if(tmp[0]=='m'){
                z1=st->pop();
                if(z1<=0){
                    cout<<"bledne dzialanie";
                    return 0;
                }
                z2=st->pop();
                st->push(z2%z1);
            }
            else if(tmp[0]=='d'){
                z1=st->pop();
                if(z1<=0){
                    cout<<"bledne dzialanie";
                    return 0;
                }
                z2=st->pop();
                st->push(z2/z1);
            }
            else if(tmp[0]=='^'){
                z1=st->pop();
                z2=st->pop();
                if((z1==0 && z2==0) ||z1<0){
                    cout<<"bledne dzialanie";
                    return 0;
                }
                st->push(pow(z2,z1));
            }
        }

        i++;
    }
    cout<<st->toop();
    return 0;
}