#include <iostream>
//#include <stdlib.h>
#include <time.h>
//#include <limits>
#define x 10
#define inf 999
using namespace std;
void set_zero(const int n,int a[][x]){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
}
void display(int arr[][x], const int n){
    cout<<"---------------------------------\n";
    for (int i = 0; i <n; i++){
        for (int j = 0; j <n; j++){
            if (arr[i][j]<inf)
                cout << arr[i][j] << "\t";
            else{
                 cout  << "inf\t";
            }

        }
        cout << endl<<endl;
    }
    cout<<"---------------------------------\n";
}
void path(int q,int r,int p[][x]){
    if (p[q][r]!=0){
        path(q,p[q][r],p);
        cout<<"v"<<p[q][r]<<" ";
        path (p[q][r],r,p);
    }
}
void set_rand (const int n,int a[][x]){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i==j)
                a[i][j]=0;
            else{
                int t=rand()%5;
                if(t!=0){
                    a[i][j]=t;
                }
                else{
                    a[i][j]=inf;
                }
            }
        }
    }
}
void eq(int a[][x],int b[][x], const int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=b[i][j];
        }
    }
}
void floyd (const int n,int w[][x],int d[][x],int p[][x]){
    set_zero(n,p);
    eq(d,w,n);
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  if (d[i][j] > (d[i][k] + d[k][j])){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=k;

                }
            }
        }
    }

}

int main()
{
    srand(time(0));
    const int n=rand()%5+5;
    int w[n][x]={{0,1,inf,1,5},{9,0,3,2,inf},{inf,inf,0,4,inf},{inf,inf,2,0,3},{3,inf,inf,inf,0}};
    int d[n][x];
    int p[n][x];
    set_zero(n,p);
    set_rand(n,w);
    display(w,n);
    floyd(n,w,d,p);
    display(d,n);
    while (1){
        cout<<"\nwhat path?(-1,-1 to exit)";
        int q,r;
        cout<<"q=";
        cin>>q;
        cout<<"r=";
        cin>>r;
        if(q==-1)
            break;
        path(q,r,p);
    }
    cout <<"n="<< n << endl;
    return 0;
}
