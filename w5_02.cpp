#include <bits/stdc++.h>
using namespace std;
bool Sum(vector<int>& nums, int key) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == key) {
            cout << "Pair found: (" << nums[left] << ", " << nums[right] << ")" << endl;
            return true;
        }
        else if (sum < key) {
            left++;   
        }
        else {
            right--; 
        }
    }
    return false;
}
int main() {
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int> nums = {10, 15, 3, 7};
    int key = 17;
    if (!Sum(nums, key)) {
        cout << "No pair found" << endl;
    }
    return 0;
}