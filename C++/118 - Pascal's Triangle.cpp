/*
 118. Pascal's Triangle (E)

 Notes:
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};