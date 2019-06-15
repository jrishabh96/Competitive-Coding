#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    
    LL q,n,ans;
    vector<string> names;

	string temp;
	cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>temp;
    	names.push_back(temp);
    }

    sort(names.begin(), names.end());

    map<string,int> namesMap;
    for (int i = 0; i < names.size(); ++i)
    {
    	namesMap[ names[i] ] = i+1;
    }

    cin>>q;
    while(q--){
    	
    	ans = 0;

    	string inputName;
    	cin>>inputName;

    	for (int i = 0; i < inputName.length(); ++i)
    	{
    		ans += inputName[i]-'A'+1;
    	}

    	ans = ans * namesMap[ inputName ];
    	cout<<ans<<endl;
    }
    
    return 0;
}