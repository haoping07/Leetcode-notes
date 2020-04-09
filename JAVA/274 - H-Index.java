/*
 274. H-Index (M)
 
 Approach 1 :
 Time: O(n*log(n)), collection sort is n*log(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int h = 0;
        for (int i = citations.length - 1; i >= 0; i--) {
            if (citations[i] >= h + 1) h++;
        }
        return h;
    }
}