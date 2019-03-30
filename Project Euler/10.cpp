// https://www.hackerrank.com/contests/projecteuler/challenges/euler010
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL A[1000009];
LL Sum[1000009];

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

//PrePopulate array till 1e6
void sumPrimes(){

    Sum[0]=Sum[1]=0;

    // Iterator for Primes vector
    int x=0;

    for( int i=2; i<1e6+5; i++){
        Sum[i] = Sum[i-1];
        if( A[i] == 0 ){
            // i is Prime just add i to Sum till i
            Sum[i]+=i;
        }
    }
}

//Constraints n <= 1e6
int main() {
    
    LL t,n,ans;

    cin>>t;

    sieve();
    sumPrimes();
    
    while(t--){
        
        ans = 0;
        cin>>n;

        ans = Sum[n];

        cout<<ans<<endl;
    }
    
    return 0;
}
