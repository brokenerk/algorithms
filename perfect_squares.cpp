/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
*/
#include <bits/stdc++.h>
using namespace std;

int numSquares(int n) {
    vector<int> dp {0, 1, 2, 3};

    for (int i = 4; i < n + 1; i++) {
        dp.push_back(i);

        for (int x = 1; x < (int)(ceil(sqrt(i)) + 1); x++) {
            int temp = x * x;

            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1 + dp[i-temp]);
        }
    }

    return dp[n];
}

int main() {
    cout << numSquares(13) << endl;
    return 0;
}