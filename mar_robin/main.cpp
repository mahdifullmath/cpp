#include <iostream>

#include <windows.h>

using namespace std;

int main()
{
int n,qt;
int sum=0;
cout<< "enter number of process: ";
cin>> n;
int A[n];

for(int i=0; i<n; i++){
cout<< "enter the burst time of p"<<i+1<<":";
cin>>A[i];
}
cout<< "enter the quantum time: ";
cin>> qt;

for(int i=0; i<n; i++){
    sum=sum+A[i];
}
while(sum>0){
    for(int j=0; j<n; j++){
        if(A[j]>=qt){
            for(int i=0; i<qt; i++){
                A[j]=A[j]-1;
                sum=sum-1;
                Sleep(1000);
                cout<<"p"<<j+1<<endl;
            }
        }
        else{
            for(int i=0; A[j]>0; i++){
                A[j]=A[j]-1;;
                sum=sum-1;
                Sleep(1000);
                cout<<"p"<<j+1<<endl;
            }
        }
    }
}

return 0;
}
