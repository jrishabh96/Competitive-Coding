//  https://www.hackerrank.com/contests/projecteuler/challenges/euler014
#include<bits/stdc++.h>
using namespace std;

#define LL long long

const LL MAXIMUM = 5000001;

LL Count[MAXIMUM]; // 5*10^6
LL MaxCount[MAXIMUM]; // 5*10^6
LL MaxChainNumber[MAXIMUM]; // stores largest chain number till MAXIMUM

LL LongestChain(LL num){

	if(num<MAXIMUM && Count[num]!=-1){
		return Count[num];
	}

	LL chain;

	if(num%2==0){
		chain = 1 + LongestChain(num/2);
	}else{
		chain = 1 + LongestChain(3*num+1);
	}

	if(num<MAXIMUM) Count[num]=chain;

	return chain;
}

//Just calculate by following the path and save the step on every point
int main() {
    
    LL t,n,ans;

    cin>>t;

    for (int i = 0; i <MAXIMUM; ++i){
    	Count[i]=-1;
    }

    // Precompute the chain length for every number
    Count[1]=1;
    for (int i = 2; i <MAXIMUM; ++i){
    	LongestChain(i);
    }

    MaxCount[1]=1; 
    for (int i = 2; i <MAXIMUM; ++i){
    	MaxCount[i] = max( MaxCount[i-1],Count[i] );
    	MaxChainNumber[i]= MaxCount[i]==Count[i]? i : MaxChainNumber[i-1];// store largest chain number 
    }


    while(t--){
    	ans = 0;
    	cin>>n;
		
		ans = MaxChainNumber[n];

    	cout<<ans<<endl;
    }
    
    return 0;
}
