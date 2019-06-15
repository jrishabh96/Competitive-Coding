const int MAX_RANGE = 1000009;
LL seenValue[MAX_RANGE];

vector<LL> Primes;

//Get all primestill 1e6
void sieve(){

    seenValue[1]=1;
    for (LL i = 2; i < MAX_RANGE; ++i)
    {
        if(seenValue[i]==0){
            Primes.push_back(i);
            for (LL j = 2*i; j < MAX_RANGE; j+=i)seenValue[j]=1;
        }
    }
}