# 프로그래밍 기법

## 2.1 언어적특성

파이썬을 사용할 예정이므로 이 부분은 넘어간다.

## 2.2 재귀적 알고리즘

### 2.2.1 부분집합 생성하기
```
def search(k) :
	if k == n+1 :
		print(subset)
	else :
		subset.append(k)
		search(k+1)
		subset.remove(k)
		search(k+1)
```
위의 코드를 설명하자면, search 함수의 인자가 k일 때, 이 함수는 원소 k를 부분집합에 포함할지, 아니면 포함하지 않을지를 결정한다. 그리고 두 경우에 모두 인자를 k+1로 주고 함수를 재귀적으로 호출한다. k == n+1이 되면, 함수가 모든 원소를 처리했기 때문에 하나의 부분집합이 생성된 것이다.

여기서 고려할 사항이 두가지가 존재한다.

 - n과 subset이 전역변수로 설정하였다는 것이다.  전역변수로 설정하기 싫다면 search(k,n,subset) 과 같이 파라미터를 더 늘려서 n과 subset을 넘겨준다.
 - k부터 n까지의 연속된 수를 원소로 가지는 집합의 부분집합이라는 가정이 존재한다. 실제로 원소의 수가 연속적이지 않는 집합은 위의 코드가 제대로 동작하지 않는다.

```
def search(i,uncontinuous_set,subset):
 if i == len(uncontinuous_set) :
  print(subset)
 else :
  subset.append(uncontinuous_set[i])
  search(i+1,uncontinuous_set,subset)
  subset.remove(uncontinuous_set[i])
  search(i+1,uncontinuous_set,subset)
```

연속된 수를 원소로 가지지 않는 집합의 부분집합을 구하려면, 다음과 같이 집합의 인덱스로 원소를 접근한다. (또한 위 코드에서는 subset을 전역변수로 설정하지 않고 파라미터로 넘겨주었다.)

```
a ={1,2,3}
print(a.issubset({1,2,3,4})) #True
print(a.issuperset({1,2})) #True
```
참고로 파이썬에서는 해당 집합이 부분집합인지, 상위집합인지  확인하는 함수 issubset(), issuperset() 이 존재한다.

### 2.2.2 순열 생성하기

```
def search() :
 if len(permutation) == n :
  print(permutation)
 else :
  for i in range(1,n+1):
   if chosen[i] : continue
   chosen[i] = True
   permutation.append(i)
   search()
   chosen[i] = False
   permutation.remove(i)
```
위 코드를 설명하자면,  함수를 호출할 때마다 새로운 원소를 permutation에 추가하고, 그 원소를 선택했음을 chosen에 기록한다. 그러다가 permutation의 크기와 집합의 크기가 같아지면 하나의 순열이 생성된 것이다.

여기서도 부분집합과 유사한 고려사항이 두가지가 존재한다.

 - n과 permutation, chosen이 전역변수로 설정하였다는 것이다.  전역변수로 설정하기 싫다면 함수의 파라미터를 더 늘려서 n과 permutation, chosen을 넘겨준다.
 - k부터 n까지의 연속된 수를 원소로 가지는 집합의 순열이라는 가정이 존재한다. 실제로 원소의 수가 연속적이지 않는 집합은 위의 코드가 제대로 동작하지 않는다.


```
import itertools

pool = ['A', 'B', 'C']
print(list(map(''.join, itertools.permutations(pool)))) # 3개의 원소로 수열 만들기
print(list(map(''.join, itertools.permutations(pool, 2)))) # 2개의 원소로 수열 만들기
```
참고로 파이썬에는 itertools.permutations() 이라는 순열을 구하는 함수가 이미 존재한다. 이를 잘 활용해보는 것도 좋을 것 같다.

### 2.2.3 퇴각검색
퇴각 검색(Backtracking,백트레킹) 이란 비어있는 해로 탐색을 시작하고, 단계마다 해를 확장해 나가는 방식의 알고리즘이다.

> 의문, 퇴각검색과 탐욕 알고리즘의 차이는?

크기가 nXn 인 체스판에 n개의 퀸을 서로 공격할 수 없도록 배치하는 방법의 수를 세는 예제 문제를 살펴보자. 이 문제는 각 행을 차례로 살펴보면서 퀸을 배치하는 퇴각 검색으로 풀 수 있다. 좀 더 정확하게 말하면, 행마다 정확히 하나의 퀸을 배치하되 그 퀸이 이전단계에서 배치한 퀸을 공격할 수 없도록 배치한다.

이 알고리즘을 구현하면 다음과 같다.


```
def search(y) :
 if y == n :
  count += 1
  return
 for x in range(n):
  if col[x] or diag1[x] or diag2[x] : continue
  col[x] = diag1[x] = diag2[x] = 1
  search(y+1)
  col[x] = diag1[x] = diag2[x] = 0
```
  위 코드를 설명하자면, search(0)을 호출하면 탐색이 시작된다. 체스판의 크기는 n이다. 이 코드는 해의 개수를 count에 저장하며 행과 열의 번호가 0부터 n-1까지라고 가정한다. search 함수의 인자가 y일 때, 이 함수는 퀸을 y번 행에 배치한 후 인자를 y+1로 주고 함수를 재귀적으로 호출한다. 그러다가 y == n이 되면 하나의 해를 구한 것 이므로 count의 값을 하나 증가시킨다. 배열 col은 퀸이 포함된 열을 추적하기 위한 것이고, 배열 diag1과 diag2는 대각선을 추적하기 위한 것이다. 퀸이 이미 배치된 열, 혹은 대각선에 퀸을 추가로 배치할 수는 없다.

여기서도 고려사항이 두가지가 존재한다.

 - n과 count, col, diag1, diag2이 전역변수로 설정하였다는 것이다.  전역변수로 설정하기 싫다면 함수의 파라미터로 변수를 전달해준다.
 - 사실, 아무도 큰 n에 대해 퀸을 배치하는 경우의 수를 효율적으로 구하는 방법을 알지 못한다. 컴퓨터 클러스터링을 통해서 알려진 가장 큰 n은 27이다.


## 2.3 비트연산

### 2.3.3 집합 표현하기

집합의 모든 부분집합을 n비트의 정수를 이용하여 표현할 수 있다.
이때, 정수의 비트 1은 그에 대응되는 원소가 부분집합에 속해 있음을 의미한다. 이러한 표현법을 이용하면 집합을 효율적으로 표현할 수 있다. 각 원소마다 비트 한개 만큼의 메모리를 사용하고, 집합에 대한 연산을 비트 연산을 이용하여 구현할 수 있기 때문이다.

```
def get_powerset(A):
 A_size =  len(A)
 A_pow =  []  
 for i in range(2**A_size):
  flag =  bin(i)[2:].zfill(A_size)
  subset =  [A[j]  for j in  range(A_size)  if flag[j]  ==  '1']
  A_pow.append(subset)  
  return A_pow
```
