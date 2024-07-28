#include <iostream>
#include<math.h>
using namespace std;
unsigned long long fak(int i,int k){
    if (k<0)
        k=-k;
    unsigned long long j=1;
    for (int s=i;s>k;s--){
        j=j*s;
    }
    return j;
}
int maxi (int a,int b){
    if(a>b)
        return a;
    else
        return b;

}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int t=x-n;
 /*   int a;
    a= fak (maxi(n,t),(abs(x-n)));
    int b=fak (maxi(n,y),(abs(y-n)));
    int c=a*b;
    cout<<c;*/
    int s=0;
    long long e=1;
    int j,i;
    i=1;
    for (;i<=t+1 ;i++){
        j=0;
        for( ;j<=i&&j<=y;j++){
            s=s+1;
        }
      }
    cout<<fak (s,s-n+1);
    return 0;
}
