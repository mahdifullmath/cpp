#include <iostream>

using namespace std;

int main()
{
    int d1,d2,d3,n,s;
    cin>>n;
    d1=n%10;
    d2=(n/10)%10;
    d3=n/100;
    s=(d3*d3)+(d2*d2)+(d1*d1);
    cout << " s="<<s<< endl;
    return 0;
}
