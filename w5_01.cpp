#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> freq(26, 0);
    for (char ch : arr) {
        freq[ch - 'a']++;
    }
    int maxFreq = 0;
    char result = '\0';
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            result = (char)(i + 'a');
        }
    }
    if (maxFreq <= 1) {
        cout << "No Duplicates Present" << endl;
    } else {
        cout << result << " " << maxFreq << endl;
    }
}
int main() {
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}