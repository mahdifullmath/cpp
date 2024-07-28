#include <iostream>

using namespace std;
void mrege(int* mini, int* maxi,int* miniv, int* maxiv,int* miniu, int* maxiu){
    if(*miniv<*miniu){
        *mini=*miniv;
    }
    else {
        *mini=*miniu;
    }
       if(*maxiv<*maxiu){
        *maxi=*maxiu;
    }
    else {
        *maxi=*maxiv;
    }
}
void minmaxx(int n,int a[],int* mini,int* maxi){
    int t=n/2+1, miniv,maxiv;
    int m=n-t,miniu,maxiu;
    int v[t];
    int u[m];
    for (int i=0;i<t;i++){
        v[i]=a[i];
    }
    for (int i=0;i+t<n;i++){
        u[i]=a[t+i];
    }
    if(n==1){
        *maxi=a[0];
        *mini=a[0];
        return;
    }
    if (n>1){
        minmaxx(t,v, &miniv ,&maxiv);
        minmaxx(t,u, &miniu ,&maxiu);
        mrege (mini,maxi,&miniv,&maxiv,&miniu,&maxiu);
    }


    return;
}

int main()
{
    int minn=0,maxx=100;
    int a[10]={2,3,1,45,22,3,4,5,6,69};
    minmaxx(10,a,&minn,&maxx);
    cout << minn << endl<<maxx;
    return 0;
}
