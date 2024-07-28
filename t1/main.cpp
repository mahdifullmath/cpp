#include<iostream>
using namespace std;
float avrageodd (int *s,int n);
int main (){
    int n;
    cin>>n;
    int *s=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cout<<"avgodd = "<<avrageodd(s,n);
    return 0;
}
float avrageodd (int *t,int n)
{
    int sum=0,s=n/2+n%2;
	for(int i=0;i<n;i+=2){
         sum=sum+t[i];
    }
    return (float)sum/s;
}
