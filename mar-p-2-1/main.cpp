#include <iostream>

using namespace std;
int sorting (int a[],int t){
   if (t>0){
    int minn=a[0];
    int x=0,i=0;
    for (;i<t;i++){
        if (a[i]<minn){
            minn=a[i];
            x=i;
        }
    }

    swap(a[x],a[t-1]);
    sorting (a,t-1);
    }
    return a[0];

}
int main()
{
    int t;
    cin >>t;
    int a[t];
    for (int i=0;i<t;i++){
        cin>> a[i];
    }
    int x;
    x=sorting (a,t);
    for (int i=0;i<t;i++){
        cout<<" "<< a[i];
    }
    cout<<"\nmax:"<<x;
    return 0;
}
