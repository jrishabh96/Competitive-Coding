//	https://www.hackerrank.com/contests/projecteuler/challenges/euler004
#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<LL> Palindromes;

LL reverse(LL num){

    LL reverseNum=0;

    while(num!=0){
        reverseNum = reverseNum*10 + num%10;
        num = num/10;
    }

    return reverseNum;
}

bool isPalindrome(LL num){
    return num == reverse(num) ;
}


void getPalindromes(){

    LL num;

    for (LL i = 100; i <= 999; ++i)
    {
        for (LL j = 100; j <= 999; ++j)
        {
            num = i*j;
            if(isPalindrome(num)){
                Palindromes.push_back(num);
            }
        }
    }
    sort(Palindromes.begin(),Palindromes.end());
}

// Simply get All Palindromes for [100-999]*[100-999] and binarySearch against required number N.
int main() {
    
    LL t,n,ans;

    cin>>t;

    getPalindromes();
    
    while(t--){
        
        ans = 0;
        cin>>n;

        int pos = lower_bound(Palindromes.begin(), Palindromes.end(), n)  - Palindromes.begin() ; 
        while(Palindromes[pos]>=n){
            pos--;
        }  
        ans = Palindromes[pos];
        cout<<ans<<endl;
    }
    
    return 0;
}
