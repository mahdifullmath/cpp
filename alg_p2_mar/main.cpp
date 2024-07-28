
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
 void backpack(int n,int W,int w[],int val[],bool include[],int sumw,int sumv,int i,int bestsum){

     if(sumw>W){
        include[i]=false;
        sumw=sumw-w[i];
        sumv=sumv-val[i];
        i--;
        if(sumv>bestsum)
            bestsum=sumv;
        disply(n,W,w,val,include,sumv,sumw);
        return;

     }
     else if(sumw==W){
        if(sumv>bestsum)
            bestsum=sumv;
        disply(n,W,w,val,include,sumv,sumw);
        include[i]=false;
        sumw=sumw-w[i];
        sumv=sumv-val[i];
        i--;
        return;

     }
    if (i<0||i>=n){
        return;
     }

     if(include[i]==true){
        include[i]=false;
        sumw=sumw-w[i];
        sumv=sumv-val[i];
        i--;
        backpack(n,W,w,val,include,sumw,sumv,i,bestsum);
     }
    include[i]=true;
     sumw=sumw+w[i];
     sumv=sumv+val[i];
        i++;
        backpack(n,W,w,val,include,sumw,sumv,i,bestsum);

    /*int sumw=0;
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
        disply(n,W,w,val,include,sumv,sumw);*/
 }
//--------------------------------------------------------------
/*void bazgashti(int n,int W,int w[],int val[],bool include[],int i){
    if (i==n){
        return;
    }
    else if(include[i]==false){
        backpack(n,W,w,val,include);
        include[i]=true;
    }
    else if(include[i]==true){
        bazgashti(n,W,w,val,include,i+1);
    }

}*/
//--------------------------------------------------------------
int main()
{
    int n=5;
    int W=50;
    int w[n]={10,10,10,20,30};
    int val[n]={10,10,20,25,40};
    int sumv=0,sumw=0,bestsum=0;
    int i=0;
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
   /* backpack(n,W,w,val,include);
    setfalse(include,n);
    for(int i=0 ,k=n-1;i<n-1;i++,k--){
            include[i]=true;
            backpack(n,W,w,val,include);
            setfalse(include,n);

          //if(i<k){
              for (int j=i;j<=n-i-2;j++){
                  include[j]=true;
              }
              backpack(n,W,w,val,include);
              setfalse(include,n);
         // }



      }*/
      //bazgashti(n,W,w,val,include,0);
      backpack(n,W,w,val,include,sumw,sumv,i,bestsum);
    return 0;
}



