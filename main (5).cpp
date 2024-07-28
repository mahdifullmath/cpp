
#include <iostream>
using namespace std;
void setfalse(bool x[],int n){
    for(int i=0;i<n;i++){
        x[i]=false;}
}
//---------------------------------------------------------------------------
void disply(int n,int W,int w[],int val[],bool include[],int sumv,int sumw){
    for(int i=0;i<n;i++){
        if (include[i]==true){
            cout<<"item("<<i+1<<"),";
        }
    }
    cout<<"\nsum of vals:"<<sumv;
    cout<<"\nsum of weights:"<<sumw<<endl<<endl;
}
//--------------------------------------------------------
 void backpack(int n,int W,int w[],int val[],bool include[]){
    int sumw=0;
    int sumv=0;
    int i=0;
    for(;i<n;i++){
        if (include[i]==false){
            include[i]=true;
            sumw=sumw+w[i];
            sumv=sumv+val[i];
        }
        else{
            include[i]=false;
        }
        if(sumw>W){
            sumw=sumw-w[i];
            sumv=sumv-val[i];
            include[i]=false;
            i=i-1;
            disply(n,W,w,val,include,sumv,sumw);
            return;
            }
        else if(sumw==W){
            disply(n,W,w,val,include,sumv,sumw);
            return;
        }

    }
    if(i==n)
        disply(n,W,w,val,include,sumv,sumw);
 }
//--------------------------------------------------------------
int main()
{
    int n=3;
    int W=50;
    int w[3]={10,20,30};
    int val[3]={20,25,40};
    bool include[n];
    setfalse(include,n);
    /*int n;
      cout<<"enter number of object:";
      cin>>n;
      int w[n],val[n];
      bool include[n];
      setfalse(include,n);
      int W;
      cout<<"enter total weight:";
      cin>>W;
      for(int i=0;i<n;i++){
        cout<<"enter weight("<<i+1<<"):";
        cin>>w[i];
        cout<<"enter value("<<i+1<<"):";
        cin>>val[i];
      }*/
    backpack(n,W,w,val,include);
    setfalse(include,n);
    for(int i=0;i<n-1;i++){

          for (int j=0;j<=i;j++){
              include[j]=true;

          }
          backpack(n,W,w,val,include);
          setfalse(include,n);
          if (i>0){
              include[i]=true;
              backpack(n,W,w,val,include);
              setfalse(include,n);
          }


      }
    return 0;
}



