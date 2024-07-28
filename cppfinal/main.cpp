#include <iostream>
#include <string.h>

using namespace std;

class complex{
int a,b;
public:
complex(int I, int j){
cout<<"Parameterized Constructor\n";
a=I; b=j;
}
complex(){
cout <<"Default Constructor \n";
a=0; b=0;
}
complex operator+(complex ob){
complex t;
t.a=a+ob.a;
t.b=b+ob.b;
return t;
}
complex operator-(complex ob){
complex t;
t.a=a-ob.a;
t.b=b-ob.b;
return(t);
}
complex operator=(complex ob){
a=ob.a;
b=ob.b;
return *this;
}
complex operator++( ){
++a;
++b;
return *this;
}
complex operator+=(complex ob){
a+=ob.a;
b+=ob.b;
return *this;
}
void display() {
cout<<a<<"+"<<b<<"I"<<endl;
}
};
int main(){
complex obj1(1,5),obj2(3,4),result;
obj1.display();
obj2.display();
result = obj1+obj2;
result.display();
obj1=obj2;
obj1.display();
obj1=++obj2;
obj1.display();
obj1+=obj2;
obj1.display();
}
