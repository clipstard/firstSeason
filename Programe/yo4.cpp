#include <iostream>
#include <string.h>

using namespace std;
class cladire{

public:
char adresa[20];
int sala;
int buget;
    cladire(){
    strcpy(adresa,"chisinau");
    sala=1;
    buget=1000;
    }
    cladire(char *a,int s, int b){
    strcpy(adresa,a);
    sala=s;
    buget=b;
    }
    cladire(cladire &a){
    strcpy(adresa,a.adresa);
    sala=a.sala;
    buget=a.buget;
    }
    void Afisare(){
   // cout<<"\t\t\tDatele despre cladire\n";
    cout<<"Adresa: "<<adresa<<endl;
    cout<<"Nr de sali: "<<sala<<endl;
    cout<<"Bugetul institutiei :"<<buget<<" lei"<<endl;
    }
    void Init(){

    cout<<"Dati Adresa cladirii: ";       	cin>>adresa;
    cout<<"Cite sali are cladirea: ";     	cin>>sala;
    cout<<"Care este bugetul cladirii: ";   cin>>buget;
    }
   cladire& operator=(cladire &a){
    	strcpy(adresa,a.adresa);
    	sala=a.sala;
    	buget=a.buget;
    	return *this;
	}
};
class prescolar:public cladire{
int ani;
char denumire[20];
public:
    prescolar(){
    ani=3;
    strcpy(denumire,"gradinita");
    }
    prescolar(char *a,int s, int b, int an, char *nn):cladire(a,s,b){
    ani=an;
    strcpy(denumire,nn);
    }
    prescolar(prescolar &ap,char *a,int s,int b):cladire(a,s,b){
    ani=ap.ani;
    strcpy(denumire,ap.denumire);
    }
    void Afisare(){
    cladire::Afisare();
  //  cout<<"\t\tDate despre institutie prescolara:\n";
    cout<<"\tInstitutia prescolara: "<<denumire<<endl;
    cout<<"\tDurata: "<<ani<<endl;
    }
    void Init(){
    cladire::Init();
    cout<<"Dati numele institutiei prescolare: "; cin>>denumire;
    cout<<"Dati durata studiilor: ";              cin>>ani;
    }
       prescolar operator=(prescolar &c){
    	strcpy(denumire,c.denumire);
    	ani=c.ani;
    	strcpy(adresa,c.adresa);
    	sala=c.sala;
    	buget=c.buget;
    	return *this;
	}
};
class medie:public cladire{
int absolvit;
char denumire[20];
public:
    medie(){
    absolvit=2015;
    strcpy(denumire,"Scoala medie");
    }
    medie(char *a,int s, int b,int ab,char *d):cladire(a,s,b){
    strcpy(denumire,d);
    absolvit=ab;
    }
    medie(medie &A,char *a,int s,int b):cladire(a,s,b){
    strcpy(denumire,A.denumire);
    absolvit=A.absolvit;
    }
    void Afisare(){
    cladire::Afisare();
  //     cout<<"\t\tDate despre institutie medie:\n";
    cout<<"\tScoala medie: "<<denumire;
    cout<<endl<<"\tAbsolvit in anul: "<<absolvit<<endl;
    }
    void Init(){
    cladire::Init();
    cout<<"Dati denumirea scolii: ";  cin>>denumire;
    cout<<"Absolvit in anul: ";       cin>>absolvit;
    }
   medie& operator=(medie &c){
    	strcpy(denumire,c.denumire);
    	absolvit=c.absolvit;
    	strcpy(adresa,c.adresa);
    	sala=c.sala;
    	buget=c.buget;
    	return *this;
	}
};
class superioara:public cladire{
int ciclu;
char nume[20];
char facultate[20];
public:
    superioara(){
        ciclu=1;
        strcpy(nume,"UTM");
        strcpy(facultate,"FCIM");
    }
    superioara(char *a,int s, int b,int c,char *n,char *f):cladire(a,s,b){
        ciclu=c;
        strcpy(nume,n);
        strcpy(facultate,f);
    }
    superioara(superioara &A,char *a,int s,int b):cladire(a,s,b){
        ciclu=A.ciclu;
        strcpy(nume,A.nume);
        strcpy(facultate,A.facultate);
    }
    void Afisare(){
    cladire::Afisare();
 //      cout<<"\t\tDate despre institutie superioara:\n";
    cout<<"\tUniversitatea :"<<nume;
    cout<<endl<<"\tFacultatea :"<<facultate;
    cout<<endl<<"\tAnul :"<<ciclu;
    cout<<endl;
    }
    void Init(){
    cladire::Init();
    cout<<"Numele universitatii :";   cin>>nume;
    cout<<"Facultatea :"; cin>>facultate;
    cout<<"Anul :"; cin>>ciclu;
    }
       superioara operator=(superioara &c){
    	strcpy(nume,c.nume);
    	strcpy(facultate,c.facultate);
    	ciclu=c.ciclu;
    	strcpy(adresa,c.adresa);
    	sala=c.sala;
    	buget=c.buget;
    	return *this;
	}
};
int main(){
    prescolar p1("Ismail 10",6,24000,3,"Licurici");
    prescolar p2;
  //  p2.Init();
    cout<<endl;
    p1.Afisare();
    cout<<endl;
    p2.Afisare();
    cout<<endl;
    medie m1("Nicolae Titulescu 18",52,154000,2012,"Iulia Hasdeu");
    medie m2;
   // m2.Init();
    cout<<endl;
    m1.Afisare();
    m2.Afisare();
    superioara s1("Studentilor 9/1",112,1154000,2,"UTM","CIM");
    superioara s2;
  	//s2.Init();
    cout<<endl;
    s1.Afisare();
    cout<<endl;
    s2.Afisare();
    medie m3(m1);
    cout<<endl;
    m3.Afisare();
    cout<<"\n\n";
    prescolar p3(p1);
    cout<<endl;
    p3.Afisare();
   cladire c1("Independentei 10/2",15,11000);
   cladire c2;
   c2=c1;
   cout<<endl;
   c1.Afisare();
   cout<<endl;
   c2.Afisare();
   cout<<endl;
   medie m4=m1;
   m4.Afisare();
return 0;
}

