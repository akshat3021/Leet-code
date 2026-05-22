#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());

    int count = 0;
    int last = -1e9;

    for (int x : nums) {
        int chosen = max(x - k, last + 1);
        if (chosen <= x + k) {
            count++;
            last = chosen;
        }
    }

    return count;
    }
};