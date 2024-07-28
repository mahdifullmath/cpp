#include <iostream>

using namespace std;

class polinomial2{
private:
    float a;
    float b;
    float c;
public:
    polinomial2 (){
        a=0;
        b=0;
        c=0;
    }
    polinomial2(int c1,int b1,int a1){
        a=a1;
        b=b1;
        c=c1;
    }
    void get (){
        cin>>a>>b>>c;
    }
    float y(float x){
        return c*x*x+b*x+a;
    }
    void display (){
        if (a>=0&&b>=0)
            cout<<c<<"x^2+"<<b<<"x+"<<a<<endl;
        else if (a<0&&b<0)
            cout<<c<<"x^2"<<b<<"x"<<a<<endl;
        else if (a>=0&&b<0)
            cout<<c<<"x^2"<<b<<"x+"<<a<<endl;
        else if (a<0&&b>=0)
            cout<<c<<"x^2+"<<b<<"x"<<a<<endl;
    }
    polinomial2 operator -(polinomial2 x){
        polinomial2 m;
        m.a=a-x.a;
        m.b=b-x.b;
        m.c=c-x.c;
        return m;
    }
    polinomial2 operator +(polinomial2 x){
        polinomial2 m;
        m.a=a+x.a;
        m.b=b+x.b;
        m.c=c+x.c;
        return m;
    }
    void operator =(polinomial2 x){
        a=x.a;
        b=x.b;
        c=x.c;
    }


};

int main()
{
    polinomial2 a;
    polinomial2 b;
    a.get();
    b.get();
    a.display();
    b.display();
    polinomial2 c;
    c=a+b;
    c.display();
    c=a-b;
    c.display();

    return 0;
}

