//  https://www.hackerrank.com/contests/projecteuler/challenges/euler018
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL Triangle[20][20];
LL MaxPathTriangle[20][20];

// Just calculate by saving max path for that node 
int main() {
    
    LL t,n,ans;

    cin>>t;
    
    while(t--){
    	
    	ans = 0;
    	cin>>n;
    	memset(Triangle,0,sizeof Triangle);
    	memset(MaxPathTriangle,0,sizeof MaxPathTriangle);

    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j <= i; ++j)
    			cin>>Triangle[i][j];

    	MaxPathTriangle[0][0] = Triangle[0][0];
    	for (int i = 0; i < n-1; ++i){
    		for (int j = 0; j <= i; ++j){
    			MaxPathTriangle[i+1][j] = max(MaxPathTriangle[i+1][j], Triangle[i+1][j] + MaxPathTriangle[i][j]);
    			MaxPathTriangle[i+1][j+1] = max(MaxPathTriangle[i+1][j+1], Triangle[i+1][j+1] + MaxPathTriangle[i][j]);
    		}
    	}

    	for (int i = 0; i < n; ++i)
    		ans = max(ans, MaxPathTriangle[n-1][i]);

    	cout<<ans<<endl;
    }
    
    return 0;
}
