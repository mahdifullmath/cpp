#include <iostream>

using namespace std;
struct complex
{
  float real,img;
}x;
void display(complex *x)
{
//    cout<< "complex num: "<<this->real
cout<< "complex num: "<<x->real;
//    cout<< "+"<<this->img<<"i"<<endl
cout<< "+"<<x->img<<"i"<<endl;
}
// complex add complex(complex x1, complex  x2)
complex addcomplexi(complex x1, complex  x2)
{
    // عملگر *
    complex *x=new complex;
    // عمل گر ->
    x->real = x1.real + x2.real;
    //عملگر->
    x->img = x1.img + x2.img;
}
 void get_value(complex *x)
 {
     float *r, *i;
     //cout
     cout<<"real:";
     cin >> (*r);
     //cout
     cout<<"img:";
     cin  >> (*i);
     // complex x

     x->real = r[0];
     x->img = i[0];

 }
int main()
{
    // تعریف متغیر
  complex x;
  complex* cx;
  //*cx
  cx->img = 2;
  ::x.real = 3;
  complex cx2[10];
  for(int i= 0; i<= 10; i++)
  {
      //اسم تابع
      get_value(&cx2[i]);
  }
   for(int i= 0; i<= 10; i++)
   {
       // اسم تابع
      display(&cx2[i]);
   }
   //اسم تابع
   x = addcomplexi(*cx2, *cx);
   //cout
   cout<<"x:" <<x.real ;
   cout<<::x.img << endl;
   //string
   puts("the end");
   delete cx;
    return 0;
    //}
    }

