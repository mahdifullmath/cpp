#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,dis;
    cin>>n;
    char x[n];
    int dis1=0;
    int dis2=0;
    int t;
    vector <int> dist;
    cin.ignore();
    cin.getline(x,n);
    for (int i=0;i<n;i++){
        dis=0;
        while(x[i]=='0'&&i<n){
            dis++;
            i++;
        }

        dist.push_back(dis);

    }
    sort(dist.begin(), dist.end());
    int max1,max2,max3;
    max1=dist.back();
    dist.pop_back();
    max2=dist.back();
    max3=max(max1/2,max2/2);
    int max4=max1/2;
    max3=max(max4/2,max3);
    std::vector<int>::iterator it = dist.begin() ;
    max3=min(*it,max3);
    cout << max3 ;
    return 0;
}
