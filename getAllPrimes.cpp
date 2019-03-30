LL A[1000009];

vector<LL> Primes;


//Get all primestill 1e6
void sieve(){

    A[1]=1;
    
    for (LL i = 2; i < 1000009; ++i)
    {
        if(A[i]==0){
            Primes.push_back(i);
            for (LL j = 2*i; j < 1000009; j+=i)A[j]=1;
        }
    }
}
