#include <iostream>
#include <vector>
using namespace std;

void binarySearch(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1;
    int comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;

        if (arr[mid] == key) {
            cout << "Present " << comparisons << endl;
            return;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Not Present " << comparisons << endl;
}

int main() {
    cout<<”Akshat Aswal”<<endl<<”G1”<<endl<<”Roll NO : 09”
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        binarySearch(arr, n, key);
    }
    
    return 0;
}