#include <iostream>
using namespace std;
int main(){
    int a,t=1,x=0;
    cin>>a;
    for (int i=2;x<a;i++){
        t=1;
        for (int j=2;j<i;j++){
            if (i%j==0){
                t=0;
            }
        }
        if (t==1){
          x++;
          int o=1,z=0;
          cout<<endl;
          for (int d=i;z<x;d++){
             o=1;
             for (int j=2;j<d;j++){
                if (d%j==0){
                o=0;
                }
             }
             if (o==1){
             cout <<d<<" ";
             z++;
             }
           }
         }
    }
    return 0;
}
