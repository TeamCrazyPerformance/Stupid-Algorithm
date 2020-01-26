n = int(input())
point = [int(input()) for i in range(n)]
step = [point[0],point[0]+point[1],max(point[0],point[1])+point[2]]
for i in range(3,n): step.append(max(step[i-2],step[i-3]+point[i-1])+point[i])
print(step[-1])
