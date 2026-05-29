class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> present(mx + 1, false);
        for (int x : nums) {
            present[x] = true;
        }

        vector<int> best(mx + 1, 0);

        for (int d = 1; d <= mx; ++d) {
            if (!present[d]) continue;

            for (int multiple = d; multiple <= mx; multiple += d) {
                if (present[multiple] && best[multiple] == 0) {
                    best[multiple] = d;
                }
            }
        }

        long long ans = 0;
        
        for (int x : nums) {
            ans += best[x];
        }

        return ans;
    }
};
