#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
int x;
    cout<< " number of process: ";
    cin>> x;
int M[x];

 for(int i=0; i<x; i++){
    cout<< " time of process "<<i+1<<":";
    cin>>M[i];
}
    int Qt;
    cout<< " Quantum time: ";
    cin>> Qt;

    int s=0;
  for(int i=0; i<x; i++){
    s=s+M[i];
}
  while(s>0){
    for(int j=0; j<x; j++){
        if(M[j]>=Qt){
            for(int i=0; i<Qt; i++){
                s=s-1;
                M[j]=M[j]-1;
                cout<<"process"<<j+1<<endl;
                Sleep(2000);
            }
        }
        else{
            for(int i=0; M[j]>0; i++){
                s=s-1;
                M[j]=M[j]-1;
                cout<<"process"<<j+1<<endl;
                Sleep(2000);
            }
        }
    }
}

return 0;
}
