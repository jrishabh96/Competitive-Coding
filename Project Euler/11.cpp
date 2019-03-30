// https://www.hackerrank.com/contests/projecteuler/challenges/euler011
#include<bits/stdc++.h>
using namespace std;

#define LL long long

const int N=20, M=20;

LL A[N][M];

// 8 directions - Here u can reduce to 4 directions
int dx[8] = { -1,-1,-1, 0,0, 1,1,1 };
int dy[8] = { -1, 0, 1,-1,1,-1,0,1 };



// Number of directions
const int DIRECTIONS = 8 ;

// 4 numbers to be selected
const int COUNT = 4 ;

// Check if in the Bounds  0 <= i < N, 0 <= j < M 
bool isValid(int i, int j){

    if( i>=0 && i<N && j>=0 && j<M )
        return true;

    return false;
}

//find max Product starting at pos x,y
LL getMaxProduct(int x, int y){

    LL maxProduct = 0; 
    for (int i = 0; i < DIRECTIONS; ++i)
    {
        LL temp_i = x, temp_j = y;

        LL product  = 1;
        for (int j = 0; j < COUNT; ++j){

            if( !isValid(temp_i,temp_j) ){
                // Dont consider this case going out of bound
                product=0;
                break;
            }
            product = product * A[temp_i][temp_j];
            temp_i += dx[i]; temp_j += dy[i];
        }

        maxProduct = max( maxProduct, product );
    }
    
    return maxProduct;
}


int main() {
    
    LL ans =0 ;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin>>A[i][j];

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){

            //find max Product starting at pos x,y
            LL maxProduct = getMaxProduct(i,j);
            ans = max(ans,maxProduct);
        }
    }

    cout<<ans<<endl;

    return 0;
}
