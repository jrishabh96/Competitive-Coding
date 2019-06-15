//  https://www.hackerrank.com/contests/projecteuler/challenges/euler017
#include <bits/stdc++.h>
using namespace std;

#define LL long long

string space = " ";

//  number to word 0-19
string TeenNTW[20]={
	"Zero",
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine",
	"Ten",
	"Eleven",
	"Twelve",
	"Thirteen",
	"Fourteen",
	"Fifteen",
	"Sixteen",
	"Seventeen",
	"Eighteen",
	"Nineteen"
};

// number to word from 0,10,20,30,40,...,90,100
string MultipleOfTenNTW[11]={
	"Zero",
	"Ten",
	"Twenty",
	"Thirty",
	"Forty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninety",
	"Hundred"
};

// number to word  1000 , 1000,000 ....
string PlacesNTW[6]={
	"Zero",
	"Thousand",
	"Million",
	"Billion",
	"Trillion",
	"Zillion"
};

string calculateWordTillThousand(LL n, bool isSpaceRequired){

	string word ="";
	if(n>=100){
		if(isSpaceRequired) word.append( space );
		word.append( TeenNTW[n/100]  );
		word.append( space );
		word.append( "Hundred" );
	}

	n=n%100;

	if(n==0) return word;

	if(n<=19){
		if(isSpaceRequired || word.length()!=0) word.append( space );
		word.append( TeenNTW[n] );
		return word;
	}

	if(isSpaceRequired || word.length()!=0) word.append( space );
	word.append( MultipleOfTenNTW[n/10]  );

	n=n%10;

	if(n==0) return word;

	if(isSpaceRequired || word.length()!=0) word.append( space );
	word.append( TeenNTW[n]  );

	return word;
}


int main() {

	LL t, n;
	cin >> t;

	while (t--) {
		cin>>n;

		string ans="";
		if(n==0){
			cout<<"Zero \n"<<endl;
			continue;
		}

		for (int i = 12; i > 0; i=i-3)
		{
			if(n>pow(10,i)){
				ans.append( calculateWordTillThousand( n/pow(10,i), ans.length() != 0 ) );
				ans.append( space );
				ans.append( PlacesNTW[i/3] );		
			}
			n=n% (LL)pow(10,i);
		}
		ans.append( calculateWordTillThousand( n, ans.length() != 0 ) );

		cout<<ans<<endl;
	}

	return 0;
}