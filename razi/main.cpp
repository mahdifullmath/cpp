#include <iostream>

using namespace std;
float avg(int &you);
float avg2(int &you);
int n;
int main()
{
    int g,f;
   cin>>n;
   int *you=new int[n];
   for(int i=0;i<n;i++){
    cin>>*(you+i);
   }
    g=avg(*you);
    f=avg2(*you);
   cout<<f<<endl<<g;
   delete[]you;
    return 0;
}
float avg(int &you){
    int sum=0;
    int *ps=&you;
    for(int i=0;i<n;i++){
        sum=sum+*(ps+i);
    }
    int g=0;
    float a=(float)sum/n;
    int i=0;
    for(i=0;i<n;i++){
       if(a>*(ps+i)){
        g++ ;
        }
    }
    return g;
 }
 float avg2(int &you){
     int sum=0;
     int *ps=&you;
     for (int i=0;i<n;i++){
         sum=sum+*(ps+i);
    }
    float a=(float)sum/n;
     int i;
     int f=0;

        for ( i=0;i<n;i++){
        if(a<*(ps+i))
        f++;
    }
    return f;
}
