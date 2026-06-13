class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;

        for (const string& word : words) {
            long long totalWeight = 0;

            for (char ch : word) {
                totalWeight += weights[ch - 'a'];
            }

            int rem = totalWeight % 26;
            result.push_back('z' - rem);
        }

        return result;
    }
};
