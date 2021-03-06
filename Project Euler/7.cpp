// https://www.hackerrank.com/contests/projecteuler/challenges/euler007
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL A[1000009];

vector<LL> Primes;


//Get all primestill 1e6
void sieve(){

    A[1]=1;
    
    for (LL i = 2; i < 1000009; ++i)
    {
        if(A[i]==0){
            Primes.push_back(i);
            for (LL j = 2*i; j < 1000009; j+=i)A[j]=1;
        }
    }
}

// Precompute no. of primes till 10^6. No of primes ~ x/ln(x)
int main() {
    
    LL t,n,ans;

    cin>>t;
    sieve();
    
    while(t--){
    	
    	ans = 0;
    	cin>>n;

    	ans = Primes[n-1];

    	cout<<ans<<endl;
    }
    
    return 0;
}
