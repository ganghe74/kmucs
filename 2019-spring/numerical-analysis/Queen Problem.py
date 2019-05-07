# 수치해석 선택형과제
import copy

def take_input():
    """Accepts the size of the chess board"""

    while True:
        try:
            size = int(input('What is the size of the chessboard? n = \n'))
            if size == 1:
                print("Trivial solution, choose a board size of at least 4")
            if size <= 3:
                print("Enter a value such that size>=4")
                continue
            return size
        except ValueError:
            print("Invalid value entered. Enter again")


def get_board(size):
    """Returns an n by n board"""
    board = [0] * size
    for ix in range(size):
        board[ix] = [0] * size
    return board


def print_solutions(solutions, size):
    """Prints all the solutions in user friendly way"""
    for sol in solutions:
        for row in sol:
            print(row)
        print()


def is_safe(board, row, col, size):
    """Check if it's safe to place a queen at board[x][y]"""

    # check row on left side
    for iy in range(col):
        if board[row][iy] == 1:
            return False

    ix, iy = row, col
    while ix >= 0 and iy >= 0:
        if board[ix][iy] == 1:
            return False
        ix -= 1
        iy -= 1

    jx, jy = row, col
    while jx < size and jy >= 0:
        if board[jx][jy] == 1:
            return False
        jx += 1
        jy -= 1

    return True


def dfs(board, col, size):
    # 기저 사례, 더이상 탐색이 불가능하므로 탐색을 중지한다.
    if col >= size: 
        return

    # 모든 열에 놓는 경우의 수를 고려하기 위한 반복문
    for i in range(size):
        # board[i][col]에 놓는게 가능하다면 탐색을 진행한다.
        if is_safe(board, i, col, size):
            board[i][col] = 1
            # 만약 N개의 퀸을 모두 놓았으면 정답에 추가하고 퇴각한다.
            if col == size - 1:
                add_solution(board)
                board[i][col] = 0
                return
            # 다음 단계로 탐색을 진행한다.
            dfs(board, col + 1, size)
            # board[i][col]에 대한 탐색이 끝났으므로 퀸을 다시 뺀다.
            board[i][col] = 0

# queue 모듈을 불러옴
import queue

def bfs(board, size):
    # 큐를 선언한다.
    # 처음 큐에는 텅 빈 baord와 퀸의 개수를 알려주는 0이 들어있다.
    Q = queue.Queue()
    Q.put((board, 0))
    # 큐가 빌때까지 진행 (모든 경우의수를 탐색할때까지)
    while Q.qsize() > 0:
        board, col = Q.get()
        # 만약 size개의 퀸이 있으면 정답임
        if col == size:
            add_solution(board)
            continue
        # 모든 열에 놓는 경우의 수를 고려하기 위한 반복문
        for i in range(size):
            # board[i]][col]에 놓는게 가능하다면 큐에 넣는다
            if is_safe(board, i, col, size):
                next_board = copy.deepcopy(board)
                next_board[i][col] = 1
                Q.put((next_board, col+1))
        


def add_solution(board):
    """Saves the board state to the global variable 'solutions'"""
    global solutions
    saved_board = copy.deepcopy(board)
    solutions.append(saved_board)


size = take_input()

board = get_board(size)

solutions = []

solve(board, 0, size)
#bfs(board, size)

print_solutions(solutions, size)

print("Total solutions = {}".format(len(solutions)))