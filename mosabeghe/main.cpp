#include <bits/stdc++.h>

using namespace std;
/*class player:
    {
        string name;
        string pos;
        int
    };
*/
int main()
{
    string name [30];
    string pos [30];
    int a[28][10];
    int sum [30];
    fill (sum,sum+30,0);
    for (int i=0;i<28;i++){
          cin>>name[i];
          cin>>pos[i];
          if (pos[i]=="GKP")
          for (int j=0;j<10;j++){
                cin>>a[i][j];
                if (a[i][0]>=60){
                    sum[i]=sum[i]+2;
                }
                if (a[i][1]>0){
                    sum[i]+=a[i][1]*6;
                }
                if(a[i][3]>0){
                    sum [i]-=
                }

          }
          else if (pos[i]=="DEF")
          for (int j=0;j<8;j++){
                cin>>a[i][j];
                if (a[i][0]>=60){
                    sum[i]=sum[i]+2;
                }
          }
          else if (pos[i]=="MID")
          for (int j=0;j<8;j++){
                cin>>a[i][j];
                if (a[i][0]>=60){
                    sum[i]=sum[i]+2;
                }

          }
          else if (pos[i]=="FWD")
          for (int j=0;j<7;j++){
                cin>>a[i][j];
                if (a[i][1]>=60){
                    sum[i]=sum[i]+2;
                }
          }

    }

    cout <<  << endl;
    return 0;
}
