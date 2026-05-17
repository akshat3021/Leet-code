#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ═══════════════════════════════════════════════════════════
// APPROACH 1: RECURSION (Naive)
// Time: O(2^n)  Space: O(n) — recursion stack
// Idea: At each item, try BOTH choices (take / skip)
//       Return the maximum of the two
// ═══════════════════════════════════════════════════════════
int knapsackRecursion(int idx, int W,
                      vector<int>& val, vector<int>& wt) {

    // Base case: no items left OR bag is full
    if (idx == 0 || W == 0) return 0;

    // Choice 1: SKIP current item
    int skip = knapsackRecursion(idx - 1, W, val, wt);

    // Choice 2: TAKE current item (only if it fits)
    int take = 0;
    if (wt[idx - 1] <= W)
        take = val[idx - 1] +
               knapsackRecursion(idx - 1, W - wt[idx-1], val, wt);

    return max(take, skip);
}

// ═══════════════════════════════════════════════════════════
// APPROACH 2: TOP-DOWN DP (Memoization)
// Time: O(n×W)  Space: O(n×W) — memo table + recursion stack
// Idea: Same as recursion BUT store already-computed answers
//       in a memo table so we never solve the same
//       subproblem twice
// ═══════════════════════════════════════════════════════════
int knapsackMemo(int idx, int W,
                 vector<int>& val, vector<int>& wt,
                 vector<vector<int>>& memo) {

    if (idx == 0 || W == 0) return 0;

    // Already computed this subproblem? Return it directly
    if (memo[idx][W] != -1) return memo[idx][W];

    int skip = knapsackMemo(idx - 1, W, val, wt, memo);

    int take = 0;
    if (wt[idx - 1] <= W)
        take = val[idx - 1] +
               knapsackMemo(idx - 1, W - wt[idx-1], val, wt, memo);

    // STORE result before returning
    memo[idx][W] = max(take, skip);
    return memo[idx][W];
}

// ═══════════════════════════════════════════════════════════
// APPROACH 3: BOTTOM-UP DP (Tabulation) ← YOUR CODE
// Time: O(n×W)  Space: O(n×W) — 2D table
// Idea: Build the DP table iteratively from base case up.
//       No recursion at all. Fills row by row.
// ═══════════════════════════════════════════════════════════
int knapsackTabulation(int W,
                       vector<int>& val, vector<int>& wt) {
    int n = wt.size();

    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {

            int notPick = dp[i-1][j];  // skip item i

            int pick = 0;              // take item i (if fits)
            if (wt[i-1] <= j)
                pick = val[i-1] + dp[i-1][j - wt[i-1]];

            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n][W];
}

// ═══════════════════════════════════════════════════════════
// APPROACH 4: SPACE-OPTIMIZED BOTTOM-UP DP
// Time: O(n×W)  Space: O(W) — only 1D array!
// Idea: In tabulation, row i only depends on row i-1.
//       So we don't need the full 2D table —
//       just ONE row (1D array), updated in-place.
// ⚠️  MUST iterate j from W down to wt[i]
//     (right to left) to avoid using updated values
// ═══════════════════════════════════════════════════════════
int knapsackSpaceOpt(int W,
                     vector<int>& val, vector<int>& wt) {
    int n = wt.size();

    // Single 1D array — represents ONE row of the 2D table
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // ⚠️ MUST go RIGHT TO LEFT to avoid using the
        //    already-updated values of the current row
        for (int j = W; j >= wt[i]; j--) {
            dp[j] = max(dp[j],              // skip item i
                        val[i] + dp[j - wt[i]]); // take item i
        }
    }
    return dp[W];
}


// ═══════════════════════════════════════════════════════════
// MAIN — test all 4 on the same input
// ═══════════════════════════════════════════════════════════
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter values : ";
    for (int i = 0; i < n; i++) cin >> val[i];
    int W;
    cout << "Enter capacity: ";
    cin >> W;

    // --- Approach 1: Recursion ---
    cout << "\n[1] Recursion       : "
         << knapsackRecursion(n, W, val, wt);

    // --- Approach 2: Memoization ---
    vector<vector<int>> memo(n+1, vector<int>(W+1, -1));
    cout << "\n[2] Memoization     : "
         << knapsackMemo(n, W, val, wt, memo);

    // --- Approach 3: Tabulation ---
    cout << "\n[3] Tabulation      : "
         << knapsackTabulation(W, val, wt);

    // --- Approach 4: Space Optimized ---
    cout << "\n[4] Space Optimized : "
         << knapsackSpaceOpt(W, val, wt);

    cout << "\n";
    return 0;
}