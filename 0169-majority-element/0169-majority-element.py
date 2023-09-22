class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        d = {}
        for val in nums:
            if val in d:
                d[val] += 1
                if d[val] > n // 2:
                    return val
            else:
                d[val] = 1
