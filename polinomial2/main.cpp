#include <iostream>
#include <math.h>
using namespace std;
class polynomial2{
	private:
	int a;
	int b;
	int c;
	public:
	polynomial2 ();
	polynomial2 (int A, int B, int C);
	float tabe (float x);
	void display();
	void root();
	polynomial2 pluss(polynomial2 z);
  };
polynomial2:: polynomial2(){
  	 a=b=c=0;
}
polynomial2:: polynomial2(int A, int B, int C){
      a=A;
      b=B;
      c=C;
}
float polynomial2:: tabe(float x){
      	return a*x*x+b*x+c;
}
void polynomial2::display(){
      cout<<a<<"x^2";
      if (b>0)
      cout<<"+"<<b<<"x";
      else
      cout<<b<<"x";
      if(c>0)
      cout<<"+"<<c<<endl;
      else
      cout<<c<<endl;
}
void polynomial2:: root(){
      	if(b*b-4*a*c<0)
      	  cout<<"no root";
   	    else
     	  cout<<"x1="<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl<<"x2=" <<(-b-sqrt(b*b-4*a*c))/(2*a)<<endl;
}
polynomial2 polynomial2::pluss (polynomial2 o){
   polynomial2 t;
     t.a=a+o.a;
     t.b=b+o.b;
     t.c=c+o.c;
      return t;
      }
int main(){
    polynomial2 t(1,-4,4);
    polynomial2 s(1,4,4);
    polynomial2 w;
    float m=t.tabe(2);
    s.display();
    t.root();
    w=t.pluss(s);
    w.display ();
    cout<<m;
    return 0;
}
