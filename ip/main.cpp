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
    int proxy[4];
    for (int i=0;i<4;i++){
       proxy[i]=-1;
    }
    int px=0;
    int y=t/4;
    for(int i=0,j=0;i<4;i++){
        for(int i=0,j=0;j<t&&i<4;j++){
            px=px*10+pro[j]
            if (px>225){
                px=px/10;
                j--;
                break;
            }
        }
        proxy[i]=px;
        px=0;
    }

    return 0;
}
