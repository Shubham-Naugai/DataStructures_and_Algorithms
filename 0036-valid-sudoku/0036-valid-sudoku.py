class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # brute force
        def isValid(row, col, value, board):
            for i in range(9):
                if board[i][col] == value:
                    return False
                if board[row][i] == value:
                    return False
                if board[(3 * (row//3)) + (i//3)][(3 * (col//3)) + i%3] == value:
                    return False
            return True
        
        
        def solve(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] != ".":
                        temp = board[i][j]
                        board[i][j] = "."
                        if not isValid(i, j, temp, board):
                            return False
                        board[i][j] = temp
            return True
        return solve(board)