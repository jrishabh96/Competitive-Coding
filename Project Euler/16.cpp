//  https://www.hackerrank.com/contests/projecteuler/challenges/euler016
#include <bits/stdc++.h>
using namespace std;

#define LL long long

/*
 Magic number in last arises from 2^10 ~ number with 3 digits at the end.
 2^10000 will be with ~ 3000 digits . Store every digit of number in array form
 so end product will be

 {2}
 {4}
 {8}
 {6,1}
 {2,3}
 {4,6}
 ...
 {4,0,2,1}
 */

LL PowerOfTwo[10002][3030];

int main() {

    LL t, n, ans;
    cin >> t;

    memset(PowerOfTwo, 0, sizeof(PowerOfTwo));
    PowerOfTwo[0][0] = 1;

    // Prepopulate PowerOfTwo array till 10^4
    for (int i = 1; i < 10001; ++i) {
        LL leftOverSum = 0;
        for (int j = 0; j < 3030; ++j) {
            PowerOfTwo[i][j] = 2 * PowerOfTwo[i - 1][j] + leftOverSum;
            leftOverSum = PowerOfTwo[i][j] / 10;
            PowerOfTwo[i][j] = PowerOfTwo[i][j] % 10;
        }
    }

    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < 3030; ++i) {
            ans += PowerOfTwo[n][i];
        }
        cout << ans << endl;
    }

    return 0;
}
// Note: Here u can also use string instead of an array to save space