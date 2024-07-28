#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int sn[5];
    char  *n[5];
    for (int i=0;i<5;i++){
        cin>>sn[i];
        cin>>*n[i];
    }
    char b [20];
    cin>>b;
    for (int i=0;i<5;i++){
        char key[10] ;
        strncpy (key,n[i],3);
        if (b==key)
            cout<<sn[i]<<endl<<n[i];
    }
    return 0;
}
