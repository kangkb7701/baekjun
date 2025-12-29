import sys

input = sys.stdin.readline

def solve_sudoku():
    if not blank: #리스트가 비었다면
        return True

    r,c = blank.pop(0)
    k = box_index(r,c)
    for num in range(1, 10):
        if num not in row_sets[r] and num not in col_sets[c] and num not in box_sets[k]:
            sudoku[r][c] = num
            row_sets[r].add(num)
            col_sets[c].add(num)
            box_sets[k].add(num)
            if solve_sudoku(): #빈칸 다 채웠으면 종료
                return True
            sudoku[r][c] = 0
            row_sets[r].remove(num)
            col_sets[c].remove(num)
            box_sets[k].remove(num)

    blank.insert(0,(r, c))
    return False

def box_index(r,c):
    # 0~8번박스 (좌->우->아래로 이동)
    return (r//3)*3 + (c//3)
#문제풀이
sudoku = []

row_sets = [set() for _ in range(9)]
col_sets = [set() for _ in range(9)]
box_sets = [set() for _ in range(9)]

for i in range(9):
    row = input().strip()
    sudoku.append(list(map(int,row)))

blank = []

for row in range(9):
    for col in range(9):
        num = sudoku[row][col]
        if num == 0:
            blank.append((row,col))
        else:
            row_sets[row].add(num)
            col_sets[col].add(num)
            k = box_index(row,col)
            box_sets[k].add(num)

# 디버깅용
#for row in sudoku:
#    print(row)

if solve_sudoku():
    for row in sudoku:
        for i in range(9):
            print(row[i],end='')
        print()


