/*
 189. Rotate Array (E)

 Notes: 
 Approach 1: Replace
 Exchange one by one
 Time: O(n)
 Space: O(1)

 Approach 2: Split and Reverse (tricky)
 Rotate three time
 Time: O(n)
 Space: O(1)

 Approach 3: right side and left side
 Split the array to two sides, right side are the numbers that will rotate to the
 front, left side are the numbers that won't rotate to the front. Find them and
 combine them.
 Time: O(2n)
 Space: O(n)

*/

// Approach 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            int startId = i;
            int startVal = nums[i];
            do {
                // Make sure k will not exceed the nums size
                int nextId = (startId + k) % nums.size();
                // Record the element value that will be replace
                int nextVal = nums[nextId];
                // Assign the current val to the new posistion
                nums[nextId] = startVal;
                // Update the initialize status
                startId = nextId;
                startVal = nextVal;
                c++;
            } while (i != startId);
            if (c == nums.size()) return;
        }
    }
};

// Approach 2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

// Approach 3
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> res;
        // Handle the elements that will be exceeded nums size after
        // moving k steps.
        for (int i = nums.size() - k; i < nums.size(); i++) {
            res.push_back(nums[i]);
        }

        // Handle the elements that won't exceeded nums size after
        // moving k steps.
        for (int i = 0; i < nums.size() - k; i++) {
            res.push_back(nums[i]);
        }

        // Update the nums
        for (int i = 0; i < res.size(); i++) {
            nums[i] = res[i];
        }
    }
};