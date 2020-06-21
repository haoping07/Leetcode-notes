/*
 215. Kth Largest Element in an Array (M)

 Notes:
 Approach 1 : Priority Queue
 1. Create a priority queue (smallest on top), push all node into it
 2. If queue.size() > k, pop it
 Time: O(nlogk), priority_queue::push/pop operation is logn [see https://en.cppreference.com/w/cpp/container/priority_queue/push]
 Space: O(k), only store k number in priority queue 

 Approach 2 : Quick sort (Solution from basketwangCoding - https://www.youtube.com/watch?v=zyskis1Gw0c)
 1. Use Quick sort to get the position of each sorted node
 2. If the position + 1 is larger than k_small, move the left pointer to position + 1
    If the position + 1 is smaller than k_small, move the right pointer to position - 1
    If the position + 1 is equal to k_small, then that is the answer
 Time: O(nlogk), worst O(n^2), a sorted data
 Space: O(n)

*/

// *Approach 1 : Priority Queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> todo;

        for (const int n : nums)
        {
            todo.push(n);
            if (todo.size() > k)
                todo.pop();
        }
        return todo.top();
    }
};


// *Approach 2 : Quick Sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || k <= 0 || k > size) return 0;
        int left = 0, right = size - 1;
        int k_small = size - k + 1;

        while (1)
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
        return -1;
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