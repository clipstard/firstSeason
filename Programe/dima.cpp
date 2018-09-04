#include <iostream>
#include <math.h>
#include <string.h>
#define Endl endl

using namespace std;

class Date{
int an,luna,zi;
    public:
Date(int a, int b, int c){
an=a;
luna=b;
zi=c;
}
Date(){
    an=0;
    luna=0;
    zi=0;
}


Date operator +(const Date &a){
    Date temp;
temp.an=an+a.an;
temp.luna=luna+a.luna;
temp.zi=zi+a.zi;
return temp;

}
Date operator -(const Date &a){
    Date temp;
temp.an=an-a.an;
temp.luna=luna-a.luna;
temp.zi=zi-a.zi;
return temp;

}
Date& operator =(const Date &a){
an=a.an;
luna=a.luna;
zi=a.zi;
return *this;
}
/*int operator ++(){
    zi++;
if(zi>31){
    zi-=31;
    luna++;
}
if(luna>12){
    luna-=12;
    an++;
}
return (an,luna,zi);
}*/
void Afisare(){

    cout<<"\n Data:"<<an<<" "<<luna<<" "<<zi;

}
void Citire(){

cout<<"Introduceti Data :"<<endl;
cout<<"Dati anul: "; cin>>an;
cout<<"Dati luna: "; cin>>luna;
cout<<"Dati ziua: "; cin>>zi;
}
//friend int operator++(Date &x);
//friend int operator--(Date &x);
//friend Date operator (Date a)++;
//friend Operatie operator--(Operatie a);
Date& operator++();
Date operator++(int);
};

Date& Date::operator ++(){
zi++;
if(zi>31){
    zi-=31;
    luna++;
}
if(luna>12){
    luna-=12;
    an++;
}
return *this;
}
Date Date::operator++(int){
Date temp(an,luna,zi);
++(*this);
return temp;
}
/*int operator --(Date &x){
x.zi--;
if(x.zi<1){
    x.zi+=31;
    x.luna--;
}
if(x.luna<1){
    x.luna+=12;
    x.an--;
}
return (x.an,x.luna,x.zi);
}*/
int main(){
Date d1;
d1.Citire();
d1.Afisare();
Date d2(1996,5,21);
Date d3;
d3=d2+d1;
d3.Afisare();
//++d3;
//++d3;
++d3;
d3.Afisare();
d3++;
//--d3;
d3.Afisare();
return 0;
}

