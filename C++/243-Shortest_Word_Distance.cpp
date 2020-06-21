/*
 243. Shortest Word Distance (Easy)

 Notes:
    - O(n)
    Scan the list. If find word1, move pointer1 to it, if find word2, move pointer2 to it. Each time you find something,
    calcualte the distant between pointer1 and pointer2 and compare the value with the previous found distant and take 
    the smallest one
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string& word1, string& word2) {
        int ptr1 = -1, ptr2 = -1, ans = INT_MAX;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
                ptr1 = i;
            if (words[i] == word2)
                ptr2 = i;

            if (ptr1 != -1 && ptr2 != -1)
                ans = min(ans, abs(ptr1 - ptr2));                
        }
        return ans;
    }
};