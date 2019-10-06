/*
 274. H-Index
 Medium
*/

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