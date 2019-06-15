#include<bits/stdc++.h>
using namespace std;

#define LL long long

const LL MOD = 1e9+7;

// pre calculate for 500*500
LL Box[505][505];


int main() {
    
    for (int i = 1; i < 505; ++i){
        for (int j = 1; j < 505; ++j){
            if(i==1 && j==1) 
                Box[1][1]=1; // starting from (1,1) to avoid the hassel
            else 
                Box[i][j] = (Box[i-1][j] + Box[i][j-1]) %MOD;
            
        }
    }

    LL t,n,m,ans;

    cin>>t;
    
    while(t--){
        
        ans = 0;
        cin>>n>>m;

        ans = Box[n+1][m+1];

        cout<<ans<<endl;
    }
    
    return 0;
}
// Alternate way (n+m)Cm