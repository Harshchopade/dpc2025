#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& entry : mp) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    vector<string> testInput = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(testInput);

    cout << "[ ";
    for (auto& group : ans) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << "]\n";

    return 0;
}
