class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>diff={0};
        for(int i = 0 ;i<gain.size();i++){
            int sum = diff[i]+gain[i];
            diff.push_back(sum);
        }
        sort(diff.begin(),diff.end());
        return diff[diff.size()-1];
    }
};
