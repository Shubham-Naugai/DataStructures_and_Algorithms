class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());

        int longest_sequence = 0; 
        for(int i=0; i<nums.size(); i++){
            if(set.find(nums[i]-1) != set.end()){
                continue;
            }
            else{
                int curr_streak = 0;
                int current_element = nums[i];
                while(set.find(current_element) != set.end()){
                    curr_streak += 1;
                    current_element++;
                }
                
                longest_sequence = max(longest_sequence, curr_streak);
            }
        }
        return longest_sequence; 
    }
};