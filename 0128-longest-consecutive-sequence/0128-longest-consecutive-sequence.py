class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        maximum = 0
        hashSet = set(nums)
        for i in nums:
            if i-1 not in hashSet:
                minimal_number = i
                curr_streak = 0
                while minimal_number in hashSet:
                    minimal_number += 1
                    curr_streak += 1
                maximum = max(maximum, curr_streak)
        return maximum