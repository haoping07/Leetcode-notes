/*
 239. Sliding Window Maximum (H)

 Approach 1 : Use deque (double-ended queue)
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
public:
    void InQueue(deque<int>& queue, int num)
    {
        while (!queue.empty() && queue.back() < num)
            queue.pop_back();
        queue.push_back(num);
    }

    void OutQueue(deque<int>& queue, int num)
    {
        if (queue.front() == num)
            queue.pop_front();
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> res;

        for (int i = 0; i < k - 1; i++)
            InQueue(queue, nums[i]);

        for (int i = k - 1; i < nums.size(); i++)
        {
            InQueue(queue, nums[i]);
            res.push_back(queue.front());
            OutQueue(queue, nums[i - k + 1]);
        }
        return res;
    }
};