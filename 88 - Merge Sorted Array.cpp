/*
 88. Merge Sorted Array (E)
 
 Approach 1 : two pointers
 Time: O(n)
 Space: O(1)

*/

/* Approach 1.1 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0)
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while (n >= 0)
            nums1[pos--] = nums2[n--];
    }
};


/* Approach 1.2 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int p = m + n - 1;

        while (p1 >= 0 && p2 >= 0)
        {
            if (nums1[p1] <= nums2[p2])
                nums1[p--] = nums2[p2--];
            else
                nums1[p--] = nums1[p1--];
        }

        // Copy remaining records in nums2, if any
        while (p2 >= 0)
            nums1[p--] = nums2[p2--];
    }
};