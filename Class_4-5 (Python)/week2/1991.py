import sys

input = sys.stdin.readline

n = int(input())

# 딕셔너리 생성 {key0 : val0, key1, val1, ...}
tree = {}

for i in range(n):
    tree[parent] = [left, right]
    parent, left, right = map(str, input().strip().split())
    # <-- str 을 map으로 받아올때는 \n반드시 없애줘야댐, 여기선 end=''로 막았긴 하지만, 마지막 right = 'C\n'이런식으로 들어가있을거임
    # 백준에서 이걸 정답으로 인식하는 이유는 아마 input데이터가 txt파일로 들어와서일거다. txt파일엔 한라인 읽어와도 \n이 보통 없으니까


# 전위순회
def preorder(node):
    if node != ".":
        print(node, end="")
        preorder(tree[node][0])  # left
        preorder(tree[node][1])  # right


# 중위순회
def inorder(node):
    if node != ".":
        inorder(tree[node][0])  # left
        print(node, end="")
        inorder(tree[node][1])  # right


# 후위순회
def postorder(node):
    if node != ".":
        postorder(tree[node][0])  # left
        postorder(tree[node][1])  # right
        print(node, end="")


preorder("A")
print()
inorder("A")
print()
postorder("A")
