#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string expr;
    getline(cin, expr);         // read whole postfix expression line
    stringstream ss(expr);
    stack<long long> st;
    string token;

    while (ss >> token) {       // process tokens separated by spaces
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);   // integer division (C++ truncates toward zero)
        } else {
            st.push(stoll(token)); // handle integers (positive/negative)
        }
    }
    cout << st.top();
    return 0;
}
