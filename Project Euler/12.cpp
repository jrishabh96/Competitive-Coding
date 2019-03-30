// https://www.hackerrank.com/contests/projecteuler/challenges/euler012
#include<bits/stdc++.h>
using namespace std;

#define LL long long

const LL MAX = 100009;
LL Divisors[MAX];

void calculateNumberOfDivisors(){

    Divisors[1] = (LL)1;

    LL tempi, tempCounter;

    for (int i = 2; i<MAX; ++i)
    {
    	tempi = i;
    	Divisors[i] = (LL)1;

    	LL sqrti = (LL)sqrt(i);
        for (int j = 2; j <= sqrti; ++j)
        {
        	tempCounter = 0;
        	while( tempi%j == 0 ){
				tempi /= j;tempCounter++; 	
        	}
        	Divisors[i] *= (tempCounter+1);
        }
    }

}

/* 
 * Number of Divisors = (p1+1)*(p2+1)....(pn+1) where p1 is count of first prime and so on
 * 
 * Triangle numbers are in form n*(n+1)/2 where n=1,2,3
 * Consecutive number do not have divisor in common
 * So we can precompute number of divisor from 1 to n.
 * For that we need to get count of number of primes for each number
 *
 * Crude calculation - Take p1=p2=...=pn=1, 2^10 = 1024 , 
 * First 10 prime numbers => multiply them => 4e9 = 4 * 10^9 
 * So we need to calculate till n = 10^5 and precalculate, taking n*(n+1)/2 = 10^10
 *
 */
int main() {
    
    LL t,n,ans;

    cin>>t;

    calculateNumberOfDivisors();
    
    // T<=10 Scan from brute force
    while(t--){

    	ans=0;
    	cin>>n;

    	for (int i = 1; i <= 1e5; ++i)
    	{
    		if(Divisors[i]>n){
    			ans=Divisors[i];
    			break;
    		}
    	}

    	cout<<ans<<endl;
    }
    
    return 0;
}


/**
	If T was large
	Lets store max divisors from 1 to i in Divisors[i]. 
    From this we can get increasing of Divisors[i] removing unwanted values
    Divisors[i] = max( Divisors[i], Divisors[i-1] );
    Then BinarySearch
   */