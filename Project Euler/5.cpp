//  https://www.hackerrank.com/contests/projecteuler/challenges/euler005
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL gcd(LL a,LL b){

    LL c;
    while(a!=0){
        c=b%a;
        b=a;
        a=c;
    }
    return b;
}


int main() {
    
    LL t,n,ans,x;

    cin>>t;

    LL A[41];

    A[1]=1;

    //Precompute answer upto 40. Just calculate and divide greatest common divisor from last [1...N-1]
    for (int i = 2; i <=40; ++i)
    {

        x = gcd(A[i-1],i);
        A[i] = A[i-1]*i/x;
    }

    while(t--){

        ans = 0;
        cin>>n;

        ans = A[n];

        cout<<ans<<endl;
    }
    
    return 0;
}
