class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using selection sort algorithm to sort in in-place
        int n = nums.size();
        // selection_sort
        for(int i=0; i<=n-2; i++){
            int min_ind = i;
            for(int j=i; j<=n-1; j++){
                if(nums[j] < nums[min_ind]){
                    min_ind = j;
                }
            }
            // swap(nums[min_ind], nums[i])
            int temp = nums[min_ind];
            nums[min_ind] = nums[i];
            nums[i] = temp;
        }
    }
};