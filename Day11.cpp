#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result) {
    if (current.size() == s.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;
        used[i] = true;
        current.push_back(s[i]);
        backtrack(s, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<string> permuteUnique(string s) {
    sort(s.begin(), s.end());
    vector<string> result;
    vector<bool> used(s.size(), false);
    string current = "";
    backtrack(s, used, current, result);
    return result;
}
int main() {
    string s = "aab";
    vector<string> permutations = permuteUnique(s);
    cout << "[";
    for (int i = 0; i < permutations.size(); i++) {
        cout << permutations[i];
        if (i != permutations.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
