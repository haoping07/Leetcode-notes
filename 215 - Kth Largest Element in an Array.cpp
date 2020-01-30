/*
 215. Kth Largest Element in an Array (M)

 Notes:
    1. Priority Queue
    Push each elements into priority queue, if queue size is greater than k, pop it. 
    The result wil be the top element of queue
      T: O(logn)
      S: O(logn)?

    2. Quick sort
    Solution from basketwangCoding [https://www.youtube.com/watch?v=zyskis1Gw0c]
    Use Quick sort to sort/get element position one by one, if position is equal to K, then that is the answer 
      T: O(logn)    worst O(n^2): a sorted data
      S: O(n)?
*/

// Approach 1 : Priority Queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> todo;
        for (int i = 0; i < nums.size(); i++)
        {
            todo.push(nums[i]);
            if (todo.size() > k)
                todo.pop();
        }
        return todo.top();
    }
};


// Approach 2 : Quick Sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || k <= 0 || k > size) return 0;
        int left = 0, right = size - 1;
        int k_small = size - k + 1;

        while (true)
        {
            int pos = partition(nums, left, right);
            if (k_small == pos + 1)
                return nums[pos];
            else if (k_small < pos + 1)
                right = pos - 1;
            else
                left = pos + 1;
        }

        // Fake return 
        return 0;
    }

    void swap(vector<int>& nums, int left, int right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = right;
        int slow = left - 1;
        int fast = left;

        while (fast < pivot)
        {
            if (nums[fast] > nums[pivot])
                fast++;
            else
                swap(nums, ++slow, fast++);
        }
        swap(nums, ++slow, pivot);
        return slow;
    }
};