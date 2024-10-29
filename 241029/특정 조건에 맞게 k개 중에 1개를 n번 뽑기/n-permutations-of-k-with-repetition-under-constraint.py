k, n = map(int, input().split())
answer = []

def choose(cur):
    if cur == n:
        for a in answer:
            print(a, end=' ')
        print()
        return
    
    for i in range(1, k + 1):
        if cur >= 2 and i == answer[-1] and i == answer[-2]:
            continue

        answer.append(i)
        choose(cur + 1)
        answer.pop()

choose(0)