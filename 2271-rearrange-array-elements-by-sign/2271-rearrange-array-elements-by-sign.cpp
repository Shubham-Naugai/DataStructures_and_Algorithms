class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        if (n==0){
            return nums;
        }
        
        vector<int> res(n, 0);
        int ptr1 = 0;
        int ptr2 = 1;
        for (int i=0; i<n; i++){
            if (nums[i]>0){
                res[ptr1] = nums[i];
                ptr1 += 2;
            }
            else{
                res[ptr2] = nums[i];
                ptr2 += 2;
            }
        }
        return res;
    }
};