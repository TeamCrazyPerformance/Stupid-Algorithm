n = int(input())
num_list = list(map(int,input().split( )))
sum = best = num_list[0]
for i in num_list[1:]:
    sum = max(i,sum+i)
    best = max(best,sum)
print(best)