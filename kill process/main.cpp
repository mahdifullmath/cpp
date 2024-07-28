#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    for (;1;){
    cout<<"input process name:";
    string s="taskkill /IM ";
    string prname;
    cin>>prname;
    string f=s+prname+".exe /F";
    const char *x=f.c_str();
 //   cout<<f;
    system(x);
    cout<<"do you want to kill another process?(y/n)";
    char t;
    cin>>t;
    if (t!='y'){
        break;
    }
    system("cls");
    }
}
