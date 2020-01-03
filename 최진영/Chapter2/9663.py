n = int(input())

col = [0]*n
diag1 = [0]*(n*2)
diag2 = [0]*(n*2)
answer = 0

def queen(i) :
 if i == n :
     global answer
     answer += 1
     return
 else:
    for j in range(n):
     if col[j] or diag1[j+i] or diag2[j-i+n-1] : continue
     col[j] = diag1[j+i] = diag2[j-i+n-1] = 1
     queen(i+1)
     col[j] = diag1[j+i] = diag2[j-i+n-1] = 0

queen(0)
print(answer)