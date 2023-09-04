class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> countGap;
        for (auto row: wall){
            int total = 0;
            for(int j=0; j<row.size()-1; j++){
                total += row[j];
                countGap[total]++;
            }
        }
        int maxCount = 0;
        for (auto pair: countGap) {
            maxCount = max(maxCount, pair.second);
        }
        return wall.size() - maxCount;
    }
};