#include <iostream>
//include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>n;
    cin>>m;
    int t=0;
    int x[n][2];
    int x2[m][2];
    int worst=0;
    int ww=0;
    for (int i=0;i<n;i++){
        t=0;
        cin>>x[i][t];
        t=1;
        cin>>x[i][t];
    }
    for (int i=0;i<m;i++){
        t=0;
        cin>>x2[i][t];
        t=1;
        cin>>x2[i][t];
    }
    int rah=100;
    int rah2=100;
    int j=0;
    for (int i=0;rah>0||rah2>0;){
            if (x2[j][1]>x[i][1]){
                    worst=x2[j][1]-x[i][1];
                    if (ww<worst){
                        ww=worst;
                    }
                }
            if(rah-x[i][0]>rah2-x2[j][0]){
                rah=rah-x[i][0];
                i++;
                if (rah==0&&rah2>0){
                    j++;
                if (x2[j][1]>x[i][1]){
                    worst=x2[j][1]-x[i][1];
                }
                }

            }
            else if(rah-x[i][0]==rah2-x2[j][0]){
                rah2=rah2-x2[j][0];
                j++;
                rah=rah-x[i][0];
                i++;

            }
            else {
                rah2=rah2-x2[j][0];
                j++;
                if (rah==0&&rah2>0){
                    i++;
                if (x2[j][1]>x[i][1]){
                    worst=x2[j][1]-x[i][1];
                }
                }
                }
        }




    cout << ww ;
    return 0;
}
