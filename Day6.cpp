#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int,int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<long long, vector<int>> prefixMap; 
    vector<pair<int,int>> result;
    long long prefix_sum = 0;
    prefixMap[0].push_back(-1);

    for (int i = 0; i < arr.size(); i++) {
        prefix_sum += arr[i];
        if (prefixMap.find(prefix_sum) != prefixMap.end()) {
            for (int start : prefixMap[prefix_sum]) {
                result.push_back({start + 1, i});
            }
        }
        prefixMap[prefix_sum].push_back(i);
    }
    return result;
}

int main() {
    vector<int> arr = {4, -1, -3, 1, 2, -1};
    vector<pair<int,int>> subarrays = findZeroSumSubarrays(arr);
    for (auto &p : subarrays) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
    return 0;
}
