global N
N = 8
global r
r=0
def printSolution(board):
	for i in range(N):
		for j in range(N):
			print (board[i][j],end=' ')
		print()
	global r
	r+=1


def isSafe(board, row, col):

	
	for i in range(col):
		if board[row][i] == 1:
			return False

	
	for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
		if board[i][j] == 1:
			return False

	
	for i, j in zip(range(row, N, 1), range(col, -1, -1)):
		if board[i][j] == 1:
			return False

	return True

def solveNQUtil(board, col):

	if col >= N:
		printSolution(board)
	for i in range(N):
		if isSafe(board, i, col):
			board[i][col] = 1
			solveNQUtil(board, col + 1)
			board[i][col] = 0
	return False


board = [[0 for i in range(N)] for j in range(N) ]


solveNQUtil(board,0)

print(r)
