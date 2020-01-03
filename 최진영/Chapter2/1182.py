subset = []
answer = 0

n, sum_num = map(int, input().split())
set = list(map(int,input().split()))

def subset_function(i):
    if i == n:
        if subset and sum(subset) == sum_num:
            global answer
            answer += 1
        return
    subset.append(set[i])
    subset_function(i+1)
    subset.remove(set[i])
    subset_function(i+1)

subset_function(0)
print(answer)

