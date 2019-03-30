// https://www.hackerrank.com/contests/projecteuler/challenges/euler008
#include<bits/stdc++.h>
using namespace std;

#define LL long long

//Simple brute force N*K*T
int main() {
    
    LL t,n,k,ans;
    string s;
    
    cin>>t;
    
    while(t--){
    	
    	ans = 0;
    	cin>>n>>k;

    	cin>>s;

    	LL prod=1;
    	for (int i = 0; i < s.length()-k; ++i)
    	{
    		prod=1;
    		for(int j=i; j<i+k; ++j){
    			prod = prod*(s[j]-'0');
    		}
    		ans = max(ans,prod);
    	}

    	cout<<ans<<endl;
    }
    
    return 0;
}
