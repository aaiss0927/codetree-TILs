n, m = map(int, input().split())
answer = []
is_used = [False for _ in range(0, n + 1)]

def choose(cur, start):
    if cur == m:
        for a in answer:
            print(a, end=' ')
        print()
        return
    
    for i in range(start, n + 1):
        if is_used[i]:
            continue

        is_used[i] = True
        answer.append(i)
        choose(cur + 1, i + 1)
        answer.pop()
        is_used[i] = False

choose(0, 1)