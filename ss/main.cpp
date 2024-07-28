#include <iostream>
using namespace std;

int main()
{
    int n;
    bool f;
    cin>>n;
    int m[n];
    int t[n];
    for (int i=0;i<n;i++){
        cin>>m[i];
    }
    for (int i=0;i<n;i++){
        cin>>t[i];
    }
    for (int i=0;i<n;i++){
        f=true;
        for (int j=0;j<n;j++){
            if (m[i]==t[j]){
                f=false;
                break;
            }
        }
        if(f){
         cout<<m[i]<<endl;
        }
    }
    return 0;
}
