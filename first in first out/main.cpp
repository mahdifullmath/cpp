#include <iostream>
#include <string>
#include<windows.h>
//#include <queue>
using namespace std;
template<class t,int Max>
class priorityqueue1 {
private:
    t items[Max];
    int rear=-1;
public:
    void inserti(t x){
        items[++rear]=x;
    }
    t deletei(){
        t maxx=items[0];
        for (int i=0;i<rear;i++){
            swap (items[i],items[i+1]);
        }
        rear--;
        return maxx;

    }
    bool isempty(){
        if (rear==-1)
            return 1;
        else
            return 0;
    }
};

int main()
{

    int n;
    cout<<"how many process you want to add: ";
    cin>>n;
    priorityqueue1 <int,100> time;
    priorityqueue1 <string,100> process;
    for (int i=0;i<n;i++){
        cout<<"process name?";
        string p;
        cin>>p;
        process.inserti(p);
        cout<<"this process time?";
        int t;
        cin>>t;
        time.inserti(t);
    }
    for(int i=0,m=1;i<n;i++){
        string x=process.deletei();
        int t=time.deletei();
        for(int j=0;j<t;j++,m++){
            cout<<"p"<<m<<" :\t"<<x;
            cout<<endl;
            Sleep(100);
        }
        cout<<endl;
    }
    return 0;
}
