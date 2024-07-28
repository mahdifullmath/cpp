#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    int x;
    cin>>n;
    int b;
    cin>>b;
    char m[100];
    int i=0;
    for(;n!=0;i++){
        x=n%b;
        m[i]=x;
        n=n/b;
        if(n==0)
            break;
    }
    for(int j=0;j<=i;){
        if(m[j]<=9&&m[j]>=0){
            m[j]=m[j]+48;
            j++;
        }
        if(m[j]>=10&&m[j]<=26){
            m[j]=m[j]+55;
            j++;
        }
    }
   // cout <<char (0+48)<<endl;
    for(int j=i;j>=0;j--){
        cout <<m[j];
    }
    return 0;
}
