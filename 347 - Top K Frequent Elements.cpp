/*
 347. Top K Frequent Elements (M)

 Notes:
 Apporach 1 : Priority Queue (NO BETTER THAN O(nlogn))
 Count the freq of each element, push the elements into priority queue and get the top k freq elements 
 Time: O(nlogk)
 Space: O(k)

 Apporach 2 : Bucket sort (NOT WORK IN SOME CASE)
 Build a bucket, freq as key, val as value. Get k elements from right to left of bucket
 Time: O(n), if use hashmap for bucket

*/

// *Apporach 1 : Priority Queue (NO BETTER THAN O(nlogn), BUT WORK FOR ALL CASES)
class Node
{
public:
    int val;
    int freq;
    Node(int val, int freq) : val(val), freq(freq) {}
};

struct nodeGreater
{
    bool operator()(const Node& node1, const Node& node2)
    {
        if (node1.freq > node2.freq)
            return true;
        if (node1.freq == node2.freq)
            return node1.val > node2.val;

        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Build the freq hashmap
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        // Priority queue
        priority_queue<Node, vector<Node>, nodeGreater> pq;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            Node temp(it->first, it->second);
            pq.push(temp);

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().val);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Apporach 2 : Bucket Sort (TIME IS O(n) BUT NOT WORK IN SOME CASES)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int max_freq = 0;
        for (int i = 0; i < nums.size(); i++)
            max_freq = max(max_freq, ++freq[nums[i]]);

        // Build the bucket
        unordered_map<int, vector<int>> bucket;
        for (auto it = freq.begin(); it != freq.end(); it++)
            bucket[it->second].push_back(it->first);

        vector<int> ans;
        for (int i = max_freq; i >= 1; i--)
        {
            if (bucket.find(i) == bucket.end())
                continue;
            ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
            if (ans.size() == k)
                return ans;
        }
        return ans;
    }
};