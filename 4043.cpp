class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int r = 0; r < n; r++) {
            string t = s.substr(r) + s.substr(0, r);

            int score = 0;

            for (int i = 0; i < n - 1; i++) {
                if (t[i] == t[i + 1])
                    score++;
            }

            if (score == k)
                ans++;
        }

        return ans;
        
    }
};
