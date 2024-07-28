
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n,bool include[])
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));

	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0){
				K[i][w] = 0;
				include [i]=false;
			}
			else if (wt[i - 1] <= w){
				K[i][w] = max(val[i - 1] +K[i - 1][w - wt[i - 1]],K[i - 1][w]);
				include[i]=true;
			}
			else{
				K[i][w] = K[i - 1][w];
				include [i]=false;
			}
		}
	}
	return K[n][W];
}

int main()
{
    int n;
    cout<<"tedad:";
    cin>>n;
	int val[n];
	for (int i=0;i<n;i++){
        cout<<"val"<<i+1<<":";
        cin>>val[i];
	}
	int wt[n];
    for (int i=0;i<n;i++){
        cout<<"weight"<<i+1<<":";
        cin>>wt[i];
	}
	int W;
	cout<<"knapSack weight:";
	cin>>W;
    bool include[n];
    for (int i=0;i<n;i++){
        include[i]=false;
    }
	cout <<"max value that knapSack can handel:"<< knapSack(W, wt, val, n,include);
	/*for (int i=0;i<n;i++){
            if (include [i])

	}*/

	return 0;
}



