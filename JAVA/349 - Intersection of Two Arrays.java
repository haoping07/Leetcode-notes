/*
 349. Intersection of Two Arrays (E)

 Approach 1 : HashSet + BS
 Sort the nums1, then find the nums2's elements in nums1
 Time: O(nums2.length)
 Space: O(set.size())

*/

/* Approach 1 */
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0) return new int[] {};
        
        HashSet<Integer> set = new HashSet<Integer>();
        
        // Find the nums2's elements in sorted nums1
        Arrays.sort(nums1);
        for (int i = 0; i < nums2.length; i++) {
            if (set.contains(nums2[i])) continue;
            else if (BS(nums1, nums2[i])) set.add(nums2[i]);
        }
        
        int[] res = new int[set.size()];
        int i = 0;
        for (int x : set) res[i++] = x;
        
        return res;
    }
    
    public boolean BS(int[] nums, int target) {
        int l = 0, r = nums.length - 1, m = 0;
        while (l < r - 1) {
            m = l + (r - l) / 2;
            if (nums[m] == target) return true;
            if (nums[m] < target) l = m;
            else r = m;
        }
        if (nums[l] == target || nums[r] == target) return true;
        return false;
    }
}