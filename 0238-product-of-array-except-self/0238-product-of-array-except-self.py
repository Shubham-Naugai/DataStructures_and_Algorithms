class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []

        # calulate the prefix prduct from left to right
        # since we are calculating the prefix product-
        # -(product of all the previous elements of nums except nums[i])
        # res[n-1] will be the product of all elements from i=0 to i=n-2 in nums
        # res[0] = 1 because nums[0] has no prefix so its prefix product is always 1 

        prefix_product = 1
        for i in range(0,n):
            res.append(prefix_product)
            prefix_product = prefix_product * nums[i]
        
        
        # product from right to left
        # now we reverse traverse the res array
        # res[i] which is prefix product of nums[i] (nums[i] is excluded)
        # p will store the product of all the elements after nums[i] (nums[i] is excluded)
        # so the the product of all array elements except nums[i] will be res[i] * p
        
        p = 1  
        for i in range(n-1,-1,-1):
            res[i] = res[i] * p
            p = p * nums[i]
        return res