/*
 295. Find Median from Data Stream (H)

 Approach 1 :
 Time: O(nlogn), priority queue push is nlogn
 Space: O(n)

*/

/* Approach 1.1 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();
        if (minQ.size() > maxQ.size())
        {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian() {
        if (maxQ.size() == minQ.size())
            return (maxQ.top() + minQ.top()) / 2;
        return maxQ.top();
    }

private:
    priority_queue<double> maxQ;
    priority_queue<double, vector<double>, greater<double>> minQ;
};


/* Approach 1.2 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxQ.empty() || num <= maxQ.top()) maxQ.push(num);
        else minQ.push(num);
        balance();
    }

    double findMedian() {
        if (maxQ.size() == minQ.size())
            return (maxQ.top() + minQ.top()) / 2;
        return maxQ.top();
    }

    void balance()
    {
        if (maxQ.size() - 1 > minQ.size())
        {
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        else if (minQ.size() > maxQ.size())
        {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

private:
    priority_queue<double> maxQ;
    priority_queue<double, vector<double>, greater<double>> minQ;
};
