class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        noOfDiag = rows+cols-1
        row = 0
        col = 0

        for d in range(noOfDiag):
            diag = []

            if col == cols or row > 0:
                col = 0
                row += 1
            
            # storing diagonal elemnts into diag array
            i=row
            j=col
            while i<rows and j<cols:
                diag.append(mat[i][j])
                i += 1
                j += 1
            
            # sorting the diag array
            diag.sort()
            
            # replace the matrix diagonal elements with diag array elements
            i=row
            j=col
            k = 0
            while i<rows and j<cols:
                mat[i][j] = diag[k]
                i += 1
                j += 1
                k += 1
            
            if row == 0:
                col += 1
        
        return mat
