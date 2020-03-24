/*
 75. Sort Colors (M)

 Approach 1 : Counting Sort
 Time: O(2n)
 Space: O(1)

 Approach 2 : Three Pointers
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 : Counting Sort */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int i : nums)
            count[i]++;

        int n = 0;
        for (int i = 0; i < count.size(); i++)
        {
            while (count[i] > 0)
            {
                nums[n++] = i;
                count[i]--;
            }
        }
    }
};

/* Approach 2 : Three Pointers */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size() - 1;
        while (mid <= right)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};