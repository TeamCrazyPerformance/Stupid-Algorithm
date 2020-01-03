n = int(input())
chosen = [0 for i in range(n+1)]
answer = []

def permutation():
    if len(answer) == n:
        for i in answer : print(i,end=' ')
        print()
        return
    for i in range(1,n+1):
        if chosen[i] : continue
        chosen[i] = 1
        answer.append(i)
        permutation()
        chosen[i] = 0
        answer.remove(i)

permutation()