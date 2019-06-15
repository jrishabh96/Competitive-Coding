//  https://www.hackerrank.com/contests/projecteuler/challenges/euler020
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL A[1009][1009];

LL sumOfDigit(LL num){
	LL sum = 0;
	while(num){
		sum += num%10;
		num = num/10;
	}
	return sum;
}


// Pre-populate Array till <= 1000
int main() {
    
    LL t,n;

    A[1][0]=A[0][0]=1;
    for (int i = 2; i <= 1000; ++i)
    {
    	LL sum=0;
    	for (int j = 0; j <= 1000; ++j)
	    {
	    	A[i][j] = A[i-1][j]*i + sum;
	    	sum = A[i][j] / 1000;
	    	A[i][j] = A[i][j] % 1000;
	    }
    }

    cin>>t;

    while(t--){
    	cin>>n;
    	LL digitSum = 0 ;
    	for (int i = 1000; i >= 0; --i)
    	{
    		digitSum += sumOfDigit( A[n][i] );
    	}
    	cout<<digitSum<<endl;
    }

    return 0;
}