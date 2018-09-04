#include <iostream>
#include <math.h>
#include <string.h>
#define Endl endl

using namespace std;

class Operatie{
    public:
int km,m,cm,mm;

Operatie(int metri, int centim, int milim){
m=metri;
cm=centim;
mm=milim;
};
Operatie(){
    km=0;
    m=0;
    cm=0;
    mm=0;
};
Operatie& operator =(const Operatie &a){
m=a.m;
cm=a.cm;
mm=a.mm;
return *this;
}
void Egalare(){
if(mm>=10){
    do{
        mm-=10;
        cm++;
    }while(mm>=10);
}
if(cm>=100){
    do{
        cm-=100;
        m++;
    }while(cm>=100);
}
if(m>=1000){
    do{
        m-=1000;
        km+=1;
    }while(m>=1000);
}
}
void Afisare(){
cout<<"\nLungimea finala este : ";
if(!km){
cout<<"\n\t\t\t\t\t\t"<<m<<" metri; "<<cm<<" cm; "<<mm<<" mm\n";
}else{
    cout<<"\n\t\t\t\t\t"<<km<<" km; "<<m<<" metri; "<<cm<<" cm; "<<mm<<" mm";
}
}
void Citire(){
    km=0;
cout<<"Introduceti lungimea :"<<endl;
cout<<"Dati metri: "; cin>>m;
cout<<"\n"<<"Dati cm: "; cin>>cm;
cout<<"\n"<<"Dati mm: "; cin>>mm;
this->Egalare();
}
friend Operatie operator+(Operatie a,Operatie b);
};
Operatie operator +(Operatie a, Operatie b){
    Operatie temp;
temp.m=a.m+b.m;
temp.cm=a.cm+b.cm;
temp.mm=a.mm+b.mm;
temp.Egalare();
return temp;

}
Operatie operator -(const Operatie &a, const Operatie &b){
    Operatie temp;
temp.m=a.m-b.m;
temp.cm=a.cm-b.cm;
temp.mm=a.mm-b.mm;
temp.Egalare();
return temp;

}
Operatie operator *(Operatie a, int z){
    Operatie temp;
temp.km=a.km*z;
temp.m=a.m*z;
temp.cm=a.cm*z;
temp.mm=a.mm*z;
temp.Egalare();
return temp;

}

Operatie operator /(Operatie a, int z){
    Operatie temp,aux;
    if(a.m%z!=0){
        aux.cm=a.m%z;
    }
    if(a.cm%z!=0){
        aux.mm=a.cm%z;
    }
temp.m=a.m/z;
temp.cm=a.cm/z+aux.cm;
temp.mm=a.mm/z+aux.mm;
temp.Egalare();
return temp;

    }

