#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
void bubble(int arr[],int length){
int aux,i=0,j=0;
for(j=0;j<length;j++){
for(i=1;i<length;i++){

if(arr[i-1]<arr[i]){
    aux=arr[i-1];
    arr[i-1]=arr[i];
    arr[i]=aux;
}
}
}
}

int main(){
    int diapazon1,diapazon2,file,f[200];
    cout<<"\nDati diapazonul cifrelor in fisiere \t.";
    cout<<endl<<"\tPentru fisierul unu: "; cin>>diapazon1;
    cout<<"\tPentru fisierul doi: "; cin>>diapazon2;

ofstream outfile;
int v3[200]={0};

outfile.open("data1.dat");
file=1;
for(int i=0;i<100;i++){
    outfile<<rand()%diapazon1+1<<endl;
}

outfile.close();
outfile.open("data2.dat");
file=2;
for(int i=0;i<100;i++){
  outfile<<rand()%diapazon2+1<<endl;
}
outfile.close();
ifstream infile;
infile.open("data1.dat");
ifstream inf;
inf.open("data2.dat");
for(int i=0;i<100;i++){
    infile>>v3[i];
    v3[i]*=100;
    v3[i]+=1;
    inf>>v3[i+100];
    v3[i+100]*=100;
    v3[i+100]+=2;
}
bubble(v3,200);
infile.close();
inf.close();
system("pause");
ofstream outfile2;
outfile2.open("result.dat");
for(int i=0;i<200;i++){
        if(v3[i]%2==0){
                v3[i]-=2;
                v3[i]/=100;
            outfile2<<v3[i]<<" Din fisierul 2"<<endl;
                cout<<v3[i]<<" Din fisierul 2"<<endl;
        }else{
            v3[i]-=1;
            v3[i]/=100;
             outfile2<<v3[i]<<" Din fisierul 1"<<endl;
              cout<<v3[i]<<" Din fisierul 1"<<endl;
        }

}
cerr<<"Fisier creat";
return 0;
}
