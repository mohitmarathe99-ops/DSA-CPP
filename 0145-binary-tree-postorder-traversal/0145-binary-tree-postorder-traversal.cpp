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
public:
//root-node nvm 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* root = st.top();
            st.pop();
            result.push_back(root->val);

            if (root->left!=nullptr) {
                st.push(root->left);
            }
            if (root->right!=nullptr) {
                st.push(root->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
        
    }
};
 