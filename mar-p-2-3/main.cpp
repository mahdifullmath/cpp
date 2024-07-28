#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"input n:";
    cin>>n;
    int a[n][n];
    cout<<"input a[n][n]:\n";
    float m=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
            m=m+a[i][j];
        }
    }
    m=(float) m/n/n;
    cout <<"miangin="<<m;

    return 0;
}
