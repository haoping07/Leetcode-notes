/*
 274. H-Index (M)
 
 Approach 1 :
 Time: O(n)
 Space: O(1)

 Approach 2 :
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int size = citations.size();
        int c = 0;
        sort(citations.begin(), citations.end());
        for (int i = size - 1; i >= 0; i--) {
            if (citations[i] >= c + 1) c++;
            else break;
        }
        return c;
    }
};


/* Approach 2 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> count(size + 1, 0);
        for (int i = 0; i < size; i++)
        {
            if (citations[i] >= size)
                count[size]++;
            else
                count[citations[i]]++;
        }

        int sum = 0;
        for (int i = size; i >= 0; i--)
        {
            sum += count[i];
            if (sum >= i)
                return i;
        }
        return 0;
    }
};