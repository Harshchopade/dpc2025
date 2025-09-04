#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
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
    reverseStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
