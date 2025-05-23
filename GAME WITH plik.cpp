#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
    int i=0;
    int z;
    string a;
    fstream tlum;
//GRAAA
    void zapis();
    void odczyt();
    void gra();
    void wyjscie();
//GRAAA
int main(){
    while(true){
        cout<<"1:Add into list \n2:Show list \n3:Start \n4:End\n>";
        z=getch();
        switch(z){
            case '1':zapis();     break;
            case '2':odczyt();    break;
            case '3':gra();       break;
            case '4':wyjscie();   break;
        };
    }
return(0);
}

void zapis(){
    cout<<"Hello,";
    cout<<"\n Enter word and translation\n>";


    tlum.open("dane.txt",ios::out|ios::app);

    while(true){
    if(i>0){
        system("cls");
        cout<<"Enter 'c' to end\n";
        cout<<"Enter word\n> ";
        }
    getline(cin,a);
        if(a=="c"){break;}
    tlum<<a<<endl;
    cout<<"Enter translation\n> ";
    getline(cin,a);
    tlum<<a<<endl;
    i++;
    }
    tlum.close();
    Sleep(200);



    }
void odczyt(){
    system("cls");
    tlum.open("dane.txt",ios::in);
    if(tlum.good()==false){
        cout<<"No file, insert data first";
        exit(0);}
    int nr=1;
    string P,A;
    while(getline(tlum,a)){
        int igla;
        igla++;
        cout<<igla<<": "<<a<<endl;
        switch(nr){
            case 1:P=a;    break;
            case 2:A=a;    break;
            }
         nr++;
         if (nr==3)nr=1;
    }
    tlum.close();
    cout<<"\n~~~~~~~~~~~~~~~~~~~~\n\n";
}
void gra(){
    tlum.open("dane.txt",ios::in);
    if(tlum.good()==false){
        cout<<"No file, insert data";
        exit(0);}
    int nr=1;
    string P,A;
    string odpowiedz;
    while(getline(tlum,a)){
        switch(nr){
            case 1:P=a;    break;
            case 2:A=a;    break;
            }
         nr++;
         if (nr==3)nr=1;
         if (nr==1){
         cout<<nr<<" Word: "<<P<<"\n Translation ";
         cin>>odpowiedz;
            if(odpowiedz==A){
                cout<<"NICE! \n";
            } else {cout<<"Wrong. Translation.. "<<A<<endl;}
         }
    }
    tlum.close();
    cout<<"\nThat will be all, thank you.\n\a";
}
void wyjscie(){
exit(0);
    }
