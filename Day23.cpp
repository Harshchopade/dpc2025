#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans = slidingWindowMaximum(arr, k);
    for (int x : ans) cout << x << " ";
    return 0;
}
