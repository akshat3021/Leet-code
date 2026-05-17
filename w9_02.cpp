#include <bits/stdc++.h>
using namespace std;
struct Item {
    int weight, value, index;
};
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
int main() {
    int N;
    cin >> N;
    vector<int> weights(N), values(N);
    for (int i = 0; i < N; i++) cin >> weights[i];
    for (int i = 0; i < N; i++) cin >> values[i];
    int W;
    cin >> W;
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        items[i] = {weights[i], values[i], i};
    }
    sort(items.begin(), items.end(), cmp);
    double maxValue = 0.0;
    vector<double> fraction(N, 0.0);
    for (auto &item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            maxValue += item.value;
            fraction[item.index] = 1.0;
        } else {
            double frac = (double)W / item.weight;
            maxValue += item.value * frac;
            fraction[item.index] = frac;
            break;
        }
    }
    cout << fixed << setprecision(2);
    cout << "Maximum Value: " << maxValue << endl;
    cout << "Items taken (index : fraction):\n";
    for (int i = 0; i < N; i++) {
        if (fraction[i] > 0) {
            cout << i << " : " << fraction[i] << endl;
        }
    }
    return 0;
}