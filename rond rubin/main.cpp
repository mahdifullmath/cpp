#include <iostream>
#include <windows.h>
using namespace std;

int main()
{

    int n;
    cout<<"how many process you want to add: ";
    cin>>n;
    int time[n];
    int maxt=0,maxti;

    string process[n];
    for (int i=0;i<n;i++){
        cout<<"process name?";
        cin>>process[i];
        cout<<"this process time?";
        cin>>time[i];
        if (time [i]>maxt){
            maxt=time[i];
            maxti=i;        }
    }
    cout<<"time slice for your round robin? ";
    int t;
    cin>>t;
    for (int m=1;maxt>0;){
        for(int i=0;i<n;i++){
            for(int j=0;j<t;j++,m++){
                if(time[i]<=0) break;
                cout<<"p"<<m<<" :\t"<<process [i];
                cout<<endl;
                Sleep(1000);
                time[i]--;
                if (i==maxti){
                    maxt--;
                }
            }
            //cout<<endl;
        }
    }
    return 0;
}
