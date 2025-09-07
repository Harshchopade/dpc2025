#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_map<TreeNode*, TreeNode*> parent;
    stack<TreeNode*> st;
    parent[root] = NULL;
    st.push(root);

    while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
        TreeNode* node = st.top();
        st.pop();
        if (node->left) {
            parent[node->left] = node;
            st.push(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            st.push(node->right);
        }
    }

    unordered_set<TreeNode*> ancestors;
    while (p) {
        ancestors.insert(p);
        p = parent[p];
    }

    while (ancestors.find(q) == ancestors.end()) {
        q = parent[q];
    }

    return q;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;          
    TreeNode* q = root->right;         

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << lca->val;
    return 0;
}
