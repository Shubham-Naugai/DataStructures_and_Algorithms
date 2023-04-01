/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k%n == 0){
            return;
        }
        int t; 
        if(k>n){
            t = floor(k/n); 
            k = k - (t*n); 
        }

        // reversing 0 - n-k-1 in nums
        int i = 0; 
        int j = n-k-1;
        int temp; 
        while(i < j){
            temp = nums[i];
            nums[i] = nums[j]; 
            nums[j] = temp;
            i++; 
            j--; 
        }

        // reversing n-k - n-1
        i = n-k; 
        j = n-1; 
        while(i < j){
            temp = nums[i];
            nums[i] = nums[j]; 
            nums[j] = temp;
            i++; 
            j--; 
        }

        // now reverse the entire nums
        i = 0; 
        j = n-1; 
        while(i<j){
            temp = nums[i];
            nums[i] = nums[j]; 
            nums[j] = temp;
            i++; 
            j--;
        }

    }
};