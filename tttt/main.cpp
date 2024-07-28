#include <iostream>

using namespace std;

class Student;
class Teacher;
class Person
{
    public:
        bool gender;
        int age;
        string family;
        string name;
    public:
        Person(){}
        Person(string nam,string famil,int sen,bool gen){
            name=nam;
            family=famil;
            age=sen;
            gender=gen;
        }
 };
class Teacher:public Person{
    private:
        double time;
        static int baseSalary;
    public:
        Teacher(){}
        Teacher(int a){
            time=a;
        }
    public:
        static double changeBase(double G){
            double H;
            H=baseSalary+G;
            return H;
        }
    private:
        double salary(){
            double Y;
            Y=time*baseSalary;
            if(time>20){
            Y=time*baseSalary*(time-20)*2;}
            return Y;
        }
    public:
        Teacher CHAP(){
            if(gender==0){
                cout<<"Gender is: M";}
            if(gender==1){
                cout<<"Gender is: F";}
          cout<<"Name     family     Age     Time     Base Salary     Total Salary   "<<endl;
          cout<<name<<"  "<<family<<"  "<<age<<"  "<<time<<"  "<<baseSalary<<"  "<<salary()<<endl;
        }
    public:
        void dryaftmodares(){
            cout<<"Name :"<<endl;
            cin>>name;
            cout<<"Family :"<<endl;
            cin>>family;
            cout<<"Age :"<<endl;
            cin>>age;
            cout<<"Gender :"<<endl;
            cin>>gender;
            cout<<"Time :"<<endl;
            cin>>time;
            cout<<"base salary: "<<baseSalary<<endl;
            cout<<"total salary: "<<salary()<<endl;
        }
    public:
        void CHAPmodares(){
            cout<<"Name :"<<endl;
            cout<<name<<endl;
            cout<<"Family :"<<endl;
            cout<<family<<endl;
            cout<<"Age :"<<endl;
            cout<<age<<endl;
            cout<<"Gender :"<<endl;
            cout<<gender<<endl;
            cout<<"Time :"<<endl;
            cout<<time<<endl;
            cout<<"base salary: "<<baseSalary<<endl;
            cout<<"total salary: "<<salary()<<endl;
        }
};
int k;

void dryaftmodares(Teacher *A){
    cout<<"chanta\n";
    cin>>k;
    for(int i=0;i<k;i++){
        A[i].dryaftmodares();
    }
}
void CHAPmodares(Teacher *A){
    cout<<"chanta\n";
    cin>>k;
    for(int i=0;i<k;i++){
        A[i].CHAPmodares();
    }
}
int Teacher::baseSalary=10000;

class Student:public Person{
    private:
        double half;
        double last;
        double project;
        double practice;
    public:
        Student(){}
        Student(double h,double l,double pro,double pra){
            half=h;
            last=l;
            project=pro;
            practice=pra;
            if(project>3 && last>10 && half>5 && practice>2){
                project=3;
                last=10;
                half=5;
                practice=2;
            }
        }
    private:
        double mark(){
            double K;
            K=half+last+project+practice;
            return K;
        }
    public:
        double moadel(){
            double z;
            z=(half+last+project+practice)/4;
            return z;
        }
    public:
        double chap2(){
            cout<<"Name     Family     Age     Gender     Middle Term     Final Term     project     Exercise     Total score     "<<endl;
            cout<<name<<"  "<<family<<"  "<<age<<"  "<<gender<<"  "<<half<<"  "<<last<<"  "<<project<<"  "<<practice<<"  "<<endl;
        }
    public:
        void dryaftDA(){
            cout<<"enter name :"<<endl;
            cin>>name;
            cout<<"enter family :"<<endl;
            cin>>family;
            cout<<"enter age :"<<endl;
            cin>>age;
            cout<<"enter gender :"<<endl;
            cin>>gender;
            cout<<"enter Miiddle Term :"<<endl;
            cin>>half;
            cout<<"enter Final Term :"<<endl;
            cin>>last;
            cout<<"enter Project :"<<endl;
            cin>>project;
            cout<<"enter Exercise :"<<endl;
            cin>>practice;
            cout<<"total score: "<<mark()<<endl;
        }
    public:
        void CHAPDA(){
            cout<<"Name :"<<endl;
            cout<<name<<endl;
            cout<<"Family :"<<endl;
            cout<<family<<endl;
            cout<<"Age :"<<endl;
            cout<<age<<endl;
            cout<<"Gender :"<<endl;
            cout<<gender<<endl;
            cout<<"enter Miiddle Term :"<<endl;
            cout<<half<<endl;
            cout<<"enter Final Term :"<<endl;
            cout<<last<<endl;
            cout<<"enter Project :"<<endl;
            cout<<project<<endl;
            cout<<"enter Exercise :"<<endl;
            cout<<practice<<endl;
            cout<<"total score: "<<mark()<<endl;
        }
};
int z;
Student *C;

void dryaftDA(){
    cin>>k;
    C=new Student[k];
    for(int i=0;i<k;i++){
        C[i].dryaftDA();
    }
}
void CHAPDA(){
    for(int i=0;i<k;i++){
        C[i].CHAPDA();
    }
}
int main(){
    Teacher A[20];
    int V=1;
    for(;V>0&&V<6;){
        cout<<"1)dryaftmodares\n2)CHAPmodares\n3)dryaftDA\n4)CHAPDA\n5)exit\n";
        cin>>V;
        switch(V){
            case 1:{
                dryaftmodares(A);
                break;
            }
            case 2:{
                CHAPmodares(A);
                break;
            }
            case 3:{
                dryaftDA();
                break;
            }
            case 4:{
                CHAPDA();
                break;
            }
        }
        if(V==5){
            break;
        }
    }

    delete[] C;
    return 0;
}
