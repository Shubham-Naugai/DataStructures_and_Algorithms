"""
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

"""

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(arr, low, mid, high):
            temp = []
            left = low
            right = mid + 1

            while left <= mid and right <= high:
                if arr[left] <= arr[right]:
                    temp.append(arr[left])
                    left += 1
                else:
                    temp.append(arr[right])
                    right += 1

            while left <= mid:
                temp.append(arr[left])
                left += 1

            while right <= high:
                temp.append(arr[right])
                right += 1

            for i in range(low, high+1):
                arr[i] = temp[i - low]


        def mergeSort(arr, low, high):
            if low >= high:
                return
            mid = (low+high)//2
            mergeSort(arr, low, mid)
            mergeSort(arr, mid+1, high)
            merge(arr, low, mid, high)
        
        n = len(nums)
        low = 0
        high = n-1
        mergeSort(nums, low, high)
        return nums