void menu(){
cout<<"\tMENU"<<Endl;
cout<<"1-Adunarea lungimilor"<<endl;
cout<<"2-Scaderea Lungimilor"<<endl;
cout<<"3-Inmultirea lungimilor"<<endl;
cout<<"4-Impartirea lungimilor"<<endl;
cout<<"5-Afisarea lungimilor introduse"<<endl;
cout<<"6-Terminarea programului"<<endl;

}
void Lungimi(Operatie n1,Operatie n2,Operatie n3,Operatie n4){
cout<<"\nLungimea 1 este : ";
if(!n1.km){
cout<<"\t\t"<<n1.m<<" metri; "<<n1.cm<<" cm; "<<n1.mm<<" mm";
}else{
    cout<<"\t\t"<<n1.km<<" km; "<<n1.m<<" metri; "<<n1.cm<<" cm; "<<n1.mm<<" mm";
}
cout<<"\nLungimea 2 este : ";
if(!n2.km){
cout<<"\t\t"<<n2.m<<" metri; "<<n2.cm<<" cm; "<<n2.mm<<" mm";
}else{
    cout<<"\t\t"<<n2.km<<" km; "<<n2.m<<" metri; "<<n2.cm<<" cm; "<<n2.mm<<" mm";
}
cout<<"\nLungimea 3 este : ";
if(!n3.km){
cout<<"\t\t"<<n3.m<<" metri; "<<n3.cm<<" cm; "<<n3.mm<<" mm";
}else{
    cout<<"\t\t"<<n3.km<<" km; "<<n3.m<<" metri; "<<n3.cm<<" cm; "<<n3.mm<<" mm";
}
cout<<"\nLungimea 4 este : ";
if(!n1.km){
cout<<"\t\t"<<n4.m<<" metri; "<<n4.cm<<" cm; "<<n4.mm<<" mm";
}else{
    cout<<"\t\t"<<n4.km<<" km; "<<n4.m<<" metri; "<<n4.cm<<" cm; "<<n4.mm<<" mm";
}
}
int main(){
    int x1=0,x2=0,x3=0,x4=0,x=0;
    int i=-1;
    int y1=0,y2=0,y3=0,y4=0,y=0;
    int terminat=1;
Operatie L1,L2,L3,L4,L5;
Operatie A1,A2;

cout<<"Dati masurarile initiale\n";
cout<<"1 -";
L1.Citire();
cout<<"2 -";
L2.Citire();
cout<<"3 -";
L3.Citire();
cout<<"4 -";
L4.Citire();
while(terminat){
        menu();

        do{
    cin>>i;
}while(i<=0||i>6);

switch(i){
case 1:cout<<"Alegeti lungimile de adaugat (5 pentru adaugarea la existenta)\n";
cin>>x;
while(x<1||x>5){
        cout<<"Gresit : ";
        cin>>x;
}
    cout<<" si\n ";
cin>>y;
switch(x){
case 1:A1=L1;
break;
case 2:A1=L2;
break;
case 3:A1=L3;
break;
case 4:A1=L4;
break;
case 5:A1=L5;
break;
}
while(y<1||y>5){
        cout<<"Gresit : ";
        cin>>y;
}
switch(y){
case 1:A2=L1;
break;
case 2:A2=L2;
break;
case 3:A2=L3;
break;
case 4:A2=L4;
break;
case 5:A2=L5;
break;
}
L5=A1+A2;
cout<<"\t\t\t";
L5.Afisare();
break;
case 2:cout<<"Alegeti lungimile de scazut (5 pentru existenta)\n";
cin>>x;
while(x<1||x>5){
        cout<<"Gresit : ";
        cin>>x;
}
    cout<<" si ";
cin>>y;
switch(x){
case 1:A1=L1;
break;
case 2:A1=L2;
break;
case 3:A1=L3;
break;
case 4:A1=L4;
break;
case 5:A1=L5;
break;
}
while(y<1||y>5){
        cout<<"Gresit : ";
        cin>>y;
}
switch(y){
case 1:A2=L1;
break;
case 2:A2=L2;
break;
case 3:A2=L3;
break;
case 4:A2=L4;
break;
case 5:A2=L5;
break;
}
L5=A1-A2;
L5.Afisare();
break;
case 3:cout<<"Alegeti lungimea de inmultit si multiplicatorul\n";
cin>>x;
while(x<1||x>5){
        cout<<"Gresit : ";
        cin>>x;
}
    cout<<" si ";
cin>>y;
switch(x){
case 1:A1=L1;
break;
case 2:A1=L2;
break;
case 3:A1=L3;
break;
case 4:A1=L4;
break;
case 5:A1=L5;
break;
}
L5=A1*y;
L5.Afisare();
break;
case 4:cout<<"Alegeti lungimea de impartit si fractia\n";
break;
cin>>x;
while(x<1||x>5){
        cout<<"Gresit : ";
        cin>>x;
}
    cout<<" si ";
cin>>y;
switch(x){
case 1:A1=L1;
break;
case 2:A1=L2;
break;
case 3:A1=L3;
break;
case 4:A1=L4;
break;
case 5:A1=L5;
break;
}
L5=A1/y;
L5.Afisare();
break;
case 5:Lungimi(L1,L2,L3,L4);
break;
case 6:terminat=0;
break;
default:cout<<"Nedefinit";
break;
}
}
return 0;
}
