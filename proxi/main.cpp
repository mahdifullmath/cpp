#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    char p[21];
    cin.getline(p,21);
    int pro[21];
    int t=0;
    for (;p[t]!='\0';t++){
        pro[t]=p[t]-48;
    }
    int proxi [81][4];
    for (int i=0;i<81;i++){
        for(int j=0;j<4;j++){
            proxi [i][j]=-1;
        }
    }
    int proxy=0;
    int y=t/4;

    for(int k=0,k<81;k++){
        for(int j=0,j<4;j++){
            for
        }
    }
    for (int i=0,j=3,x=y,q=0;i<t&&q<4;i++){

            proxy=proxy*10+pro[i];
            j--;
            x=x-1;
       if (x==0){
        cout<<proxy;
        x=y;
        q++;
        if(q==4){
            break;
        }
        cout<<'.';
        j=3;
        proxy=0;
       }
       else if (proxy>255){
        proxy=proxy/10;
        i--;
        cout<<proxy;
        proxy=0;
        q++;
        if(q==4){
            break;
        }
        cout<<'.';
        j=3;
       }
    }
    return 0;
}
