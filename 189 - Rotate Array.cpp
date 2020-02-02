/*
 189. Rotate Array (E)

 Notes: 
 A1:
 Roate one by one
   T: O(n)
   S: O(1)

 A2:
 Rotate three time
   T: O(n)
   S: O(1)
*/

// Approach 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 0) return;
        k = k % nums.size();
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int startIdx = i, startVal = nums[i];
            do
            {
                int rightPos = (startIdx + k) % nums.size();
                int tmp = nums[rightPos];
                nums[rightPos] = startVal;

                startIdx = rightPos;
                startVal = tmp;

                count++;
            } while (startIdx != i);

            if (count == nums.size()) break;
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

