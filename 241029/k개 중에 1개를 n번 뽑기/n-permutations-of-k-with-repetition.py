k, n = map(int, input().split())
answer = []

def choose(cur_num):
    if cur_num == n:
        for a in answer:
            print(a, end=' ')
        print()
        return
    
    for i in range(1, k + 1):
        answer.append(i)
        choose(cur_num + 1)
        answer.pop()

choose(0)