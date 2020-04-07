/*
 189. Rotate Array (E)

 Notes: 
 Approach 1 : Exchange
 Exchange one by one
 Time: O(n)
 Space: O(1)

 Approach 2 : Split and Reverse (tricky)
 Rotate three time
 Time: O(n)
 Space: O(1)

 Approach 3 : right side and left side
 Split the array to two sides, right side are the numbers that will rotate to the
 front, left side are the numbers that won't rotate to the front. Find them and
 combine them.
 Time: O(2n)
 Space: O(n)

*/

// Approach 1 : 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 0) return;
        k %= nums.size();
        int c = 0;

        for (int i = 0; i < nums.size(); i++) {
            int startIdx = i, startVal = nums[i];
            do {
                int newPos = (startIdx + k) % nums.size();
                int tmp = nums[newPos];
                nums[newPos] = startVal;
                startIdx = newPos;
                startVal = tmp;
                c++;
            } while (startIdx != i);
            if (c == nums.size()) return;
        }
    }
};

// Approach 2 :
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// Approach 3 :
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if ((nums.size() < 2 || k == 0) return;

        k %= nums.size();
        vector<int> temp;

        // Right side
        for (int i = nums.size() - k; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }

        // Left side
        for (int i = 0; i < nums.size() - k; i++) {
            temp.push_back(nums[i]);
        }

        // Set it to the origin array
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
    }
};