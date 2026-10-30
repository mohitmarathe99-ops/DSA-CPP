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
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,  vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inorderIndexMap) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inorderIndexMap[rootVal];
        int leftTreeSize = rootIndex - inStart;
        
        root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, 
                                     postorder, postStart, postStart + leftTreeSize - 1, 
                                     inorderIndexMap);
        root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, 
                                      postorder, postStart + leftTreeSize, postEnd - 1, 
                                      inorderIndexMap);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, 0, inorder.size() - 1, 
                               postorder, 0, postorder.size() - 1, 
                               inorderIndexMap);
    }     
};