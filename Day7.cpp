#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;

    vector<int> leftMax(n), rightMax(n);

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        int trapped = min(leftMax[i], rightMax[i]) - height[i];
        if (trapped > 0) totalWater += trapped;
    }

    return totalWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trap(height);
    cout << "Total Water Trapped = " << result << " units" << endl;
    return 0;
}
