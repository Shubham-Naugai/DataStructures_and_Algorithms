class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Optimal Approach: Moore’s Voting Algorithm
        
        /* If the count is 0, count +1 and el will be current element in nums
        if current element is same as el then count +1 else then count -1
        [ Acc to question it is confirmed the majority element always exist then el will have
        the majority element otherwise we have write another for loop to check wether el is
        the majority element or not ]*/

        int n = nums.size();
        int cnt = 0;  // Count
        int el;  // Element

        // Applying the algorithm
        for (int i=0; i<n; i++){
            if (cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return el;
        
        
        // int n = nums.size();
        // int ans;
        // unordered_map<int, int> map;
        // for(auto val: nums){
        //     map[val]++;
        //     if (map[val] > n/2){
        //         ans = val;
        //         return ans;
        //     }
        // }
        // return ans;
    }
};