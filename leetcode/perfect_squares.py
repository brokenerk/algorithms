# Given an integer n, return the least number of perfect square numbers that sum to n.

# A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

# Example 1:

# Input: n = 12
# Output: 3
# Explanation: 12 = 4 + 4 + 4.
# Example 2:

# Input: n = 13
# Output: 2
# Explanation: 13 = 4 + 9.
 

# Constraints:

# 1 <= n <= 104

import math

def numSquares(n: int) -> int:
    # Create a dynamic programming table
    # to store sq and getMinSquares table
    # for base case entries
    dp = [0, 1, 2, 3]

    # getMinSquares rest of the table 
    # using recursive formula
    for i in range(4, n + 1):
        
        # max value is i as i can always 
        # be represented as 1 * 1 + 1 * 1 + ...
        dp.append(i)

        # Go through all smaller numbers 
        # to recursively find minimum
        for x in range(1, int(math.ceil(math.sqrt(i))) + 1):
            temp = x * x
            if temp > i:
                break
            else:
                dp[i] = min(dp[i], 1 + dp[i-temp])

    # Store result
    return dp[n]

print(numSquares(12))