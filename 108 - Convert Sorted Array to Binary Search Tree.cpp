/*
 108. Convert Sorted Array to Binary Search Tree (E)

 Notes:
 Approach 1 : Recursion + BFS
 Use the middle element in vector as root in each round to build the tree
 Time: O(n)
 Space: O(n)

*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* BuildTree(vector<int>& nums, int low, int high)
    {
        if (low > high) return nullptr;

        int mid = low + (high - low) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = BuildTree(nums, low, mid - 1);
        newNode->right = BuildTree(nums, mid + 1, high);

        return newNode;
    }
};

