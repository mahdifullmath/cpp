#include <iostream>
#include <string.h>
#include <string>

using namespace std;
//------------------------------------------
void sortt(string a[],int n){
    string t;
    for (int j=0;j<n;j++){
        for (int i=0;i<n-1;i++){
 //          if (strcmp(a[i],a[i+1])){
            if (a[i]>a[i+1]){
 //               strcpy (t,a[i]);
                t=a[i];
  //              strcpy (a[i],a[i+1]);
                a[i]=a[i+1];
  //              strcpy (a[i+1],t);
                a[i+1]=t;

            }
        }
    }

}
//-----------------------------------------
int main()
{
    int n;
    cin>>n;
    string a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
     sortt (a,n);
   }
    for (int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
