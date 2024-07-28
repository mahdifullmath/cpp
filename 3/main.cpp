#include <iostream>

using namespace std;

int main()
{
    int n;
    char x[n];
    char y[n];
    cin>>n;
    cin.ignore();
    cin.getline(y,n);
    cin.ignore();
    cin.getline(x,n);
    int xi[n];
    j=0;
    sum=0;
    for (int i=0;i<n;i++){
        if (x[i]!=y[i]){
            if(x[i+1]!=y[i+1]){
                sum--;
            }
            sum++;
            x[j]=i;
            j++;
        }
     for (int i=0;i<j;i++){
        if (xi[i]+1)
     }
    }
    return 0;
}
