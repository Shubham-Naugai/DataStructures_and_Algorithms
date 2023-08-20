"""
Bubble Sort
Sort an array in ascending order using bubble sort algorithm.
Time Complexity --> (worst/average): n^2
Time Complexity --> (best): n ( if array is already sorted then we have no swaping in first iteration of outer loop,
                                so we will stop the further iterations)
Space Complexity: 1 
"""


def bubble_sort(arr, n):
    for i in range(n-1, 0, -1):
        didSwap = 0
        for j in range(0, i):
            if arr[j] > arr[j+1]:
                arr[i], arr[j+1] = arr[j+1], arr[i]
                didSwap = 1
        if didSwap == 0:
            break

if __name__ == '__main__':

    arr = [14, 56, 37, 96, 11, 40]
    n = len(arr)

    bubble_sort(arr, n)
    print(arr)
