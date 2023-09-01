class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # key = col index, value = set of values in that column
        cols = collections.defaultdict(set) # {key: {}}
        # key = row index, value = set of values in that row
        rows = collections.defaultdict(set)
        # key = pair of square's row index and col index and value = set of values in that square
        squares = collections.defaultdict(set)  # key = (r /3, c /3)

        d = {}
        d[0] = {'5'}
        print(d)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (
                    board[r][c] in rows[r]
                    or board[r][c] in cols[c]
                    or board[r][c] in squares[(r // 3, c // 3)]
                ):
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r // 3, c // 3)].add(board[r][c])

        return True


        """
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
        """