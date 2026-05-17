#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 =(double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item>& items,int capacity) {

    sort(items.begin(), items.end(), compare);

    double totalProfit = 0;
    
    for(int i = 0; i < items.size(); i++) {
        if(items[i].weight <= capacity) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            totalProfit += ((double)items[i].value / items[i].weight) * capacity;
            break;
        }
    }
    return totalProfit;
}

int main() {

    int n;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    
    for(int i = 0; i < n; i++) {

        cout << "Enter value and weight of item "<< i + 1 << ": ";

        cin >> items[i].value >> items[i].weight;
    }

    int capacity;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double ans = fractionalKnapsack(items, capacity);

    cout << "Maximum Profit = " << ans;

    return 0;
}