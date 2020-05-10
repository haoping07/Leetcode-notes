/*
 350. Intersection of Two Arrays II (E)

 Approach 1 : Sort + compare one by one
 Time: O(4n), two sorts + compare + copy to array
 Space: O(result.size())

*/

/* Approach 1 */
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0) return new int[] {};
        List<Integer> list = new ArrayList<Integer>();
        int i = 0;
        int j = 0;
        
        // Sort two lists
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        // Compare one by one
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) {
                list.add(nums1[i]);
                i++;
                j++;
            }
                
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        // Copy list to array
        int k = 0;
        int[] res = new int[list.size()];
        for (int x : list) {
            res[k++] = x;
        }
        
        return res;
    }
}
