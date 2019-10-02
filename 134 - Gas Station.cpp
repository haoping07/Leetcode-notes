/*
 134. Gas Station
 Medium
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        for (int i = 0; i < gas.size(); i++)
            totalGas += gas[i] - cost[i];
        if (totalGas < 0)
            return -1;

        int sumGas = 0, index = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sumGas += gas[i] - cost[i];
            if (sumGas < 0)
            {
                sumGas = 0;
                index = i + 1;
            }
        }
        return index;
    }
};