/*

optimize approach -> https://github.com/ShubhuNaugai/DataStructures_and_Algorithms/blob/main/LeetCode/Hash%20Table/L_1512_Number_of_Good_Pairs.cpp


Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0; 
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i < j && nums[i] == nums[j]) {
                    ans = ans + 1; 
                }
            }
        }
        return ans;
    }
};
