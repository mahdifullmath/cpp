#include <iostream>

using namespace std;
float f(float x[],int n){
 if(n==0)
    return 0;
 float a=f(x,n-1);
 a+=x[n-1]-floor(x[n-1])
 return a;
}

int main()
{

    cout << f(4,2) << endl;
    return 0;
}
