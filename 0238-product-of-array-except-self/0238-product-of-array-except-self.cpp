class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        int prefix_product = 1;
        for(int i=0; i<n; i++){
            res.push_back(prefix_product);
            prefix_product = prefix_product * nums[i]; 
        }

        int p = 1;
        for(int i=n-1; i>=0; i--){
            res[i] = res[i] * p;
            p = p * nums[i]; 
        }
        return res; 
    }
};