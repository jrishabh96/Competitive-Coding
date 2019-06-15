//  https://www.hackerrank.com/contests/projecteuler/challenges/euler021
#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX = 100005;
LL A[MAX];

LL sumOfDigit(LL num) {
    LL sum = 0;
    while (num) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

// Just try everything till 10^5
int main() {
    LL t, n;

    // sum_of_divisors(n),n
    map<LL, LL> seenSumDivisors;
    vector<LL> amicableNumbers;

    for (int i = 2; i < MAX; ++i) {
        LL sum = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                if (j * j == i)
                    sum += j;
                else
                    sum += (j + i / j);
            }
        }

        if (seenSumDivisors.find(sum) != seenSumDivisors.end() && seenSumDivisors[sum] == i) {
            amicableNumbers.push_back(sum);
            amicableNumbers.push_back(i);
        } else {
            seenSumDivisors[i] = sum;
        }
    }

    amicableNumbers.push_back(0);
    sort(amicableNumbers.begin(), amicableNumbers.end());

    LL tempAmicableNumberSum = 0;
    vector<LL> amicableNumberSum;

    for (int i = 0; i < amicableNumbers.size(); ++i) {
        tempAmicableNumberSum += amicableNumbers[i];
        amicableNumberSum.push_back(tempAmicableNumberSum);
    }

    cin >> t;
    while (t--) {
        cin >> n;
        LL upperIndex = upper_bound(amicableNumbers.begin(), amicableNumbers.end(), n) - amicableNumbers.begin() - 1;
        cout << amicableNumberSum[upperIndex] << endl;
    }

    return 0;
}