n, m = map(int, input().split())

def choose(cur, lower_bound, answer = []):
    if cur == m:
        print(*answer)
        return
    
    for i in range(lower_bound, n + 1):
        answer.append(i)
        choose(cur + 1, i + 1)
        answer.pop()

choose(0, 1)