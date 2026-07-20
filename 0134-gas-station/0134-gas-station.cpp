class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalG =0, totalC =0;
        for(int i=0; i<gas.size(); i++){
            totalG += gas[i];
            totalC += cost[i];
        }
        if(totalG < totalC){
            return -1;
        }
        int currG =0, startInd =0;
        for(int i=0; i<gas.size(); i++){
            currG += gas[i] - cost[i];
            if(currG < 0){
                startInd = i+1;
                currG =0;
            }
        }
        return startInd;
    }
};