#include <iostream>
#include <math.h>
using namespace std;
long double f (long double x){
    long double t;
    t=cos(x)+exp (x);
    return t;
}
int main()
{
    long double a=-3,b=0,ep=pow(10,-5),c;
//    cin>>a>>b>>ep;

    int i=0;
    for (;abs(b-a)>=ep||f(c)==0;i++){
        c=(float)(a+b)/2;
        if(f(a)*f(c)<0)
            b=c;
        else if(f(b)*f(c)<0)
            a=c;
    }
    cout<<"root= "<<c<<endl<<"i= "<<i<<endl<<f(c);
    return 0;
}
