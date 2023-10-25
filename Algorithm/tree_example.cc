#include<iostream> 
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    array.push_back(root->val);
    preorder(root->left, array);
    preorder(root->right, array);
}

void inorder(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    inorder(root->left, array);
    array.push_back(root->val);
    inorder(root->right, array);
}

void postorder(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    postorder(root->left, array);
    postorder(root->right, array);
    array.push_back(root->val);
}

void preorder_ii(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    TreeNode *cur = root;
    stack<TreeNode *> s;

    while (cur || !s.empty()) {
        while (cur) {
            array.push_back(cur->val);
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cur = cur->right;
    }
}

void inorder_ii(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    TreeNode *cur = root;
    stack<TreeNode *> s;
    
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        array.push_back(cur->val);
        s.pop();
        cur = cur->right;
    }

}

void postorder_ii(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    stack<TreeNode *> s1, s2;
    s1.push(root);
    TreeNode *cur;
    while (!s1.empty()) {
        cur = s1.top();
        s1.pop();
        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
        s2.push(cur);
    }
    while (!s2.empty()) {
        cur = s2.top();
        array.push_back(cur->val);
        s2.pop();
    }
}

void levelorder(TreeNode *root, vector<int> &array) {
    if (root == nullptr) return;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *cur;
    while (!q.empty()) {
        cur = q.front();
        array.push_back(cur->val);
        q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

void print(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    vector<int> res;
    preorder(root, res);
    cout << "preorder: ";
    print(res);
    res.clear();
    inorder(root, res);
    cout << "inorder: ";
    print(res);
    res.clear();
    postorder(root, res);
    cout << "postorder: ";
    print(res);
    res.clear();
    preorder_ii(root, res);
    cout << "preorder_ii: ";
    print(res); 
    res.clear();
    inorder_ii(root, res);
    cout << "inorder_ii: ";
    print(res);
    res.clear();
    postorder_ii(root, res);
    cout << "postorder_ii: ";
    print(res);
    res.clear();
    levelorder(root, res);
    cout << "levelorder: ";
    print(res);
    return 0;
}
