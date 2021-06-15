
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution
{
public:
    int solve(TreeNode *node, int *res)
    {

        if (node == NULL)
        {
            // NULL has no height...
            // we are at a null, path length
            return -1;
        }

        // try to calculate from left and right from our curr node
        int l = solve(node->left, res);
        int r = solve(node->right, res);

        // induce
        // 1. when this node acts only as an intermediary
        int temp = 1 + max(l, r);

        // 2. when this node acts an answer node
        int ans = 2 + l + r;

        // if it did act as ans, try updating
        if (*res < ans)
        {
            *res = ans;
        }

        // when it did not act as an answer node
        //, that value should be pushed to the parent
        return temp;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = INT_MIN;
        int ans = solve(root, &res);

        return res;
    }
};