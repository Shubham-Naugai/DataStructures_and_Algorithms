class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Optimal Approach: Moore’s Voting Algorithm
        """ If the count is 0, count +1 and el will be current element in nums
        if current element is same as el then count +1 else then count -1
        [ Acc to question it is confirmed the majority element always exist then el will have
        the majority element otherwise we have write another for loop to check wether el is
        the majority element or not ]"""
        n = len(nums)
        cnt = 0  # Count
        el = None  # Element

        # Applying the algorithm
        for i in range(n):
            if cnt == 0:
                cnt = 1
                el = nums[i]
            elif el == nums[i]:
                cnt += 1
            else:
                cnt -= 1
        return el

        # n = len(nums)
        # if n == 1:
        #     return nums[0]
        # d = {}
        # for val in nums:
        #     if val in d:
        #         d[val] += 1
        #         if d[val] > n // 2:
        #             return val
        #     else:
        #         d[val] = 1
