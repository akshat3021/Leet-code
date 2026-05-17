#include<bits/stdc++.h>
using namespace std;
int main() {
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
    cout << "Character Frequency:\n";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char(i + 'a') << " : " << freq[i] << endl;
        }
    }
    return 0;
}