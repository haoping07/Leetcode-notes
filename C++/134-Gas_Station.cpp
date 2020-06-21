/*
 134. Gas Station (M)
 
 Approach 1:
 Loop two lists, if the sum gas isn't enough to the next station, try the
 next one of the current node. Also, if the the total gas isn't enough to
 go through all nodes, return -1;
 Time: O(n)
 Space: O(1) 
 
*/

// Approach 1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++) {
            // Compute if the fuel is enough to the next station
            sum += gas[i] - cost[i];
            // If the fuel isn't enough
            if (sum < 0) {
                // Initialize the condition
                sum = 0;
                index = i + 1;
            }
            // We also need to check if the fuel is enough for a circular route
            total += gas[i] - cost[i];
        }
        return total < 0 ? -1 : index;
    }
};