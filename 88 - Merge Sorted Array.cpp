/*
 88. Merge Sorted Array (Easy)
 
 Notes: 
    Merge sort (two pointers) - O(n)
    Two arrays are sorted, merge array2 into array1. Do it in array1 from back to front to avoid overwriting the 
    array1's elements which are going to compare with array2's element.
*/

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