#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int x) {
    if (st.empty() || x < st.top()) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int x = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, x);
    }
}

int main() {
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    sortStack(st);
    stack<int> res;
    while (!st.empty()) {
        res.push(st.top());
        st.pop();
    }
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}
