import sys

input = sys.stdin.readline

# A*(B+C)/D 로 생각해보자


def infix_to_postfix(infix):
    priority = {"*": 2, "/": 2, "+": 1, "-": 1, "(": 0}
    stack = []
    postfix = []

    for char in infix:
        # A. 피연산자 (Operand: 알파벳 대문자)
        if "A" <= char <= "Z":
            postfix.append(char)

        # B. 여는 괄호 '('
        elif char == "(":
            stack.append(char)
        # C. 연산자 ' * / + - '
        elif char in priority:
            # 현재 연산자의 우선순위가 스택 top의 연산자 우선순위보다
            # '작거나 같을' 동안 pop하여 결과에 추가
            while stack and (priority.get(char) <= priority.get(stack[-1], -1)):
                postfix.append(stack.pop())
            # 현재 연산자를 스택에 push
            stack.append(char)

        # C. 닫는 괄호 ')'
        elif char == ")":
            # 스택에서 '('를 만날 때까지 연산자를 pop하여 결과에 추가
            while stack and stack[-1] != "(":
                postfix.append(stack.pop())
            # '(' 제거 (결과에는 추가하지 않음)
            if stack and stack[-1] == "(":
                stack.pop()

    while stack:
        postfix.append(stack.pop())

    return "".join(postfix)


infix = input().strip()
print(infix_to_postfix(infix))
