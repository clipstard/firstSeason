#include <iostream>
#include <time.h>

using namespace std;

template <class tip> class vector{
protected:
    tip *e;
    tip k;
    int dim;
public:
    vector(){
e=new tip;
    }
    void init(int d){
        dim=d;
    e=new tip[dim];
    cout<<"dati elementele tabloului"<<endl;
    for(int i=0;i<dim;i++){
        cout<<"["<<i+1<<"]"; cin>>e[i];
    }
    }
    ~vector(){};
    void cauta(){
    cout<<"introduceti elementul de cautat; "<<endl;
    cin>>k;
    int flag=1;
    int i;
    for(i=0;i<dim;i++){
        if(e[i]==k){
flag=0;
break;
        }
    }
    if(flag){
        cout<<"asa element nu a fost gasit\n"<<endl;
    }else{
        cout<<"A fost gasit"<<endl;;
        cout<<"Elementul este al "<<i+1<<"-lea"<<endl;
    }
    }
void afisare(){
    cout<<"elementele tabloului dupa numarul de ordine sunt:"<<endl;
    for(int i=0;i<dim;i++){
        cout<</*"["<<i+1<<"]: "<<*/e[i]<<",";

    }
    cout<<endl;
}
};
int main(){
vector <int>a;
a.init(10);
a.cauta();
a.afisare();
vector <float>b;
b.init(5);
b.afisare();
b.cauta();
return 0;
}
