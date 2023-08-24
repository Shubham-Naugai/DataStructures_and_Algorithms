"""
Merge Sort
Sort an array in ascending order using Merge sort algorithm.
Time Complexity --> (worst/average/best): N(logN)
Space Complexity: N
"""


# MergeSort in Python

def merge(arr, low, mid, high):
    temp = []
    left = low        # starting index of left half of arr
    right = mid + 1   # starting index of right half of arr

    # storing elements in the temporary array in a sorted manner

    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1
    
    # if elements on the left half are still left

    while left <= mid:
        temp.append(arr[left])
        left += 1

    # if elements on the right half are still left
    while right <= high:
        temp.append(arr[right])
        right += 1

    # transfering all elements from temporary to arr
    for i in range(low, high+1):
        arr[i] = temp[i - low]


def mergeSort(arr, low, high):
    if low >= high:
        return
    mid = (low+high)//2
    #left half of array
    mergeSort(arr, low, mid)
    # right half of array
    mergeSort(arr, mid+1, high)

    # merge the array
    merge(arr, low, mid, high)



if __name__ == '__main__':
    arr = [6, 5, 12, 10, 9, 1, 5]
    n = len(arr)
    low = 0
    high = n-1

    mergeSort(arr, low, high)

    print("Sorted array is: ")
    print(arr)

