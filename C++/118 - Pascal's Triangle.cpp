/*
 118. Pascal's Triangle (E)

 Approach 1 :
 Time: O(n)
 Space: O(n)

 Approach 2 : Brute force
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

/* Approach 2 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res(numRows, vector<int>());

        // First layer
        res[0].push_back(1);

        for (int i = 1; i < numRows; i++) {
            // First element always 1
            res[i].push_back(1);

            for (int j = 1; j < i; j++) {
                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }

            // Last element always 1
            res[i].push_back(1);
        }
        return res;
    }
};