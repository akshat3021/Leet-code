class Solution {
public:
    long long calc(vector<int>& Astart, vector<int>& Adur,
                   vector<int>& Bstart, vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<int,int>> b(m);
        for (int i = 0; i < m; i++)
            b[i] = {Bstart[i], Bdur[i]};

        sort(b.begin(), b.end());

        vector<int> start(m);
        vector<long long> pref(m);
        vector<long long> suff(m + 1, LLONG_MAX);

        for (int i = 0; i < m; i++) {
            start[i] = b[i].first;
            pref[i] = b[i].second;
            if (i) pref[i] = min(pref[i], pref[i - 1]);
        }

        for (int i = m - 1; i >= 0; i--) {
            suff[i] = min(suff[i + 1],
                          (long long)b[i].first + b[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)Astart.size(); i++) {
            long long finish = (long long)Astart[i] + Adur[i];

            int pos = upper_bound(start.begin(), start.end(), finish)
                      - start.begin();

            long long cur = suff[pos];

            if (pos > 0)
                cur = min(cur, finish + pref[pos - 1]);

            ans = min(ans, cur);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans1 = calc(landStartTime, landDuration,
                              waterStartTime, waterDuration);

        long long ans2 = calc(waterStartTime, waterDuration,
                              landStartTime, landDuration);

        return (int)min(ans1, ans2);
    }
};
