#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int MAX_RANGE = 1000009;
LL smallestDivisor[MAX_RANGE];
vector<LL> Primes;

//Fill the smallestDivisor array by using seive(). Smallest divisor meaning for 6 it will be 2. For 2 it will be 2.
void sieve(){
    smallestDivisor[1]=1;
    for (LL i = 2; i < MAX_RANGE; ++i)
    {
        if(smallestDivisor[i]==0){
            Primes.push_back(i);
            for (LL j = i; j < MAX_RANGE; j+=i){
                smallestDivisor[j]=i;
            }
        }
    }
}

// Prerequisite sieve() must be called before. Calculate sum of divisors. For ex. - 6 => 1,2,3=6 and 12 => 1,2,3,4,6=16
LL calcualteSumofDivisor(LL num){
    LL originalNum = num, sumofDivisor = 1;

    while( num > 1 ){
        LL count =0;
        LL divisor = smallestDivisor[num];
        while( num % divisor == 0 ){
            num /= divisor;
            count++;
        }
        sumofDivisor *= ( pow(divisor,count+1) - 1 )/( divisor - 1 );
    }

    return sumofDivisor - originalNum;
}


int main() {
    
    LL t,n,ans;

    set<LL> abundantNumbers;

    sieve();
    for (int i = 2; i < MAX_RANGE; ++i)
    {
        if( calcualteSumofDivisor(i) > i  ){
            abundantNumbers.insert(i);
        }
    }


    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;

        for (int i = 1; i <= n/2; ++i)
        {
            if( abundantNumbers.find(i) != abundantNumbers.end() && abundantNumbers.find(n-i) != abundantNumbers.end() ){
                ans=1;
                break;
            }
        }

        cout<<(ans==1?"YES":"NO")<<endl;
    }
    
    return 0;
}