/*
 124. Binary Tree Maximum Path Sum (H)

 A1: Divide-and-conquer (DFS btm-up)
 Ref: HuaHua(https://youtu.be/9ZNky1wqNUw)
 Time: O(n)
 Space: O(n)
 
*/

// A1
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int currMax = INT_MIN;
        maxPathSum(root, currMax);
        return currMax;
    }
    
    int maxPathSum(TreeNode* root, int& currMax) {
        // 如果root是空的返回0
        if (!root) return 0;
        
        // 取得左最大及又最大
        int left = max(0, maxPathSum(root->left, currMax));
        int right = max(0, maxPathSum(root->right, currMax));
        
        // 假設在此轉折, 左右加自己與歷史最大比較
        int turn = left + right + root->val;
        currMax = max(currMax, turn);
        
        // 假設不在此轉折, 左右取大的加自己往上傳
        return max(left, right) + root->val;
    }
};
