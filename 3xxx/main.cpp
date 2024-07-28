#include <iostream>
#include <string.h>

using namespace std;
class had{
public:
    char name[20];
    int man=0;
    int i=0;
    int ha=0;
    int get=0;
    int man2=0;
    had (){
        cin>>name;
    }
    void dis(){
        cout<<name<<" "<<man2-man+get<<endl;
    }

    void gethad (char s[20],int t){
        if(strcmp(name,s)==0){
                get=get+t;
        }
    }
};
void geti(char s[20],had *x,int d,int n){
        if(strcmp(x[d].name,s)==0){
            cin>>x[d].man;
            cin>>x[d].i;
            if (x[d].i!=0)
            x[d].ha=x[d].man/x[d].i;
            x[d].man2=x[d].man-(x[d].i*x[d].ha);
            for (int z=0;z<x[d].i;z++){
                char m[20];

                cin>>m;
                for (int j=0;j<n;j++){
                    x[j].gethad(m,x[d].ha);
                }
            }
        }
    }

int main()
{
    char s[20];
    int n;
    cin>>n;
    had x[n];
    for (int i=0;i<n;i++){
        cin>>s,20;
        for (int j=0;j<n;j++){
            geti(s,x,j,n);
        }
    }

for (int i=0;i<n;i++){
    x[i].dis();
}
    return 0;
}
