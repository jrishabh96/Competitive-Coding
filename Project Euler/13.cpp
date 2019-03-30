//  https://www.hackerrank.com/contests/projecteuler/challenges/euler013
#include<bits/stdc++.h>
using namespace std;

#define LL long long

string A[1009];

// Lets treat number as string as 50 digit number wont fit in any datatype
int main() {
    
    LL t,n;

    string ans;
    cin>>n;

    for( int i=0; i<n; i++){
    	cin>>A[i];
    	reverse(A[i].begin(), A[i].end()); // reverse to start from ones digit
    }

    LL leftover=0 ,sum=0 ;

	// Iterate over first 50 digits
	for (int j = 0; j < 50; ++j){

		sum = leftover ;

		for( int i=0; i<n; i++){
			sum += A[i][j] - '0'; // get number from char
		}

		ans.push_back(sum%10 +'0'); // convert to char
		leftover = sum/10;
	}

	// Till leftover is not finished
	while( leftover!=0 ){
		ans.push_back(leftover%10 +'0');
		leftover/=10;
	}

	reverse(ans.begin(), ans.end());

	//Show first 10 numbers
	for (int i = 0; i < 10; ++i){
		cout<<ans[i];
	}
    cout<<endl;

    return 0;
}
