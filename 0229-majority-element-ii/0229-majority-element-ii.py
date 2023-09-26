class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        d = {}
        n = len(nums)
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        
        ans = []
        for j in nums:
            if d[j] > 0 and d[j] > n//3:
                ans.append(j)
                d[j] = 0
        
        return ans
