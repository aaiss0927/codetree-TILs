n = int(input())

def choose(cur, answer = [], is_used = [False for i in range(n + 1)]):
    if cur == n:
        print(*answer)
        return
    
    for i in range(1, n + 1):
        if is_used[i]:
            continue

        is_used[i] = True
        answer.append(i)
        choose(cur + 1)
        answer.pop()
        is_used[i] = False

choose(0)