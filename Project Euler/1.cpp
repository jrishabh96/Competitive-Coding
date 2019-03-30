//  https://www.hackerrank.com/contests/projecteuler/challenges/euler001
#include<bits/stdc++.h>
using namespace std;

#define LL long long


/*
 noe - Number of elements
 num - Element to be multiplied with

 Returns sum of all multiple of num from [1....noe]
*/
LL getSum(LL noe, LL num){
    return noe*(noe+1)*num/2;
}



int main() {
    
    LL t,n,ans,threeRange,fiveRange,fifteenRange;
    cin>>t;
    
    while(t--){

        ans = 0;
        cin>>n;
        n--;
        
        threeRange = (LL)(n/3);
        fiveRange = (LL)(n/5);
        fifteenRange = (LL)(n/15);
        
        ans = getSum(threeRange,3) + getSum(fiveRange,5) - getSum(fifteenRange,15) ;
        
        cout<<ans<<endl;
    }
    
    return 0;
}

