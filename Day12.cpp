#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.length() % 2 != 0) return false;
    stack<char> st;
    unordered_map<char,char> mp = {{')','('}, {']','['}, {'}','{'}};
    for (char c : s) {
        if (c=='(' || c=='[' || c=='{') st.push(c);
        else {
            if (st.empty() || st.top() != mp[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "[{()}]"; 
    cout << (isValid(s) ? "true" : "false");
    return 0;
}
