"""
Selection Sort
Sort an array in ascending order using selection sort algorithm.
Time complexity(Best/worst/average): n^2
Space Complexity: 1 
"""


def selection_sort(arr, n):
    for i in range(0, n-1):
        min_ind = i
        for j in range(i, n):
            if arr[j] < arr[min_ind]:
                min_ind = j
        arr[i], arr[min_ind] = arr[min_ind], arr[i]

if __name__ == '__main__':

    arr = [14, 56, 37, 96, 11, 40]
    n = len(arr)

    selection_sort(arr, n)
    print(arr)
