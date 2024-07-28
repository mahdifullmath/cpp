#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
class person {
 public:
    string name;
    string family;
 private:
    int tt;
    unsigned long int id;
    friend int main();
    friend void moratab_sazi(person y[],person x[],int n);
};
class customer:protected person{
public:
    string username;
    friend void total_customer(customer );
    static int num_customer;
private:
    string password;
public:
    customer(){
        cout<<"\ncustomer-username:";
        cin>>username;
        cout<<"\ncostomer-password:";
        cin>>password;
        num_customer++;
    }
    customer(string a,string b){
        username=a;
        password=b;
        num_customer++;
    }
    customer(string c,string d,person e){
        username=c;
        password=d;
        name=e.name;
        family=e.family;
        num_customer++;
    }

    void complete_your_info(){
        cout<<"\nesm khod ra vared konid";
        cin>>name;
        cout<<"\nfamil khod ra vared konid";
        cin>>family;
    }
    void change_pass(){
        string b;
        cout<<"\nyour user name?";
        cin>>b;
        if(username==b){
            cout<<"ramz jadid ra vared kon";
        }
        else {
            cout<<"your username is wrong!";
        }
    }



};
int customer::num_customer=0;
class manager:public person{
private:
  friend void menu(manager *x,customer *y);
  const string namekarbar;
  const string ramz;
public:
  manager ():namekarbar("admin"),ramz("@Admin"){
      name="Ali";
      family="Fattahi";
  }
  void total_customer(customer a){
      cout<<"\nkolcostomer:"<<a.num_customer;
  }
   ~manager(){

   cout<<"\ngoodbye"<<name<<" "<<family<<".";
   }
 };
 class digital_products{
 protected:
    int ID;
    unsigned int pricebuy;
    friend void menu(manager *x,customer *y);
 public:
    int saltolid;
    unsigned int pricesell;
    digital_products(){};
 };
 class phone:public digital_products{
 private:
     friend class phone_accessories;
    int ram;
    int cim_capacity;
    int resolution[2];
    string model;
//    phone()
    void get_value(){
    }
 };
 class tablet:public digital_products{
 private:
     friend class phone_accessories;
    int ram;
    int cim_capacity;
    int weight;
    int resolution[2];
    string model;
    void get_value(){
    }
 };
 class tv:public digital_products{
 private:
    bool is4k;
    int resolution[2];
    string model;
    void get_value(){

  }
 };
class laptop_accessories: digital_products{
  protected:
  bool laptop_specific;
  public:
     string model;
 };
class cpu:public laptop_accessories{
 private:
 int core_number;
 string model;
 public:
  cpu(int a,string b){
  core_number=a;
  model=b;
  }
  cpu(){}

  void get_value(){}
 };
 class gpu:public laptop_accessories{
private:
    int capacity;
    string model;
public:
    gpu(int c,string d){
        capacity=c;
        model=d;
    }
    gpu(){}
 void get_value(){}
 };
 class hard_drive:public laptop_accessories{
private:
    int capacity;
    bool ssd;
 public:
    hard_drive(bool e,string f){
        ssd=e;
        model=f;
    }
    hard_drive(){}
    bool laptop_specific(){
        if(model=="acer"||model=="apple"||model=="asus"||model=="dell"||model=="lenovo"){
            return true;
        }
        else
            return false;
    }
 void get_value(){
 }
 };
class laptop:public digital_products{
private:

    int ram;
    cpu laptop_cpu;
    gpu laptop_gpu;
    hard_drive laptop_hard;
    int weight;
    int resolution[2];
    string model;
public:
    laptop(){}

