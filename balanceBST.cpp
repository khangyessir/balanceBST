#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> value;

    void trav(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        trav(root->left);
        value.push_back(root->val);
        trav(root->right);
    }

    TreeNode* createBST(int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(value[mid]);
        root->left = createBST(left, mid - 1);
        root->right = createBST(mid + 1, right);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        value.clear();
        trav(root);
        return createBST(0, value.size() - 1);
    }
};
