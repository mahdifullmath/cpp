#include<iostream>
using namespace std;
class String
{
  private:
    char str[20];
  public:
    String();
    String(char x[20]);
    void Display();
    void ToUpper();
    int Digits();
    void Convert(char a,char b);
    String pluss(String b){
     String o;
     o.str[0]=str[0]+b.str[0];
    return o;
     };
};
String::String(){
    cin.ignore();
    cin.clear();
    cin.getline(str,20);
}
String::String(char x[20]){
    int i;
    for(i=0 ; x[i]!='\0' ; i++){
        str[i]=x[i];
    }
    str[i]=x[i];
}
void String::Display(){
    cout<<str;
    cout<<endl;
}
void String::ToUpper(){
    for(int i=0 ; str[i]!='\0' ; i++){
        if(str[i]>='a' && str[i]<='z')
          str[i]=str[i]+('A'-'a');
    }
}
int String::Digits()  {
    int s=0;
    for(int i=0 ; str[i]!='\0' ; i++){
        if(str[i]>='0' && str[i]<='9')
         s++;
    }
    return s;
}
void String::Convert(char a,char b){
    int i;
    for(int i=0 ; str[i]!='\0' ; i++){
        if(a==str[i])
         str[i]=b;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
int main(){
    String o1,o3;
    String o2("AliReza1389");
    //o2.Display();
    //o2.ToUpper();
    //o2.Display();
    //cout<<o2.Digits()<<endl;
    //o2.Convert('A','L');
    //o2.Display();
    o3=o1.pluss(o2);
    o3.Display();
    return 0;
}
