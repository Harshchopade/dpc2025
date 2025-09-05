#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstElementKTimes(vector<int>& arr, int k) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    for (int x : arr) {
        if (freq[x] == k) return x;
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << firstElementKTimes(arr, k);
    return 0;
}
