/*
 189. Rotate Array (E)

 Approach 1 : Exchange
 Exchange one by one
 Time: O(n)
 Space: O(1)

 Approach 2 : left and right
 First add the elements that will exceed the array after rotate to the list, 
 then the remaining elements.
 Time: O(2n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public void rotate(int[] nums, int k) {
        // Handle k value
        k %= nums.length;
        int c = 0;
        
        // Iterate the array
        for (int i = 0; i < nums.length; i++) {
            int startId = i;
            int startVal = nums[i];
            
            // Use do to loop the array
            do {
                int nextId = (startId + k) % nums.length;
                int nextVal = nums[nextId];
                
                // Copy the current val to new Index
                nums[nextId] = startVal;
                
                // Update the id
                startId = nextId;
                startVal = nextVal;
                c++;
            } while (i  != startId);
            // If all element were saw before iteration, return
            if (c == nums.length) return;
        }
    }
}

/* Approach 2 */
class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        // Handle k value
        k %= len;
        
        // Result list
        List<Integer> res = new ArrayList<Integer>();
        
        // Handle left side element
        for (int i = len - k; i < len; i++) {
            res.add(nums[i]);
        }
        
        // Handle right side element
        for (int i = 0; i < len - k; i++) {
            res.add(nums[i]);
        }
        
        for (int i = 0; i < res.size(); i++) {
            nums[i] = res.get(i);
        }
    }
}