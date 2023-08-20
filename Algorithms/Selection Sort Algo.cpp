/*
Selection Sort
Sort an array in ascending order using selection sort algorithm.
Time complexity(Best/worst/average): n^2
Space Complexity: 1 
*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr, int  &n){
    for(int i=0; i<=n-2; i++){
        int min_ind = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        // swap(arr[min_ind], arr[i])
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    vector<int> arr = {14, 56, 37, 96, 11, 40};
    int n = arr.size();
    selection_sort(arr, n);
    // print sorted array
    for(int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
