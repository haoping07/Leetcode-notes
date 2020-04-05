/*
 118. Pascal's Triangle (E)

 Approach 1 : 
 Time: O(numRows^2)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();
        
        if (numRows == 0) return triangle;
        
        // First layer
        triangle.add(new ArrayList<Integer>());
        triangle.get(0).add(1);
        
        // Following layers
        for (int i = 1; i < numRows; i++) {
            List<Integer> row = new ArrayList<Integer>();
            List<Integer> prevRow = triangle.get(i - 1);
            row.add(1);
            for (int j = 1; j < i; j++) {
                row.add(prevRow.get(j - 1) + prevRow.get(j));
            }
            row.add(1);
            triangle.add(row);
        }
        return triangle;
    }
}