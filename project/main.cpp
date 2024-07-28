#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
//person...................person.........................................................
class person{
protected:
   char name [20];
   char family[40];
   int age;
   char gender[10];
public:
    person (){
        name[0]=0;
        family[0]=0;
        age=0;
        gender[0]=0;
    }
    person(int x){
        cout<<"enter name"<<x<<endl;
        cin>>name;
        cout<<"enter family"<<x<<endl;
        cin>>family;
        cout<<"enter age"<<x<<endl;
        cin>>age;
        cout<<"enter gender"<<x<<endl;
        cin>>gender;
    }
    person(char * n,char * f,int a,char * g){
        strcpy (name ,n);
        strcpy (family,f);
        age=a;
        strcpy (gender,g);
    }

};
//.............................................................................
//teacher***********************teacher*****************************************
class teacher:public person{
private:
    int time;
    static int basesalary;

public:
    teacher (){
        time=0;
    }
    teacher(int x,int y):person(x){
        cout<<"enter teaching time for "<<name<<endl;
        cin>>time;
    }
    teacher (char * n,char * f,int a,char * g,int t):person(n,f,a,g){
        time=t;
    }
    static void changesalary (){
        int s;
        cout<<"enter new base salary"<<endl;
        cin>>s;
        basesalary=s;
    }
    void displayt(){
        //cout<<"name\tfamily\tage\ttime\tbasesalary\ttotalsalari"<<endl;
        cout<<name<<"\t\t"<<family<<"\t\t"<<age<<"\t"<<time<<"\t"<<basesalary<<"\t\t"<<salary()<<endl;
    }
    int salary (){
        if (time<=20)
            return time*basesalary;
        else
            return 20*basesalary+(abs (20-time))*basesalary;
    }
};
int teacher ::basesalary=10000;
//********************************************************************************************************************
//student----------------------------student-------------------------------------------------------------------------
class student:public person{
private:
    float half,last,project,practice;

public:
    student (){
        half=0;
        last=0;
        project=0;
        practice=0;
    }
    student (int x,int y):person(x){
        int h;
        cout<<"enter midterm for "<<name<<" maximum 5"<<endl;
        cin>>h;
        if(h<=5)
            half=h;
        else
            half=5;
        cout<<"enter final for "<<name<<" maximum 10"<<endl;
        cin>>h;
        if(h<=10)
            last=h;
        else
            last=10;
        cout<<"enter project for "<<name<<" maximum 3"<<endl;
        cin>>h;
        if(h<=3)
            project=h;
        else
            project=3;
        cout<<"enter practice for "<<name<<" maximum 2"<<endl;
        cin>>h;
        if(h<=2)
            practice=h;
        else
            practice=2;
    }
    student (char * n,char *f,int a,char * g,float h,float l,float po,float p):person (n,f,a,g){
        half=h;
        last=l;
        project=po;
        practice=p;
    }
    void displays(){
       // cout<<"name\t\tfamily\t\tage\tgender\tmidterm\tfinal\tpractice\tproject\ttotal"<<endl;
        cout<<name<<"\t\t"<<family<<"\t\t"<<age<<"\t"<<gender<<"\t"<<half<<"\t"<<last<<"\t"<<practice<<"\t\t"<<project<<"\t"<<mark()<<endl;
    }
    float mark(){
        return half+last+project+practice;
    }
    friend void mashroot(student *a,int n);
    friend void balatarin(student *a,int n);
    friend int findstu (student *a,char *family,int n);
    friend void editstu (student *a,char *family,int n);
};
//-----------------------------------------------------------------------------------------------------------------------------------------
//tabe====================tabe==============================================
void getmodares (teacher *a,int n){
    for (int i=0;i<n;i++){
        teacher x(i+1,i+1);
        a[i]=x;
    }
}
void chapmodares (teacher *a,int n){
    cout<<"name\t\tfamily\t\tage\ttime\tbasesalary\ttotalsalari"<<endl;
    int s=0;
    for (int i=0;i<n;i++)
    {
        a[i].displayt();
        s=s+a[i].salary();
    }
    cout<<"total salary is:"<<s<<endl<<endl;

}
void getdaneshjou (student *a,int n){
    for (int i=0;i<n;i++){
        student x(i+1,i+1);
        a[i]=x;
    }
}
void chapdaneshjou (student *a,int n){
    cout<<"name\t\tfamily\t\tage\tgender\tmidterm\tfinal\tpractice\tproject\ttotal"<<endl;
    int s=0;
    for (int i=0;i<n;i++)
    {
        a[i].displays();
        s=s+a[i].mark();
    }
    cout<<"Avrage is:"<<(float)s/n<<endl<<endl;
}
void balatarin(student *a,int n){
    cout<<"best studens:"<<endl;
    cout<<"name\t\tfamily\t\tage\tgender\tmidterm\tfinal\tpractice\tproject\ttotal"<<endl;
    int max=0;
    for (int i=0;i<n;i++){
        if (a[i].mark()>max)
             max=a[i].mark();
    }
    for (int i=0;i<n;i++){
        if (a[i].mark()==max)
            a[i].displays();
    }
}
void mashroot(student *a,int n){
    cout<<"mashrootha:"<<endl;
    cout<<"name\t\tfamily\t\tage\tgender\tmidterm\tfinal\tpractice\tproject\ttotal"<<endl;
    for (int i=0;i<n;i++){
        if (a[i].mark()<12)
             a[i].displays();
    }
}
int findstu (student *a,char *family ,int n){
	for (int i=0;i<n;i++){
		if (strcmp(a[i].family,family)==0)
		   return i;
	}
	return -1;
}
void editstu (student *a,char *family,int n){
	int i=findstu (a,family,n);
	if (i!=-1){
        int h;
        cout<<"enter midterm for "<<a[i].name<<" maximum 5"<<endl;
        cin>>h;
        if(h<=5)
            a[i].half=h;
        else
            a[i].half=5;
        cout<<"enter final for "<<a[i].name<<" maximum 10"<<endl;
        cin>>h;
        if(h<=10)
            a[i].last=h;
        else
            a[i].last=10;
        cout<<"enter project for "<<a[i].name<<" maximum 3"<<endl;
        cin>>h;
        if(h<=3)
            a[i].project=h;
        else
            a[i].project=3;
        cout<<"enter practice for "<<a[i].name<<" maximum 2"<<endl;
        cin>>h;
        if(h<=2)
            a[i].practice=h;
        else
            a[i].practice=2;
	}
	else
	    cout<<"there is no such a student ;)\n";
}
//===========================================================================
//main+++++++++++++++++++++++++++++++++++++++++++++main++++++++++++++++++++++
int main()
{
    teacher a[2];
    student b[20];
    teacher temp1 ("ali","zribaf",54,"m",30), temp2 ("mahdi","ghasemi",40,"m",50);
    student t1("adil","max",20,"m",4.5,7,2,1.56),t2("abbas","bouazar",21,"m",2.5,3,2,1.56),t3("zahra","maleki",22,"f",2.5,7.2,3,1.26),t4("melika","sadeghi",20,"f",4.5,9.5,2.9,1.56);
    a[0]=temp1;
    a[1]=temp2;
    b[0]=t1;
    b[1]=t2;
    b[2]=t3;
    b[3]=t4;

    for (int x,n;;){

              cout<<"menu:"<<endl<<"1.get teacher\n2.get student\n3.print teacher\n4.print student\n5.top rated studens \n6.mashrouti ha\n7.edit student score\n8.find student\n9.change teachers base salary\n0.close the program\n";
              cout<<"enter a number:";
              cin>>x;
              if (x==1){
                      cout<<"how meny?"<<endl;
                      cin>>n;
	                  getmodares(a,n);
              }

              else if (x==2){
                      cout<<"how meny?"<<endl;
	                  cin>>n;
	                  getdaneshjou(b,n);
              }
              else if (x==3){
                      cout<<"how meny?"<<endl;
                      cin>>n;
                      chapmodares(a,n);
              }
              else if (x==4){
                      cout<<"how meny?"<<endl;
                      cin>>n;
                      chapdaneshjou(b,n);
              }
              else if(x==5)
                      balatarin (b ,20);
              else if(x==6)
                      mashroot(b,4);
              else if (x==7){
              	    cout<<"enter family:\n";
              	    char e[20];
              	    cin.ignore();
              	    cin.getline (e,20);
              	    editstu (b,e,20);
              }
              else if (x==8){
                    cout<<"enter family:\n";
                    char e[20];
                    cin.ignore();
                    cin.getline(e,20);
                    int z=findstu(b,e,20);
                    if (z!=-1){
                        cout<<"name\t\tfamily\t\tage\tgender\tmidterm\tfinal\tpractice\tproject\ttotal"<<endl;
                        b[z].displays();
                    }
                    else
                        cout<<"there is no such a student ;)\n";

              }
              else if (x==9){
                a[0].changesalary();
              }
              else if (x==0)
                      break;

    }


    return 0;
}
