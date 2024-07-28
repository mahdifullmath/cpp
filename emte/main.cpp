#include <iostream>
using namespace std;

int main()
{
    int n,f;
    cin>>n;
    int m[100];
    for (int i=0;i<n;i++){
        cin>>m[i];
    }
    for (int i=0;i<n;i++){
        f=0;
        for (int j=0;j<n;j++){
            if (i=!j&&m[i]==m[j]){
                f=1;
            }
        }
        if (f==0){
         cout<<m[i]<<endl;
        }
    }
    return 0;
}
