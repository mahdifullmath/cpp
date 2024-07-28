#include <iostream>

using namespace std;
struct person{
    string name;
    string family;
    unsigned long int id;
    unsigned int age;
};
class uni{
private:
    string uniname;
    string cityname;
    int year;
public:
    uni(){}
    uni(string a,string b,int c){
        uniname=a;
        cityname=b;
        year=c;
    }
    uni(uni &a){
        uniname=a.uniname;
        cityname=a.cityname;
        year=a.year;
    }
    ~uni(){}
    getuni(){
        cin>>uniname;
        cin>>cityname;
        cin>>year;
    }
};
class student{
private:
    person a;
    int yearofin;
    string u;
    int av;
public:
    student(){
        a.name='\0';
        a.family='\0';
        a.age=0;
        a.id=0;
        yearofin=0;
        u='\0';
        av=0;
    }
    student(string n,string b,int c,unsigned int d,int y,string e,int s){
        a.name=n;
        a.family=b;
        a.age=c;
        a.id=d;
        yearofin=y;
        u=e;
        av=s;
    }
    ~student(){
        cout<<"\n"<<this;
    }
};
class ostad{
private:
    person a;
    int yearofin;
    string u;
public:
    ostad(){
        a.name='\0';
        a.family='\0';
        a.age=0;
        a.id=0;
        yearofin=0;
        u='\0';
    }
    ostad(string n,string b,int c,unsigned int d,int y,string e){
        a.name=n;
        a.family=b;
        a.age=c;
        a.id=d;
        yearofin=y;
        u=e;
    }
    ~ostad(){
        cout<<"\n"<<this;
    }
};
class employee{
private:
    person em;
    int yearofin;
    string u;
    string semat;
public:
    employee(){
        em.name='\0';
        em.family='\0';
        em.age=0;
        em.id=0;
        yearofin=0;
        u='\0';
        semat='\0';
    }
    employee(string a,string b,int c,unsigned int d,int y,string e,string s){
        em.name=a;
        em.family=b;
        em.age=c;
        em.id=d;
        yearofin=y;
        u=e;
        semat=s;
    }
    ~employee(){
        cout<<"\n"<<this;
    }
};
class anjomanelmii{
private:
    ostad a;
    student b[10];
public:
    anjomanelmii(){
    }
    ~anjomanelmii(){
        cout<<"\n"<<this;
    }
};
int main()
{
    uni *a=new uni;
    student *b=new student;
    ostad *c=new ostad;
    employee *d=new employee;
    anjomanelmii *e=new anjomanelmii;
    student f[5];
    ostad g[5];
    employee h[5];
    anjomanelmii i[5];
    delete a;
    a=NULL;
    delete b;
    b=NULL;
    delete c;
    c=NULL;
    delete d;
    d=NULL;
    delete e;
    e=NULL;
    return 0;
}
