class Solution {
public:
    struct Node {
        int l, r, w, idx;
    };

    vector<Node> a;
    int n;

    vector<vector<long long>> dp;
    vector<vector<vector<int>>> path;

    vector<int> solve(int i, int k) {
        if (i == n || k == 0)
            return {};

        if (dp[i][k] != -1)
            return path[i][k];
        vector<int> skip = solve(i + 1, k);
        long long score1 = dp[i + 1][k];

        int lo = i + 1;
        int hi = n;

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (a[mid].l > a[i].r)
                hi = mid;
            else
                lo = mid + 1;
        }

        int next = lo;

        vector<int> take = solve(next, k - 1);

        long long score2 = a[i].w + dp[next][k - 1];

        take.push_back(a[i].idx);

        sort(skip.begin(), skip.end());
        sort(take.begin(), take.end());

        if (score2 > score1) {
            dp[i][k] = score2;
            path[i][k] = take;
        }
        else if (score1 > score2) {
            dp[i][k] = score1;
            path[i][k] = skip;
        }
        else {
            dp[i][k] = score1;

            if (take < skip)
                path[i][k] = take;
            else
                path[i][k] = skip;
        }

        return path[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(), a.end(), [](Node &x, Node &y) {
            if (x.l != y.l)
                return x.l < y.l;

            return x.r < y.r;
        });

        dp.assign(n + 1, vector<long long>(5, -1));
        path.assign(n + 1, vector<vector<int>>(5));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int k = 0; k <= 4; k++)
            dp[n][k] = 0;

        solve(0, 4);

        vector<int> answer = path[0][4];

        sort(answer.begin(), answer.end());

        return answer;
    }
};
