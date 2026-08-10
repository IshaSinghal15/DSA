class Solution {
public:
    unordered_map<int, int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int left, int right) {
        if (left > right)
            return NULL;

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int mid = pos[rootValue];

        root->left = build(preorder, inorder, left, mid - 1);
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};