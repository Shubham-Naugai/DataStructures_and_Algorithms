class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        left, right = 0, n - 1
        if n == 0: return False
        if n == 1:
            if nums[0]!=target:
                return False
            else:
                return True
        
        while left <= right:
            while left<right and nums[left] == nums[left+1]:
                left+=1
            while left<right and nums[right] == nums[right-1]:
                right-=1

            mid = (left + right)//2
            if nums[mid] == target: return True
            
            if nums[mid] >= nums[left]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
                    
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            
        return False