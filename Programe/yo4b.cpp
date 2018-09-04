#include <iostream>
#include <string.h>
#define q endl

using namespace std;

class motor{
protected:
    char *fp=new char[20];
    char *tip=new char[20];
    int putere;
public:
    motor(){
    strcpy(fp,"Maybach");
    strcpy(tip,"Diesel");
    putere=1500;
    }
    motor(char *firma,char *t,int p){
    strcpy(fp,firma);
    strcpy(tip,t);
    putere=p;
    }
    virtual void init()=0;
    virtual void show()=0;
    void cfp(char *firma){
    strcpy(fp,firma);
    }
    void ct(char *t){
    strcpy(tip,t);
    }
    void cp(int p){
    putere=p;
    }
    ~motor(){};
};
class corabie:public motor{
protected:
    int capacitate;
    int masurator;
    char *nume=new char[20];
    char *port=new char[20];
    public:
    corabie(){
    	    strcpy(nume,"Speranta");
    strcpy(port,"Santa-Monica");
    masurator=1000;
    capacitate=225;
	};
    corabie(char *firma,char *t,int p):motor(firma,t,p){
    strcpy(nume,"Speranta");
    strcpy(port,"Santa-Monica");
    masurator=1000;
    capacitate=225;
    }
    corabie(char *n,char *po,int c,int m,char *firma,char *t,int p):motor(firma,t,p){
    strcpy(nume,n);
    strcpy(port,po);
    masurator=m;
    capacitate=c;

    }
     void init(){
    cout<<"\nDati parametrii motorului\n";
    cout<<"Dati firma producatoare: "; cin>>fp;
    cout<<"Dati tipul motorului: "; cin>>tip;
    cout<<"Cai putere :"; cin>>putere;
    cout<<"\nDati parametrii corabiei\n";
    cout<<"Dati numele: "; cin>>nume;
    cout<<"Dati portul nasterii: "; cin>>port;
    cout<<"Dati masuratorul apei: "; cin>>masurator;
    cout<<"Dati capacitatea: "; cin>>capacitate;
    }
    void show(){
    cout<<"\nParametrii motorului\n";
    cout<<"Firma producatoare: "<<fp<<q;
    cout<<"Tipul motorului: "<<tip<<q;
    cout<<"Cai putere :"<<putere<<q;
    cout<<"\nParametrii corabiei\n";
    cout<<"Numele: "<<nume<<q;
    cout<<"Portul nasterii: "<<port<<q;
    cout<<"Masuratorul apei: "<<masurator<<q;
    cout<<"Capacitatea: "<<capacitate<<"Oameni"<<q;
    }
    ~corabie(){
	};
};
class vapor:public corabie{
int viteza;
int lungime;
public:
	vapor(){
	}
    vapor(char *n,char *po,int c,int m,char *firma,char *t,int p):corabie(n,po,c,m,firma,t,p){
	viteza=10;
	lungime=100;
	};
    vapor(int v, int l,char *n,char *po,int c,int m,char *firma,char *t,int p):corabie(n,po,c,m,firma,t,p){
    	viteza=v;
    	lungime=l;
	}
	void init(){
		corabie::init();
		    cout<<"\nDati parametrii vaporului\n";
		cout<<"Dati viteza vaporului: "; cin>>viteza;
		cout<<"Dati lungimea vaporului: "; cin>>lungime;
	}
	void show(){
		corabie::show();
		cout<<"\nParametri vaporului\n";
		cout<<"Viteza: "<<viteza<<q;
		cout<<"Lungimea: "<<lungime<<"metri"<<q;
		cout<<"###############################";
	}
	~vapor(){};
};

int main(){
	corabie c1;
	c1.show();
cout<<q<<"########################################";
	vapor v1;
	v1.init();
	vapor v2(20,3000,"Titanic","San-Torino",2500,1300,"Mitsubishi","diesel",13000);
	v1.show();
	v2.show();
	return 0;
}
