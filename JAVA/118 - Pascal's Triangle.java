/*
 118. Pascal's Triangle (E)

 Approach 1 : 
 Time: O(numRows^2)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (numRows == 0) return res;
        
        // First layer always 1
        res.add(new ArrayList<Integer>());
        res.get(0).add(1);
        
        for (int i = 1; i < numRows; i++) {
            List<Integer> row = new ArrayList<Integer>();
            List<Integer> prevRow = res.get(i - 1);
            
            // First element
            row.add(1);
            
            for (int j = 1; j < i; j++) {
                row.add(prevRow.get(j - 1) + prevRow.get(j));
            }
            
            // Last element
            row.add(1);
            // Add row to list
            res.add(row);
        }
        return res;
    }
}