//  https://www.hackerrank.com/contests/projecteuler/challenges/euler002
#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    
    /* 
    *  Here n<=4*10^16 meaning fibonnaci numbers will be less than 100. As new number to be added will sum of last of two number.
    *  the list of numbers grow exponentially. 1.62x the previous number 
    */

    LL t,num,sum=0;
    LL A[102]={0};

    cin>>t;
    
    // Prepopulate fibonacci till 1e17
    A[1]=1;A[2]=2;
    LL a = 1 , b = 2 , c =3;  
    for(int i=3; i<=100 && c<=1e17 ; i++){
    	c=a+b;
    	A[i]=c;
    	a=b;b=c;
    } 
    
    while(t--){
    	cin>>num;
    	sum=0;
        	for(int i=1; i<=100 && num>A[i]; i++){
    	       if( A[i]%2 == 0 ){
    		      sum += A[i];	
    	       }	    
    	    }
    	cout<<sum<<endl;
    }
    
    return 0;
}
