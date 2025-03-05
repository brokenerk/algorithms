/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
#include <bits/stdc++.h>
using namespace std;

void heapPermutation(vector<int> a, int size) {

    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1) {
        for (auto elem: a)
            cout << elem << ' ';
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1);

        // if size is odd, swap 0th i.e (first)
        // and (size-1)th i.e (last) element
        // else If size is even, swap ith
        // and (size-1)th i.e (last) element
        if (size % 2 == 1) {
            a[0] = a[size - 1];
            a[size - 1] = a[0];
        }
        else {
            a[i] = a[size - 1];
            a[size - 1] = a[i];
        }
    }
}

int main() {
    vector<int> nums = {1,2,3};
    heapPermutation(nums, nums.size());
    return 0;
}