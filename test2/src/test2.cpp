
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int best_karmand (int a[][1000],int n,int j){
	int best=a[0][j];
	int best_t=0;
	for (int t=0;t<n;t++){
		if(a[t][j]<best){
			best=a[t][j];
			best_t=t;
		}

	}
	return best_t;
};
int best_kar (int a[][1000],int n,int i){
	int best=a[i][0];
	int best_t=0;
	for (int t=0;t<n;t++){
		if(a[i][t]<best){
			best=a[i][t];
			best_t=t;
		}

	}
	return best_t;
};
int main() {
	int x;
	cin >> x;
	int kar[x][1000];

	for(int i=0;i<x;i++){
		for (int j=0;j<x;j++){
			cin>>kar[i][j];
		}
	}
    int best_karmand1[x];
    int best_kar1[x];
    for (int i=0;i<x;i++){
        best_karmand1[i]=best_karmand(kar,x,i);
        best_kar1[i]=best_kar(kar,x,i);
    }
    for (int i=0;i<x;i++){
	    cout << best_karmand1[i]<< endl;
    }
	return 0;
}
