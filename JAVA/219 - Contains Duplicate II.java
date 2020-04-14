/*
 219. Contains Duplicate II (E)
 
 Approach 1 :
 Use HashMap<key, val>, key as nums element, val as its index. Iterate the arrays,
 if the element not exist in hashmap, put into it with its index. If the element
 exists in hashmap, compare the difference of index, if <= k, return true, else,
 update the hashmap index.
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i]) && i - map.get(nums[i]) <= k)
                return true;
            map.put(nums[i], i);
        }
        return false;
    }
}
