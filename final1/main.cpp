#include <iostream>

using namespace std;

class rational {
private:
    int a;
    int b;
public:
    rational (){
        a=1;
        b=1;
    }
    rational (int a1,int b1){
        if (b1==0)
            cout<<"its not a rational"<<endl;
        else{
            a=a1;
            b=b1;
        }
    }
    void display1(){
        cout<<a<<'/'<<b<<endl;
    }
    void display2(){
        cout <<(float)a/b<<endl;
    }
    rational operator +(rational x){
        rational m;
        m.b=b*x.b;
        m.a=a*x.b+x.a*b;
        return m;
    }
    rational operator -(rational x){
        rational m;
        m.b=b*x.b;
        m.a=a*x.b-x.a*b;
        return m;
    }
    rational operator /(rational x){
        rational m;
        m.b=b*x.a;
        m.a=a*x.b;
        return m;
    }
    rational operator *(rational x){
        rational m;
        m.b=b*x.b;
        m.a=a*x.b;
        return m;
    }
    void operator =(rational x){
        a=x.a;
        b=x.b;
    }
};

int main()
{
    rational a(1,2);
    rational b(2,3);
    rational c;
    c=a+b;
    c.display1();
    c.display2();
    c=a/b;
    c.display1();
    c=a;
    c.display1();

    return 0;
}
