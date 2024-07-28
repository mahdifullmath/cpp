#include <iostream>

using namespace std;
int pow(int x,int i){
    int y=1;
    for (int j=1;j<=i;j++){
        y=y*x;
    }

    return y;
}
int main()
{
    unsigned long int n;
    cin>>n;
    unsigned long int bin=0;
    char biner[100];
    unsigned int i=0;
    for (;n>0;i++){
        biner[i]=n%2+48;
        bin=n%2*pow (10,i)+bin;

        n=n/2;

    }
    biner[i]='\0';
    char binergood[100];
    i=i-1;
    unsigned int x=i;
    for (unsigned int j=0;j<=x;){
        binergood[j]=biner[i];

        j++;
        i--;
    }
    binergood[x+1]='\0';
    cout <<endl<<bin<< endl<<binergood;
    return 0;
}
