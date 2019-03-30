// https://www.hackerrank.com/contests/projecteuler/challenges/euler009
#include<bits/stdc++.h>
using namespace std;

#define LL long long

// O(3000*3000)
int main() {
    
    LL t,n,k,ans;
    string s;

    // Triplet[c] = pair(a,b)  where a,b are MAX{a*b}; and a and b is a^2 + b^2 = c^2
    vector< pair<LL,LL> > Triplet[3003];


    LL a,b,c,b_squared;

    for (int i = 1; i <= 3000; ++i)
    {
        c = i;

        for (int j = 1; j < i; ++j)
        {
            a = j; 
            b_squared = c*c - a*a;

            b = (int)sqrt(b_squared);
            
            if( b*b == b_squared ){
                Triplet[c].push_back( make_pair(a,b) );
            }
        } 
    }
    
    cin>>t;

    // Here a + b + c = n and a*b*c should be max.
    while(t--){
        
        ans = -1;
        cin>>n;

        LL sumABC;

        // Tranverse array 
        for (int i = 1; i < n; ++i)
        {
            // Vector with c=i and iterating over pair contaning (a,b) where a^2 + b^2 = c^2
            for (int j = 0; j < Triplet[i].size(); ++j)
            {
                sumABC = i + Triplet[i][j].first + Triplet[i][j].second ; 
                // Check a+b+c == n or not
                if( sumABC == n ){
                    ans = max(ans,i*Triplet[i][j].first*Triplet[i][j].second);
                }
            }
        }

        cout<<ans<<endl;
    }
    
    return 0;
}

/**
Another way of doing it is by solving equations

a^2 + b^2 = c^2
a + b + c = n

c = n - a - b
b = ( n^2 - 2*n*a )/( 2*n - 2*a )
a iterate over 1 to n (u can reduce search here) 

**/