#include <iostream>

using namespace std;
class person{
protected:
    string name;
    string family;
    string natio;
    unsigned int age;
    unsigned long int id;
public:
    person(){}
    person(string a,string b){
        name=a;
        family=b;
    }
    person(string name1,string family1,string natio1,unsigned int age1,unsigned long int id1){
     name=name1;
     family=family1;
     natio=natio1;
     age=age1;
     id=id1;
    }
    virtual void show_val(){

    }
    virtual void get_val()=0;
};
class employee:public person{
protected:
    int *salary;
public:
    void get_val(){
    }
    void show_val(){
    }
    employee(){
        salary=new int;
    }
    employee(int a){
        salary=new int;
        *salary=a;
    }
    employee(string name1,string family1,string natio1,unsigned int age1,unsigned long int id1,int a):person( name1,family1,natio1, age1, id1){
        salary=new int;
        *salary=a;
    }
    void operator+=(int a){
        *salary+=a;
    }
    void operator-=(int a){
        *salary-=a;
    }
    ~employee(){
        cout<<"\n"<<this;
    }
};
class programmer:public employee{
private:
    friend class manager;
    static int p;
public:
    void get_val(){
    }
    void show_val(){
    }
    programmer(){
        p++;
    }
    programmer(string name1,string family1,string natio1,unsigned int age1,unsigned long int id1,int a):employee(name1,family1, natio1, age1, id1,a)
    {
        p++;
    }
    programmer(programmer &a){}
    void setsalary(int a);
    ~programmer(){
        cout<<"\n"<<this;
    }
};
void programmer::setsalary(int a){

}
class manager:public employee{
public:
    void get_val(){
    }
    void show_val(){
    }
    void chap(){
    }
    manager():employee (8000000){

    }
    ~manager(){
        cout<<"\n"<<this;
    }
};
int main()
{
//    const manager a;
    employee b[10];
    programmer *c=new programmer[5];

    person *x;
    delete[] c;
    return 0;
}