  void get_value(){}
};
class phone_accessories: digital_products{
protected:
    bool phone_specific;
    bool tablet_specific;
public:
    string model;
 };


 class headphone:public phone_accessories{
 private:
 string model;
 string color;
 public:
  headphone(string g,string f){
    model=g;
    color=f;
  }
  headphone(){}
   void get_value(){}
 };
 class cover:public phone_accessories{
 private:
 string color;
  cover(string h,string i){
    color=h;
    model=i;
  }

    void get_value(){}
 };
 class memory_card:public phone_accessories{
 private:
 int capacity;

    void get_value(){}
 };
 class orders{
 public:
    customer *c;
    phone *p;
    tablet *t;
    laptop *l;
    tv *tv1;
    headphone *h;
    cover *c1;
    cpu *cpu1;
    gpu *g1;
    hard_drive *h1;
    orders (customer x, phone a){
        c=new customer;
        *c=x;
        p=new phone;
        *p=a;
    }
    orders (customer x, tablet a){
        c=new customer;
        *c=x;
        t=new tablet;
        *t=a;
    }
    orders (customer x, laptop a){
        c=new customer;
        *c=x;
        l=new laptop;
        *l=a;
    }
    orders (customer x, tv a){
        c=new customer;
        *c=x;
        tv1=new tv;
        *tv1=a;
    }
    orders (customer x, headphone a){
        c=new customer;
        *c=x;
        h=new headphone;
        *h=a;
    }
    orders (customer x, cpu a){
        c=new customer;
        *c=x;
        cpu1=new cpu;
        *cpu1=a;
    }
    orders (customer x, gpu a){
        c=new customer;
        *c=x;
        g1=new gpu;
        *g1=a;
    }
    orders (customer x, hard_drive a){
        c=new customer;
        *c=x;
        h1=new hard_drive;
        *h1=a;
    }
    ~orders(){
        cout<<endl<<c->username<<endl<<"model";
         delete c;
        delete p;
        delete t;
        delete l;
        delete tv1;
        delete h;
        delete c1;
        delete cpu1;
        delete g1;
        delete h1;
    }


 };
 class baskets{
 public:
    customer *c;
    phone *p;
    tablet *t;
    laptop *l;
    tv *tv1;
    headphone *h;
    cover *c1;
    cpu *cpu1;
    gpu *g1;
    hard_drive *h1;
    baskets  (customer x, phone a){
        c=new customer;
        *c=x;
        p=new phone;
        *p=a;
    }

    baskets (customer x, tablet a){
        c=new customer;
        *c=x;
        t=new tablet;
        *t=a;
    }
    baskets (customer x, laptop a){
        c=new customer;
        *c=x;
        l=new laptop;
        *l=a;
    }
    baskets (customer x, tv a){
        c=new customer;
        *c=x;
        tv1=new tv;
        *tv1=a;
    }
    baskets (customer x, headphone a){
        c=new customer;
        *c=x;
        h=new headphone;
        *h=a;
    }
    baskets (customer x, cpu a){
        c=new customer;
        *c=x;
        cpu1=new cpu;
        *cpu1=a;
    }
    baskets (customer x, gpu a){
        c=new customer;
        *c=x;
        g1=new gpu;
        *g1=a;
    }
    baskets (customer x, hard_drive a){
        c=new customer;
        *c=x;
        h1=new hard_drive;
        *h1=a;
    }
    ~baskets(){
        cout<<endl<<c->username<<endl<<"model";
         delete c;
        delete p;
        delete t;
        delete l;
        delete tv1;
        delete h;
        delete c1;
        delete cpu1;
        delete g1;
        delete h1;
    }



 };
void menu(manager *x,customer *y){
    string a,b;
    cout<<"\ndear manager hi!\nusername:";
    cin>>a;
    cout<<"\npassword:";
    cin>>b;
    digital_products c;
    if(a==x->namekarbar&&b==x->ramz){
    int x=0;
    while (x!=8){
        cout<<"\n1.moshtari\t\t2.tedadmoshtari\n3.taghiikalaprice\t4.sood\n5.tedadkalakharidi\t6.modlaptap\n7.mianginsenmoshtari\t8.exit";
        cin>>x;
        if(x==1){
            string a;
            cin>>a;
            if (a==y->username){
                cout<<"\ntedad sefareshat:"<<1;
            }

        }
        else if (x==2){
                cout<<"\nall customers:"<<y->num_customer;

        }
        else if(x==3){
                int a;
                cin>>a;
                if(a==c.ID){}
                else {
                    cout<<"\nyou dont have eny";
                }

        }
        else if(x==4){
                int a;
                cin>>a;
                if(a==c.ID){}

                else {
                    cout<<"\nyou dont have eny";
                }

        }
        else if(x==5){
                int a;
                cin>>a;
                if(a==c.ID){}
                else {
                    cout<<"\nyou dont have eny";
                }

        }
        else if(x==6){
                int a;
                cin>>a;
                if(a==c.ID){}
                else {
                    cout<<"\nyou dont have eny";
                }

        }
        else if(x==7){
                int a;
                cin>>a;
                if(a==c.ID){

                }
                else {
                    cout<<"\nyou dont have eny";
                }

        }
    }
    }
    else {
        cout<<"\nyou are not modir";
    }
    }
void moratab_sazi(person y[],person x[],int n){
    for (int i=0;i<n;i++){
        x[i]=y[i];
	}
    for (int i=0; i<n;i++){
  	   for (int i=0; i<n-1;i++){
		 if (x[i].family>x[i+1].family)
	 	{
			swap (x[i],x[i+1]);
		 }
		 else if(x[i].family==x[i+1].family&&x[i].name>x[i+1].name)
  	        swap (x[i],x[i+1]);
        else if(x[i].family==x[i+1].family&&x[i].name==x[i+1].name&&x[i].id>x[i+1].id)
            swap (x[i],x[i+1]);
        else if(x[i].family==x[i+1].family&&x[i].name==x[i+1].name&&x[i].id==x[i+1].id&&x[i].tt>x[i+1].tt)
            swap (x[i],x[i+1]);
  	   }
	  }
	}
int main()
{
    person x[100];
    manager *a=new manager;
    customer *b=new customer;
    customer d;
    phone cp;
    baskets *bask=new baskets(d,cp);
    orders *order=new orders(d,cp);

    menu(a,b);
    fstream file1;
    file1.open("read.txt",ios::in);
    for(int i=0;!file1.eof();i++){
        file1>>x[i].name;
        file1>>x[i].family;
        file1>>x[i].id;
    }
    file1.close();
    file1.open("write.text",ios::out);
    for (int i=0;i<100;i++){
       srand(time(0));
       x[i].tt=rand() % (1385 - 1301) +1385;
       file1<<x[i].name<<endl<<x[i].family<<endl<<x[i].id<<endl<<x[i].tt<<endl;
    }

    person y[100];
    moratab_sazi(x,y,100);
    delete a;
    delete b;
    delete bask;
    delete order;
    return 0;
}
