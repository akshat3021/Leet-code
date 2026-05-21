#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }
        vector<string> ans;
        int miniSum = INT_MAX;
        for (int j = 0; j < list2.size(); j++) {
            if (mp.find(list2[j]) != mp.end()) {
                int sum = j + mp[list2[j]];
                if (sum < miniSum) {
                    miniSum = sum;
                    ans.clear();
                    ans.push_back(list2[j]);
                }
                else if (sum == miniSum) {
                    ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};