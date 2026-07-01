class Solution {
public:
    int sumD(int num) {
        int sum = 0;
        num = abs(num);
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = sumD(nums[i]);
        }
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
