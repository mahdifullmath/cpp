#include <iostream>

using namespace std;

int main()
{
    int a=23,b=-3;
    cout<<"a="<<a<<"\t";
    cout<<"b="<<b;
    a=a+b;
    b=a-b;
    a=a-b;
    cout << endl;
    cout<<"a="<<a<<"\t";
    cout<<"b="<<b;
    return 0;
}
