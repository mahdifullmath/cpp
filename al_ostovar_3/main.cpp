#include <iostream>
#include <queue>
using namespace std;
struct node{
    int level;
    int profit;
    int weight;
};
float bound (node u,int n, int p[], int w[], int W) {
    int i=0, k=0;
    int totweight;
    float result;
    if (u.weight >= W) return 0;
    else {
        result = u. profit;
        i = u. level-1 ;
        totweight = u.weight;
        while (i<= n && totweight + w[i] <= W){
            totweight= totweight + w[i];
            result = result + p[i];
            i++;
        }
        k = i;
        if (k <=n)
            result = result + (W - totweight) * p[k]/w[k]; // Grab fraction of kth item
        cout<<result<<" ";
        return result;
    }
}
/*void knapsack3 (int n, int p[], int w[], int W, int& maxprofit) {
    queue <node> PQ;
    node u, v;
    //Initialize (PQ);
// Initialize PQ to be empty
    v. level = 0; v. profit = 0; v. weight = 0;
// Initialize v to be the root
    maxprofit = 0;
    v. bound = bound(v,n,p,w,W);
    PQ.push(v);
    while (!PQ.empty()){
        //remove (PQ, v);
        v=PQ.front();
        PQ.pop();
        if (v.bound > maxprofit) {
            u.level= v.level + 1;
            u.weight = v. weight + w[u.level];
            u. profit = v. profit + p[u. level];
            if (u.weight <= W && u.profit > maxprofit)
                maxprofit = u. profit;
                u. bound = bound (u,n,p,w,W);
            if (u.bound> maxprofit)
                PQ.push(u);
            u. weight = v. weight;
            u. profit = v. profit;
            u. bound = bound (u,n,p,w,W);
            if (u.bound > maxprofit)
                PQ.push(u);
// Remove node with best bound.
// Check if node is still promising
// Set u to the child
// that includes the next item
// Set u to the child
// that does not include
// the next item.
}
}
}*/
void knapsack2 (int n, int p[], int w[], int W, int& maxprofit) {
    queue <node> PQ;
    node u, v;
    //Initialize (PQ);
// Initialize PQ to be empty
    v. level = 0; v. profit = 0; v. weight = 0;
// Initialize v to be the root
    maxprofit = 0;
   // v. bound = bound(v,n,p,w,W);
    PQ.push(v);
    while (!PQ.empty()){
        //remove (PQ, v);
        v=PQ.front();
        PQ.pop();
        u.level= v.level + 1;
        u.weight = v. weight + w[u.level];
        u. profit = v. profit + p[u. level];
        if (u.weight <= W && u.profit > maxprofit)
                maxprofit = u. profit;
            if (bound (u,n,p,w,W)> maxprofit){
                PQ.push(u);
            }
            u. weight = v. weight;
            u. profit = v. profit;
            if (bound (u,n,p,w,W) > maxprofit)
                PQ.push(u);
// Remove node with best bound.
// Check if node is still promising
// Set u to the child
// that includes the next item
// Set u to the child
// that does not include
// the next item.

}
}


int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    int W;
    cout<<"W=";
    cin>>W;
    int w[n];
    int p[n];
    float pw[n];
    for(int i=0;i<n;i++){
        cout<<"w=";
        cin>>w[i];
        cout<<"p=";
        cin>>p[i];
        pw[i]=p[i]/w[i];
    }
    for (int i=0; i<n;i++){
        for (int j=0; i<n-1;i++){
            if (pw[j]<pw[j+1]){
                swap(pw[j],pw[j+1]);
                swap(p[j],p[j+1]);
                swap(w[j],w[j+1]);
            }
        }
    }
    int maxprofit=0;

    knapsack2(n,p,w,W,maxprofit);
    cout << "max profit is:"<<maxprofit << endl;
    return 0;
}

