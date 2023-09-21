class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n;
        int top = 0;
        int bottom = n;
        int value = 1;

        vector<vector<int>> res(n, vector<int> (n));
        
        while(left < right && top < bottom){
            for(int i=left; i<right; i++){
                res[top][i] = value;
                value++;
            }
            top++;

            for(int i=top; i<bottom; i++){
                res[i][right-1] = value;
                value++;
            }
            right--;

            for(int i=right-1; i>=left; i--){
                res[bottom-1][i] = value;
                value++;
            }
            bottom--;

            for(int i=bottom-1; i>=top; i--){
                res[i][left] = value;
                value++;
            }
            left++;
        }
        return res;
    }
};