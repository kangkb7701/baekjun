import sys

input = sys.stdin.readline

# N: 보드 크기, board: 초기 보드 상태
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
answer = 0


# 1. 한 줄을 왼쪽으로 미는 함수 (핵심 로직)
def compress_line(line):
    # 0을 제외한 숫자만 추출
    temp = [x for x in line if x != 0]
    new_line = []
    i = 0
    while i < len(temp):
        # 현재 숫자와 다음 숫자가 같으면 합침
        if i + 1 < len(temp) and temp[i] == temp[i + 1]:
            new_line.append(temp[i] * 2)
            i += 2  # 두 개를 합쳤으므로 인덱스 2칸 이동
        else:
            # 다르면 그대로 추가
            new_line.append(temp[i])
            i += 1
    # 남은 공간을 0으로 채움
    return new_line + [0] * (N - len(new_line))


# 2. 전체 보드를 왼쪽으로 미는 함수
def move_left(board):
    new_board = []
    for row in board:
        new_board.append(compress_line(row))
    return new_board


# 3. 보드를 시계방향 90도 회전하는 함수
def rotate_90(board):
    # zip을 활용한 파이썬 행렬 회전 테크닉
    return list(map(list, zip(*board[::-1])))


# 4. DFS 탐색 (최대 5번)
def dfs(board, count):
    global answer

    # 가지치기 (선택 사항): 현재 최대값이 이미 찾은 값보다 작다면 중단할 수도 있지만,
    # 4^5는 작으므로 굳이 안 해도 통과됨.
    current_max = max(map(max, board))
    answer = max(answer, current_max)

    if count == 5:
        return

    # 4방향 탐색
    for _ in range(4):
        moved_board = move_left(board)
        # 보드가 실제로 변했을 때만 다음 단계로 진입 (최적화)
        if moved_board != board:
            dfs(moved_board, count + 1)
        # 다음 방향을 위해 보드 회전 (상->우->하->좌 순서로 커버됨)
        board = rotate_90(board)


# 실행
dfs(board, 0)
print(answer)
