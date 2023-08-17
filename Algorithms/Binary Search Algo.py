"""
Given a sorted array of n integers and a target value, determine if the target exists in
the array in logarithmic time using the binary search algorithm. If target exists in the
array, print the index of it.
Input:
 
nums[] = [2, 3, 5, 7, 9]
target = 7
 
Output: Element found at index 3
 
 
Input:
 
nums[] = [1, 4, 5, 8, 9]
target = 2
 
Output: Element not found

"""

# ***********Iterative approach***********

def binarySearch(nums, target):
 
    # search space is nums[left…right]
    (left, right) = (0, len(nums) - 1)
 
    # loop till the search space is exhausted
    while left <= right:
 
        # find the mid-value in the search space and
        # compares it with the target
 
        mid = (left + right) // 2
 
        # overflow can happen. Use:
        # mid = left + (right - left) / 2
        # mid = right - (right - left) // 2
 
        # target is found
        if target == nums[mid]:
            return mid
 
        # discard all elements in the right search space,
        # including the middle element
        elif target < nums[mid]:
            right = mid - 1
 
        # discard all elements in the left search space,
        # including the middle element
        else:
            left = mid + 1
 
    # `target` doesn't exist in the list
    return -1
 
 
if __name__ == '__main__':
 
    nums = [2, 5, 6, 8, 9, 10]
    target = 5
 
    index = binarySearch(nums, target)
 
    if index != -1:
        print('Element found at index', index)
    else:
        print('Element found not in the list')





# ***********Recursive approach***********

def binarySearch(nums, left, right, target):
 
    # Base condition (search space is exhausted)
    if left > right:
        return -1
 
    # find the mid-value in the search space and
    # compares it with the target
 
    mid = (left + right) // 2
 
    # overflow can happen. Use below
    # mid = left + (right - left) / 2
 
    # Base condition (a target is found)
    if target == nums[mid]:
        return mid
 
    # discard all elements in the right search space,
    # including the middle element
    elif target < nums[mid]:
        return binarySearch(nums, left, mid - 1, target)
 
    # discard all elements in the left search space,
    # including the middle element
    else:
        return binarySearch(nums, mid + 1, right, target)
 
 
if __name__ == '__main__':
 
    nums = [2, 5, 6, 8, 9, 10]
    target = 5
 
    (left, right) = (0, len(nums) - 1)
    index = binarySearch(nums, left, right, target)
 
    if index != -1:
        print('Element found at index', index)
    else:
        print('Element found not in the list')



"""
We know that at each step of the algorithm, our search space reduces to half. That means if initially, our search space contains n elements, then after one iteration it contains n/2, then n/4 and so on…

n —> n/2 —> n/4 —> … —> 1
Suppose our search space is exhausted after k steps. Then,

n/2k = 1
n = 2k
k = log2n
Therefore, the time complexity of the binary search algorithm is O(log2n), which is very efficient. The auxiliary space required by the program is O(1) for iterative implementation and O(log2n) for recursive implementation due to call stack.
"""