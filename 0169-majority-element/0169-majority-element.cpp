class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans;
        unordered_map<int, int> map;
        for(auto val: nums){
            map[val]++;
            if (map[val] > n/2){
                ans = val;
                return ans;
            }
        }
        return ans;
    }
};