class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size(); 
        int cols = mat[0].size();
        int noOfDiag = rows+cols-1; 
        int col = 0;
        int row = 0; 

        for(int d=1; d<=noOfDiag; d++){
            // initializing empty vector for storing diagonal element
            vector<int> diag;

            if(col == cols | row > 0){
                col = 0;
                row++; 
            }

            for(int i=row, j=col; i<rows && j<cols; i++, j++){
                diag.push_back(mat[i][j]);
            }
            
            sort(diag.begin(), diag.end());

            for(int i=row, j=col, k=0; i<rows && j<cols; i++, j++, k++){
                mat[i][j] = diag[k];
            }
            
            if(row == 0){
                col++;
            }

        }
        return mat;
    }
};