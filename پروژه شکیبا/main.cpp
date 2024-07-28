#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
int o,d;
void menu();
class shakhs{
 public:
    string esm;
    string famil;
    int sen;
    char jensiat;
    shakhs(){}
    shakhs(string e,string f,int s,char j){
    esm=e; famil=f; sen=s; jensiat=j;}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ostad: public shakhs {
 private:
    int saatkar;
    static int hoghughpaye;
    int hoghugh(){
        if(saatkar>20){return ((saatkar-20)*2*hoghughpaye + 20*hoghughpaye);}
        else {return saatkar*hoghughpaye;}
        }
 public:
    ostad(string e="empty",string f="empty",int s=0,char j='-',int t=0):shakhs(e,f,s,j){saatkar=t;}
    ostad(int zaman){saatkar=zaman;}
    static void taghirehoghughpaye(){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(65)<<"Change Base Salary"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Hoghughepaye Ra Vared Konid"<<endl; cin>>hoghughpaye;
    int select;
    cout<<"\n[0]: Bazgasht Be Menu"<<endl;
    cin>>select;
    if(select==0) menu();
    }
    void chapostad(){
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(65)<<"Moshahede Liste Asatid"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<"Name"<<setw(8)<<"|"<<setw(11)<<"Family"<<setw(6)<<"|"<<setw(5)<<"Age"<<setw(3)<<"|"<<setw(8)<<"Gender"<<setw(3)<<"|"<<setw(13)<<"Time"<<setw(3)<<"|"<<setw(12)<<"BaseSalary"<<setw(3)<<"|";
    cout<<setw(10)<<"TotalSalary"<<setw(5)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<esm<<setw(8)<<"|"<<setw(11)<<famil<<setw(6)<<"|"<<setw(5)<<sen<<setw(3)<<"|"<<setw(8)<<jensiat<<setw(3)<<"|"<<setw(13)<<saatkar<<setw(3)<<"|"<<setw(12)<<hoghughpaye<<setw(3)<<"|";
    cout<<setw(10)<<hoghugh()<<setw(5)<<endl;

    }
    friend void chapostad2(int o);
    friend void daryaftostad(int d);
    }*pos;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ostad::hoghughpaye=10000;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class daneshju:public shakhs{
 private:
    float mian,payan,proje,tamrin;
    float nomrekol(){return (mian+payan+proje+tamrin);}
 public:
        static int java,php,python,cpp;
        string favorite;
        char darkhast[80];
        daneshju(string e="empty",string f="empty",int s=0,char j='-',string fav="-",float m=0,float pa=0,float po=0,float t=0):shakhs(e,f,s,j){
        mian=m; payan=pa; proje=po; tamrin=t; favorite=fav; strcpy(darkhast,"empty");
        while (m>5) {cout<<"Nomre Mianterm Ra Dobare Vared Konid: (Mahdude: 0 Ta 5)"<<endl; cin>>mian;}
        while (pa>10) {cout<<"Nomre Payanterm Ra Dobare Vared Konid: (Mahdude: 0 Ta 10)"<<endl; cin>>payan;}
        while (t>2) {cout<<"Nomre Tamrin Ra Dobare Vared Konid: (Mahdude: 0 Ta 2)"<<endl; cin>>tamrin;}
        while (po>3) {cout<<"Nomre Proje Ra Dobare Vared Konid: (Mahdude: 0 Ta 3)"<<endl; cin>>proje;}
        if(favorite=="java") java++;
        else if(favorite=="php") php++;
        else if(favorite=="python") python++;
        else if(favorite=="c++") cpp++;

        }

    void chapdaneshju(){
    cout<<setw(12)<<"Name"<<setw(8)<<"|"<<setw(11)<<"Family"<<setw(6)<<"|"<<setw(5)<<"Age"<<setw(3)<<"|"<<setw(8)<<"Gender"<<setw(3)<<"|"<<setw(8)<<"Favorite"<<setw(3)<<"|"<<setw(13)<<"Middle Term"<<setw(3)<<"|"<<setw(12)<<"Final Term"<<setw(3)<<"|";
    cout<<setw(10)<<"Project"<<setw(5)<<"|"<<setw(11)<<"Exercise"<<setw(5)<<"|"<<setw(12)<<"Total Score"<<setw(5)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<esm<<setw(8)<<"|"<<setw(11)<<famil<<setw(6)<<"|"<<setw(5)<<sen<<setw(3)<<"|"<<setw(8)<<jensiat<<setw(3)<<"|"<<setw(8)<<favorite<<setw(3)<<"|"<<setw(13)<<mian<<setw(3)<<"|"<<setw(12)<<payan<<setw(3)<<"|";
    cout<<setw(10)<<proje<<setw(5)<<"|"<<setw(11)<<tamrin<<setw(5)<<"|"<<setw(12)<<nomrekol()<<setw(5)<<endl;
       }

    friend void nomrebala(int d);
    friend void mashrut (int d);
    friend void daryaftdaneshju(int d);
    friend void chapdaneshju2(int d);
    friend void alaghemandi();
   }*pda;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int daneshju::php=0;
int daneshju::python=0;
int daneshju::java=0;
int daneshju::cpp=0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   void daryaftostad(int o){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(75)<<"Vared Kardane Etelaate Asatid"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;

   cout<<"Etelaate Asatid Ra Be In Surat Vared Konid: Name Family Age Gender Time"<<endl;
   for(int i=2;i<o;i++){
   cin>>(pos+i)->esm>>(pos+i)->famil>>(pos+i)->sen>>(pos+i)->jensiat>>(pos+i)->saatkar;}
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl;
   cin>>select;
   if(select==0) menu();
   }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   void chapostad2(int o){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(65)<<"Etelaate Asatid"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    float sum=0;
    cout<<setw(12)<<"Name"<<setw(8)<<"|"<<setw(11)<<"Family"<<setw(6)<<"|"<<setw(5)<<"Age"<<setw(3)<<"|"<<setw(8)<<"Gender"<<setw(3)<<"|"<<setw(13)<<"Time"<<setw(3)<<"|"<<setw(12)<<"BaseSalary"<<setw(3)<<"|";
    cout<<setw(10)<<"TotalSalary"<<setw(5)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<o;i++){
    cout<<setw(12)<<(pos+i)->esm<<setw(8)<<"|"<<setw(11)<<(pos+i)->famil<<setw(6)<<"|"<<setw(5)<<(pos+i)->sen<<setw(3)<<"|"<<setw(8)<<(pos+i)->jensiat<<setw(3)<<"|"<<setw(13)<<(pos+i)->saatkar<<setw(3)<<"|"<<setw(12)<<(pos+i)->hoghughpaye<<setw(3)<<"|"<<setw(12)<<(pos+i)->hoghugh()<<setw(3)<<endl;
    }
    for(int i=0;i<o;i++){sum+=(pos+i)->hoghugh();}
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Total Salary is: "<<sum<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int select;
    cout<<"\n[0]: Bazgasht Be Menu"<<endl;
    cin>>select;
    if(select==0) menu();
      }

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   void daryaftdaneshju(int d){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(86)<<"Vared Kardane Etelaate Daneshjuyan"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    cout<<"Nahveve Vared Kardane Etelaat: Name Family Age Gender Favorite MiddleTerm FinalTerm Project Exercise"<<endl;
    for(int i=2;i<d;i++){strcpy((pda+i)->darkhast,"empty");
    cin>>(pda+i)->esm>>(pda+i)->famil>>(pda+i)->sen>>(pda+i)->jensiat>>(pda+i)->favorite>>(pda+i)->mian>>(pda+i)->payan>>(pda+i)->proje>>(pda+i)->tamrin;
    while (((pda+i)->mian)>5) {cout<<"Nomre Mianterme "<<"["<<(pda+i)->esm<<" "<<(pda+i)->famil<<"] Ra Dobare Vared Konid: (Mahdude: 0 Ta 5)"<<endl; cin>>(pda+i)->mian;}
    while (((pda+i)->payan)>10) {cout<<"Nomre Payanterme "<<"["<<(pda+i)->esm<<" "<<(pda+i)->famil<<"] Ra Dobare Vared Konid: (Mahdude: 0 Ta 10)"<<endl; cin>>(pda+i)->payan;}
    while (((pda+i)->tamrin)>2) {cout<<"Nomre Tamrine "<<"["<<(pda+i)->esm<<" "<<(pda+i)->famil<<"] Ra Dobare Vared Konid: (Mahdude: 0 Ta 2)"<<endl; cin>>(pda+i)->tamrin;}
    while (((pda+i)->proje)>3) {cout<<"Nomre Projeye "<<"["<<(pda+i)->esm<<" "<<(pda+i)->famil<<"] Ra Dobare Vared Konid: (Mahdude: 0 Ta 3)"<<endl; cin>>(pda+i)->proje;}
    if(((pda+i)->favorite)=="java") (pda+i)->java++;
    else if(((pda+i)->favorite)=="php") (pda+i)->php++;
    else if(((pda+i)->favorite)=="python") (pda+i)->python++;
    else if(((pda+i)->favorite)=="c++") (pda+i)->cpp++;
       }
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl;
   cin>>select;
   if(select==0) menu();
      }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   void chapdaneshju2(int d){
    system("cls");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(70)<<"Etelaate Daneshjuyan"<<setw(20)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int tedad=0;
    int sum=0;
    cout<<setw(12)<<"Name"<<setw(8)<<"|"<<setw(11)<<"Family"<<setw(6)<<"|"<<setw(5)<<"Age"<<setw(3)<<"|"<<setw(8)<<"Gender"<<setw(3)<<"|"<<setw(8)<<"Favorite"<<setw(3)<<"|"<<setw(13)<<"Middle Term"<<setw(3)<<"|"<<setw(12)<<"Final Term"<<setw(3)<<"|";
    cout<<setw(10)<<"Project"<<setw(5)<<"|"<<setw(11)<<"Exercise"<<setw(5)<<"|"<<setw(12)<<"Total Score"<<setw(5)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<d;i++){ if(((pda+i)->esm)!="empty") tedad++;
    cout<<setw(12)<<(pda+i)->esm<<setw(8)<<"|"<<setw(11)<<(pda+i)->famil<<setw(6)<<"|"<<setw(5)<<(pda+i)->sen<<setw(3)<<"|"<<setw(8)<<(pda+i)->jensiat<<setw(3)<<"|"<<setw(8)<<(pda+i)->favorite<<setw(3)<<"|"<<setw(13)<<(pda+i)->mian<<setw(3)<<"|"<<setw(12)<<(pda+i)->payan<<setw(3)<<"|";
    cout<<setw(10)<<(pda+i)->proje<<setw(5)<<"|"<<setw(11)<<(pda+i)->tamrin<<setw(5)<<"|"<<setw(12)<<(pda+i)->nomrekol()<<setw(5)<<endl;
    }
    for(int i=0;i<d;i++){sum+=(pda+i)->nomrekol();}
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Average is: "<<(float)sum/tedad<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl;
   cin>>select;
   if(select==0) menu();
   }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void nomrebala(int d){
    system("cls");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(80)<<"Bartarinha"<<setw(20)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

        daneshju temp[1];
        for(int i=0;i<d-1;i++){
            for(int j=0;j<d-1;j++){
                if((pda+i)->nomrekol() < (pda+i+1)->nomrekol())
                    {temp[0]=*(pda+i);
                    (pda+i)=(pda+i+1);
                    *(pda+i+1)=temp[0];}
            }}

    cout<<setw(12)<<"Name"<<setw(8)<<"|"<<setw(11)<<"Family"<<setw(6)<<"|"<<setw(5)<<"Age"<<setw(3)<<"|"<<setw(8)<<"Gender"<<setw(3)<<"|"<<setw(8)<<"Favorite"<<setw(3)<<"|"<<setw(13)<<"Middle Term"<<setw(3)<<"|"<<setw(12)<<"Final Term"<<setw(3)<<"|";
    cout<<setw(10)<<"Project"<<setw(5)<<"|"<<setw(11)<<"Exercise"<<setw(5)<<"|"<<setw(12)<<"Total Score"<<setw(5)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<d;i++){if((pda+i)->nomrekol()>=16){
    cout<<setw(12)<<(pda+i)->esm<<setw(8)<<"|"<<setw(11)<<(pda+i)->famil<<setw(6)<<"|"<<setw(5)<<(pda+i)->sen<<setw(3)<<"|"<<setw(8)<<(pda+i)->jensiat<<setw(3)<<"|"<<setw(8)<<(pda+i)->favorite<<setw(3)<<"|"<<setw(13)<<(pda+i)->mian<<setw(3)<<"|"<<setw(12)<<(pda+i)->payan<<setw(3)<<"|";
    cout<<setw(10)<<(pda+i)->proje<<setw(5)<<"|"<<setw(11)<<(pda+i)->tamrin<<setw(5)<<"|"<<setw(12)<<(pda+i)->nomrekol()<<setw(5)<<endl;
    }}

   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl;
   cin>>select;
   if(select==0) menu();
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void mashrut(int d){
    system("cls");
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(86)<<"Mashrut Shodegan"<<setw(20)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<"Name"<<setw(8)<<"|"<<setw(11)<<"Family"<<setw(6)<<"|"<<setw(5)<<"Age"<<setw(3)<<"|"<<setw(8)<<"Gender"<<setw(3)<<"|"<<setw(8)<<"Favorite"<<setw(3)<<"|"<<setw(13)<<"Middle Term"<<setw(3)<<"|"<<setw(12)<<"Final Term"<<setw(3)<<"|";
    cout<<setw(10)<<"Project"<<setw(5)<<"|"<<setw(11)<<"Exercise"<<setw(5)<<"|"<<setw(12)<<"Total Score"<<setw(5)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<d;i++){
    if((pda+i)->nomrekol() <10){
    cout<<setw(12)<<(pda+i)->esm<<setw(8)<<"|"<<setw(11)<<(pda+i)->famil<<setw(6)<<"|"<<setw(5)<<(pda+i)->sen<<setw(3)<<"|"<<setw(8)<<(pda+i)->jensiat<<setw(3)<<"|"<<setw(8)<<(pda+i)->favorite<<setw(3)<<"|"<<setw(13)<<(pda+i)->mian<<setw(3)<<"|"<<setw(12)<<(pda+i)->payan<<setw(3)<<"|";
    cout<<setw(10)<<(pda+i)->proje<<setw(5)<<"|"<<setw(11)<<(pda+i)->tamrin<<setw(5)<<"|"<<setw(12)<<(pda+i)->nomrekol()<<setw(5)<<endl;
    }
    }
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl;
   cin>>select;
   if(select==0) menu();
 }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void khoruj(){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(75)<<"Exit"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Ba Movafaghiat Kharej Shodid"<<endl;}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void moasese(){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(75)<<"Darbareye Amuzeshgah"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"| Name Amuzeshgah | :"<<"Khansar College of Mathematics and Computer Science"<<endl<<endl;
    cout<<"| Tedade Asatid | : "<<o<<endl<<endl;
    cout<<"| Tedade Daneshjuyan | :"<<d<<endl<<endl;
    cout<<"| Liste Dorehaye Dar Hale Bargozari | : "<<"Java "<<"Python "<<"Php "<<"C++ "<<endl<<endl;
    cout<<"| Address | : "<<"Khansar,Isfahan,Iran"<<endl<<endl;
    cout<<"| Number | : "<<"03157770691-3"<<endl<<endl;
    cout<<"| Email | : "<<"info@khansar-cmc.ac.ir"<<endl<<endl;
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl<<endl;
   cin>>select;
   if(select==0) menu();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void alaghemandi(){
     system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(80)<<"Mizane Alaghemandi Be Zabanha"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(15)<<"Java"<<setw(15)<<"|"<<setw(15)<<"Python"<<setw(15)<<"|"<<setw(15)<<"Php"<<setw(15)<<"|"<<setw(15)<<"C++"<<setw(15)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(15)<<(pda+0)->java<<setw(15)<<"|"<<setw(15)<<(pda+0)->python<<setw(15)<<"|"<<setw(15)<<(pda+0)->php<<setw(15)<<"|"<<setw(15)<<(pda+0)->cpp<<setw(15)<<endl;
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl<<endl;
   cin>>select;
   if(select==0) menu();
 }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tajdidenazar(){
    daneshju d1;
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(86)<<"Sabte Darkhaste Tajdide Nazare Nomre"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\nLotfan Nam Va Name Khanevadegie Khod Ra Ba Fasele Vared Konid:"<<endl;
    cin>>d1.esm>>d1.famil;
    int dastresi=0;int k;
    for(int i=0;i<d;i++){
    if((d1.esm==(pda+i)->esm) && (d1.famil==(pda+i)->famil)){ k=i;dastresi=1;break;}}
       if (dastresi==1) {
            cout<<"Aknun Mitavanid Darkhaste Khod Ra Sabt Konid: (Tozihe Mokhtasar Dar Morede Darkhast)"<<endl;
            cin.ignore();
            cin.getline((pda+k)->darkhast,80);
            cout<<"Darkhaste Shoma Sabt Shod";
            }
       else
            cout<<"Shoma Be In Bakhsh Dastresi Nadarid!"<<endl;

   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl<<endl;
   cin>>select;
   if(select==0) menu();
 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void chaptajdidenazar(){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(65)<<"Liste Darkhastha"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(10)<<"Nam"<<setw(10)<<"|"<<setw(25)<<"Name Khanevadegi"<<setw(10)<<"|"<<setw(45)<<"Sharhe Darkhast"<<setw(15)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<d;i++){
      if(strcmp((pda+i)->darkhast,"empty" )!=0){
        cout<<setw(10)<<(pda+i)->esm<<setw(10)<<"|"<<setw(25)<<(pda+i)->famil<<setw(10)<<"|"<<setw(45)<<(pda+i)->darkhast<<setw(15)<<endl;}
                  }
   int select;
   cout<<"\n[0]: Bazgasht Be Menu"<<endl<<endl;
   cin>>select;
   if(select==0) menu();
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(){
    system("cls");
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(65)<<"Menu"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\nLotfan Gozineye Morede Nazar Ra Entekhab Konid"<<endl<<endl;
    cout<<"[1]: Moshahedeye Etelaate Daneshjuyan"<<endl;
    cout<<"[2]: Moshahedeye Etelaate Asatid"<<endl;
    cout<<"[3]: Moshahedeye Daneshjuyane Bartar"<<endl;
    cout<<"[4]: Moshahedeye Daneshjuyane Mashrut Shode"<<endl;
    cout<<"[5]: Sabte Etelaate Asatid"<<endl;
    cout<<"[6]: Taghire Hoghughpaye Asatid"<<endl;
    cout<<"[7]: Sabte Etelaate Daneshjuyan"<<endl;
    cout<<"[8]: Darkhaste Tajdide Nazare Nomre"<<endl;
    cout<<"[9]: Moshahedeye Darkhastha"<<endl;
    cout<<"[10]: Moshahede Mizane Alaghemandi Be Zabanhaye Mokhtalef "<<endl;
    cout<<"[11]: Darbareye Amuzeshgah"<<endl;
    cout<<"[0]: Khoruj"<<endl;
    int gozine;
    cin>>gozine;
    switch(gozine){
        case 1:
            chapdaneshju2(d);
            break;
        case 2:
            chapostad2(o);
            break;
        case 3:
            nomrebala(d);
            break;
        case 4:
            mashrut(d);
            break;
        case 5:
            daryaftostad(o);
            break;
        case 6:
            ostad::taghirehoghughpaye();
            break;
        case 7:
            daryaftdaneshju(d);
            break;
        case 8:
            tajdidenazar();
            break;
        case 9:
            chaptajdidenazar();
            break;
        case 10:
            alaghemandi();
            break;
        case 11:
            moasese();
        case 0:
            khoruj();
            break;
        }

    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(65)<<"Welcome"<<setw(20)<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Lotfan Tedade Asatid Ra Vared Konid: (Vorudie Sahih: Tedad>=2) ";
    cin>>o;
    cout<<"Lotfan Tedade Daneshjuyan Ra Vared Konid: (Vorudie Sahih: Tedad>=2) ";
    cin>>d;
    ostad listo[o];
    pos=&listo[0];
    daneshju listd[d];
    pda=&listd[0];
    listd[0]={"Reza","Alian",20,'M',"php",5,10,3,2};
    listd[1]={"Maryam","Rezaei",21,'F',"python",5,8,2,1};
    listo[0]={"Ali","Rezaei",40,'M',25};
    listo[1]={"Reza","Hasani",30,'M',10};
    menu();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
