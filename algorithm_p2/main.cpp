#include <iostream>

using namespace std;
bool promising(int i,int w[],int W,int weight,int total){
    return(weight+total>=W)&&(weight==W||weight+w[i]<=W);
}
void sum_of_sub(int i , int weight , int total,int w[],int W,string include[]){
    if(promising(i,w,W,weight,total)){
        if (weight==W){
            for (int j=0;j<i;j++){
                if (include[j]=="yes")
                    cout<<"w"<<j+1<<" ";
            }
            cout<<endl;

        }
        else{
            include[i]="yes";
            sum_of_sub(i+1,weight+w[i],total-w[i],w,W,include);
            include[i]="no";
            sum_of_sub(i+1,weight,total-w[i],w,W,include);
        }
    }

}
//--------------------------------------------------------------------------------------------------
int main()
{
    int n;
    int W;
    string include[n];
    cout<<"n:";
    cin>>n;
    int w[n];
    cout<<"weights :";
    for(int i=0;i<n;i++){
        cout<<"w"<<i+1<<":";
        cin>>w[i];
    }
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0,temp; j<(n-i-1); j++)
        {
            if(w[j]>w[j+1])
            {
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }

    cout<<"\ninsert W:";
    cin>>W;
    int weight=0;
    int total=0;
    for(int i=0;i<n;i++){
        total+=w[i];
    }

    for(int i=0;i<n;i++){
        include[n]="no";
    }
    sum_of_sub(0,weight,total,w,W,include);
    cout <<"program end!" << endl;
    return 0;
}
