#include <iostream>
using namespace std;
class teacher;
class student;
int k;
int s;
class person{
public:
    char gender;
    float age;
    string family;
    string name;
public:
       person(char g,float a,string f,string n){
        gender = g;
        age=a;
        family=f;
        name=n;

    }
};
//*****
class teacher:public person{
private:
     int time;
     static float basesalary;
    float salary(){
         float q=0;
         if(time>20){
                q=20*basesalary;
                q=q+2*(time-20)*time*basesalary;
         }
         else{
                q=time*basesalary+q;
         }
         return q;
    }
public:

    teacher(int t,char g,float a,string f,string n):person( g, a, f, n)
    {
        time=t;
    }
void ChangeBase(int b)
{
	basesalary = b;
}
    void Print(){
        cout<<"name: "<<person::name<<endl;
        cout<<"family: "<<person::family<<endl;
        cout<<"age: "<<person::age<<endl;
        cout<<"time: "<<time<<endl;
        cout<<"base salary: "<<basesalary<<endl;
        cout<<"total salary: "<<salary()<<endl;

    }
    static void mohasebeh(teacher a[2]){
	int i, total = 0;
	for (i = 0;i<k;i++)
	{
		a[i].Print();
		total=total+a[i].salary();
	}
	cout << "Total Salary is:" << total<< endl;
    }
     void printteacher(int s );
    void dispteacher();
};
//******************
float teacher::basesalary=10000;
//*****************
void teacher::printteacher(int s){
    teacher *o;
  for(int i=0;i<s;i++){
        cout<<"enter data for teacher:"<<i+1<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"name:"<<endl;
        cin>>o[i].name;
        cout<<"family:"<<endl;
        cin>>o[i].family;
        cout<<"age:"<<endl;
        cin>>o[i].age;
        cout<<"gender:"<<endl;
        cin>>o[i].gender;
        cout<<"time:"<<endl;
        cin>>o[i].time;
        cout<<"base salary: "<<o[i].basesalary<<endl;
        cout<<"total salary: "<<o[i].salary()<<endl;

  }

}
//**********************
void teacher:: dispteacher(){
    teacher *o1;
     for(int i=0;i<s;i++){
        cout<<"print data for teacher:"<<i+1<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"name:"<<o1[i].name<<endl;
        cout<<"family:"<<o1[i].family<<endl;
        cout<<"age:"<<o1[i].age<<endl;
        cout<<"gender:"<<o1[i].gender<<endl;
        cout<<"base salary: "<<o1[i].basesalary<<endl;
        cout<<"total salary: "<<o1[i].salary()<<endl;

  }
}
//********************
class student:public person{
private:
    float practice;
    float project;
    float last;
    float half;

    float mark(){
        float q;
        q=practice+project+last+half;
        return q;
    }

public:
    student(float p,float r,float l ,float h,char g,float a,string f,string n):person(g, a, f, n){
        practice=p;
        project=r;
        last=l;
        half=h;
        if(practice>2&&project>3&&last>10&&half>5){
            practice=2;
            project=3;
            last=10;
            half=5;
        }
    }

    void print(){
        cout<<"name:"<<person::name<<endl;
        cout<<"family:"<<person::family<<endl;
        cout<<"age:"<<person::age<<endl;
        cout<<"gender:"<<person::gender<<endl;
        cout<<"middle term:"<<half<<endl;
        cout<<"final term:"<<last<<endl;
        cout<<"project:"<<project<<endl;
        cout<<"exercise:"<<practice<<endl;
        cout<<"total score:"<<mark()<<endl;
        }
void avre( student s[2], int m){
	float average=0;
	int i;
	for (i = 0;i < m;i++)
	{
		average =average+s[i].mark();
		s[i].print();
	}
	average /= m;
	cout << "average is:" << average<< endl;
}
    void inforstudent(int k,student *w);
    void printstudent(student *w,int );
    friend void best( student*,int) ;
	friend void mashrot(student*,int);
};
//*******************
void student::inforstudent(int k,student *w){
        for(int i=0;i<k;i++){
       cout<<"enter data for student:"<<i+1<<endl;
       cout<<"----------------------------"<<endl;
       cout<<"name:"<<endl;
       cin>>w[i].name;
       cout<<"family:"<<endl;
       cin>>w[i].family;
       cout<<"age:"<<endl;
       cin>>w[i].age;
       cout<<"gender:"<<endl;
       cin>>w[i].gender;
       cout<<"half:"<<endl;
       cin>>w[i].half;
       cout<<"last:"<<endl;
       cin>>w[i].last;
       cout<<"practice:"<<endl;
       cin>>w[i].practice;
       cout<<"project:"<<endl;
       cin>>w[i].project;
       cout<<"total mark:"<<w[i].mark();
    }

}
void student:: printstudent(student *a1, int k){

    for(int i=0;i<k;i++){
        cout<<"print data for student:"<<i+1<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"name:"<<a1[i].name<<endl;
        cout<<"family:"<<a1[i].family<<endl;
        cout<<"age:"<<a1[i].age<<endl;
        cout<<"gender:"<<a1[i].gender<<endl;
        cout<<"half:"<<a1[i].half<<endl;
        cout<<"last:"<<a1[i].last<<endl;
        cout<<"practice:"<<a1[i].practice<<endl;
        cout<<"project:"<<a1[i].project<<endl;
        cout<<"total mark:"<<a1[i].mark()<<endl;
    }
}
//**************
void best(student *s,int k)
{
	float max = 0;
	int i;
	for (i = 1;i < k;i++)
		if (s[i].mark() > max)
			max = s[i].mark();
	for (i = 0;i < k;i++)
		if (s[i].mark() == max)
			s[i].print();
}
//****************
void mashrot(student *s, int k)
{
	int i;
	for (i = 0;i < k;i++)
		if (s[i].mark() < 12)
			s[i].print();
}
//****************
int main()
{
    student w[20];
    int code ;
    cout<<"Select one of list or Enter 6 to end: "<<endl;
    cin>>code;
   while(code>0&&code<3){
    switch(code){
    case 1:{
        cout<<"Enter the number of students:";
        cin>>k;
        student a;
        a.inforstudent(k,w);
    break;}

    case 2:{
        student *a1;
        a1->printstudent(a1,k);
    break;}
    case 3:
         cout<<"Enter the number of teacher:";
         cin>>s;
         teacher *o;
         o->printteacher(s);
         break;
    }
   }
    return 0;
}
