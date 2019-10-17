/*
 75. Sort Colors (Medium)

 Notes:
    Multiple pointers - O(n)
    Make three pointers, left, mid and right, point to the array most left, most left and most right element.
    Iterate from the first element in given array. If the element's value is 0, swap(left, mid), left++, mid++. 
    If 1, mid++. If 2, swap(mid, right), right--.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size() - 1;
        while (mid <= right)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};


/*
// Pseudo code

l = 0
m = 0
r = nums.size() - 1
while mid <= right do
  if nums[mid] == 0 then
    swap(nums[mid], nums[left])
    l++
    r++
  elseif nums[mid] == 1 then
    mid++;
  else
    swap(mid, right)
    right--
  end
end

*/