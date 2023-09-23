class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        if not nums:
            return nums
        
        newArray = [0] * len(nums)
        i, j = 0, 1
        for num in nums:
            if num > 0:
                newArray[i] = num
                i += 2
            else:
                newArray[j] = num
                j += 2
            
        return newArray
        # l = len(nums)
        # if l == 2:
        #     if nums[0] >= 0:
        #         return nums
        #     nums[0], nums[1] = nums[1], nums[0]
        #     return nums
        # p = 0
        # n = 1
        # for i in range(l):
        #     if n >= l:
        #         return nums
        #     if nums[p] >= 0 and nums[n] < 0:
        #         p += 2
        #         n += 2
        #     elif nums[p] < 0 and nums[n] >= 0:
        #         nums[p], nums[n] = nums[n], nums[p]
        #         p += 2
        #         n += 2
        #     elif nums[p] >= 0 and nums[n] >= 0:
        #         t = n+1
        #         while t < l:
        #             if nums[t] >= 0:
        #                 nums[n], nums[t] = nums[t], nums[n]
        #             else:
        #                 nums[n], nums[t] = nums[t], nums[n]
        #                 break
        #             t += 1
        #         p += 2
        #         n += 2
        #     else:
        #         t = p+1
        #         while t < l:
        #             if nums[t] < 0:
        #                 nums[p], nums[t] = nums[t], nums[p]
        #             else:
        #                 nums[p], nums[t] = nums[t], nums[p]
        #                 break
        #             t += 1
        #         p += 2
        #         n += 2
