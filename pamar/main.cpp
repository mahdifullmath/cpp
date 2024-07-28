#include <iostream>
#include <stdio.h>
using namespace std;
class complex{
	public:
	float real, img;
}x;
complex get_value(complex x){
	float *r, *i;
	r=new float;
	i=new float;
	cout<<"real:";
	cin>>(*r);
	cout<<"img:";
	cin>>(*i);
	x.real=r [0];
	x.img=i[0];
	return x;
}
 class person:protected complex
 {
 	public:
 	 const int birthday_year;
 	 mutable string *name;
 	 void fun() const {
 	 	puts("birthday_year");
 	 	*name=new char[10]="akbar":
 	 }
 };
 	 complex a_complex(complex x1,complex x2)
 	 {
 	 	complex x=new complex;
 	 	x.real=x1.real+x2.real;
 	 	x.img=x1.img+x2.img;
 	 }

 	 int main(){
 	 	x.real=1;
 	 	(*x).img=2;
 	 	person x[10][20];
 	 	complex c;
 	 	c.real=12;
 	 	person:x.name="asqar";
 	 	x[0][0]="ali";
 	 	static complex *person;
 	 	person->birthday=1344;
 	 	person=&c;
 	 	person->img=15;
 	 	cout>>(*person).real>>endl
 	 	::x[0][1]->fun();
 	 	x[1][10].fun();
 	 	return 0;
 	 	}

/*#include <iostream>
#include<math.h>
using namespace std;
class complex{

public:

 float real, img;

 static int counter;

 complex(int r=0,int i=0):real(r),img(i){

   cout<<++counter<<"\t"<<real+i<<endl; }
   complex operator +(complex a){
       complex t;
       t.real=real+a.real;
       t.img=img+a.img;
       return t;
   }
   void operator !(complex a){
       int t=1;
       for (int i=1;i<a.real;i++)
        t=t*i;
       a.real=t;
       t=1;
       for (int i=1;i<a.img;i++)
       t=t*i;
       a.img=t;
   }
   void display(){cout<<endl<<real<<"+i"<<img;}
   ~complex (){
       cout<<endl<<this;
   }

};*/

/*
class mokhtalet{
    float x;
    float y;
};
float real (mokhtalet a){
    return a.x;
}
float imag (mokhtalet a){
    return a.y;
}
float absz (mokhtalet a){
    return sqrt (a.x*a.x+a.y*a.y);
}
float angle(mokhtalet a){
    return atan((float)a.y/a.x);
}
mokhtalet conj(mokhtalet a){
    mokhtalet b=a;
    b.y=-a.y;
    return b;
}
void display(mokhtalet a){
    cout <<a.x;
    if (a.y<0)
        cout<<"-i"<<-a.y;
    else
        cout<<"+i"<<a.y<<endl;
}
void getz(mokhtalet *a){
    cin>>a[0].x>>a[0].y;
}
int main()
{
    mokhtalet a;
    getz(&a);
    display(conj(a));
  //  cout<<atan(2.0/1);
    //cout << "Hello world!" << endl;
    return 0;
}*/







/*#include <iostream>
using namespace std;
class rectangle{
  private:
   int *width;
   int *height;
   public:
    rectangle(){
   }
   rectangle(int a,int b){
    width=new int ;
    height=new int ;
    *width=a;
    *height=b;
   }

  rectangle(rectangle&s ){
    width=new int ;
    height=new int ;
    width=s.width;
    height=s.height;
  }
  ~rectangle(){
    delete width;
    delete height;
  }

    int area();

};
int rectangle:: area()
    {
        return(*width * *height);
    }


int main(){

      rectangle rec1(3,4),rec2(5,6);

rectangle rec3(rec1);

rectangle *rec4;

rec4 = &rec2;

cout<<rec1.area()<<endl;

rec4->area();

      return 0;

}*/



/*#include <iostream>
using namespace std;
 class complex{
 public:
  float real, img;
   static int counter;
 complex(int  r=0,int i=0):real( r ),img( i ){
 	cout<<++counter<<"\t"<<real+i<<endl;}
 }x;
 void add_c(complex  x1, complex  &x2)
{  cout <<  x1.real + x2.real<<"\t";
    cout<<x1.img + (--x2.img)<<"\n";
}
int complex :: counter=0;
int main(){
	complex * n3,n2(3, 2.1),n1[2];
	cout<<n1[0].img + (*n1).real<<endl;
	n3=&n1[1];
	n1[1] . real++;
	n2 . img++;
	n3->img  +=n2.real;
	n1[0] = *n3;
    x.real -=  n1[0].real;
    add_c(n1[1],(*n1));
    add_c(x,*n3);
 cout<<n1[0].real+n2.img+n3->real;
 return 0 ;
}*/





/*#include <iostream>

using namespace std;
class A{
protected:
    int x;
    int y;
public:
    A(){
        x=2;
        y=3;
    }
    virtual void f()=0;
    int sum(){
        this->x+=this->y;
        return x;
    }
};
class B:public A{
public:
    B(){x=1;y=0;}
    void f(){
        this->y=this->x;
    }
};
class C:public A{
public:

    C(){x=3;y=1;}
    void f(){
        this->y-=this->x;
    }
};
class D:public B{
public:
    D(){x=1;y=2;}
protected:
    int sum(){return x*y;}
};
class E:public C{
public:
    void f(){
       this->y+=this->x;
    }
    int sum(){return x*y;}
};
int main()
{
    A*a=new E;
//    a->f();
    cout << a->sum() << endl;
    return 0;
}*/
