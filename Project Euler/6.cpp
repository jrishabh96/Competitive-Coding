//  https://www.hackerrank.com/contests/projecteuler/challenges/euler006
#include<bits/stdc++.h>
using namespace std;

#define LL long long

// (Sum of first n natural number)^2 - (Sum of first n^2 natural number)^2
int main() {
    
    LL t,n,ans;

    cin>>t;
    
    while(t--){
    	
    	ans = 0;
    	cin>>n;

    	ans = n*(n+1)*(3*n*n-n-2)/12;

    	cout<<ans<<endl;
    }
    
    return 0;
}