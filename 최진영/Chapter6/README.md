# 동적 계획법

## 기본 개념

동적 계획법이란? "어떤 문제를 풀기 위해 그 문제를 더 작은 문제의 연장선으로 생각하고, 과거에 구한 해를 활용하는" 방식의 알고리즘을 총칭한다.

### 동전 교환 문제

해결방법은 자연스럽게 떠올릴 수 있는 탐욕 알고리즘이 있을 것이다. 항상 액수가 제일 큰 동전을 택하되, 합이 목표 액수를 넘지 않도록 하는 것이다.
하지만, 이 방법은 항상 성립하지 않는다. 실제로, 동전들이 서로 배수 관계가 아니라면 탐욕알고리즘은 성립하지 않는다. 따라서 우리는 동적 계획법을 사용하여 무차별 알고리즘과 흡사하게 동작하면서도 효율적인 알고리즘을 고안해 낼 수 있다.

#### 최적해 구하기

핵심 아이디어는 우리가 첫 번째로 어떤 동전을 선택하는지에 초첨을 맞추는 것이다.

- 재귀함수를 이용하는 방법
```
int value[n];
int coins[m] = ...;

int solve(int x){
	if (x<0) return INF;
	if (x==0) return 0;
	int best = INF;
	if (value[x] != INF) return value[x];
	for(int i=0;i<m;i++) best = min(best,solve(x-coins[i])+1);
	value[x] = best;
	return best;
}

int main(){
	for(int i=1;i<n;i++) value[i] = INF;
	solve(10);
}
```

하지만, 재귀함수를 이용하는 방법은 효율적이지 않는데, 중복되는 경우의 수에서도 일일히 함수를 호출하여 값을 구하기 때문이다.
따라서 우리는 동적계획법에서 아주 중요한 개념인 `메모이제이션(memoization)` 개념을 적용하여 반복문을 이용하는 방법을 할 수 있다.

>메모이제이션(momoization) : 함수의 값을 계산한 뒤 이를 배열에 저장하는 방법을 말한다.

- 반복문을 이용하는 방법

```
int value[n];
int coins[m] = ...;

int main(){
	value[0]=0;
	for(int i=1;i<n;i++){
		value[i] = INF;
		for(int j=0;j<m;j++) value[i] = min(value[i],value[i-coins[j]]+1);
	}
}
```

#### 해답 구성하기

문제에 따라서는 최적해의 값뿐 아니라 그 값이 어떻게 만들어지는지를 구해야하는 경우도 있다. 동전 문제의 최적해가 어떻게 만들어지는지를 구하기 위해서는 새로운 배열을 정의하여 각각의 합을 만들기 위해 어떤 동전을 첫번쨰로 선택하는지를 저장하면 된다.

```
int value[n];
int coins[m] = ...;
int first[n];

int main(){
  value[0] = 0;
  for(int i=1; i<n; i++) {
    value[i]=INF;
    for(int j=0; j<m; j++){
      if(i-coins[j]>=0 & value[i]>value[i-coins[j]]){
        value[i] = value[i-coins[j]] +1;
        first[i] = coins[j];
      }
    }
  }
}
```

#### 해의 개수 구하기

동전 문제를 변형하여 합 x를 만드는 경우의 수를 세는 문제를 생각해보자. 현재의 값에서 각각의 동전값을 뺀 값이 0보다 작지 않으면 해당 동전을 택할 수 있다. 따라서 그 동전의 값을 뺀 경우의 해의 개수를 현재 해의 개수에 더하면 된다.

```
int coins[m] = ...;
int c[n];

int main(){
  c[0]=1;
  for(int i=1;i<n;i++){
    for(int j=0;j<m;j++){
      if(i-coins[j]>=0) c[i] += c[i-coins[j]];
    }
  }
}
```
## 다른 예제

### 최장 증가 부분 수열

원소가 n개인 배열의 일부 원소를 골라내어 만든 부분 수열 중에서, 각 원소가 이전 원소보다는 크다는 조건을 만족하면서 그 길이가 최대인 것을 최장 증가 부분 순열(longest increasing subsequence)이라 한다.

이때, 함수 length(k)는 위치 k에서 끝나는 최장 증가 부분 수열의 길이로 정의 할 수 있으며, 동적계획법에서 length함수를 통해 작은 문제로 쪼갤 수 있다. length(k)의 값을 계산하기 위해서는 array[i]<array[k] 이면서 length(i)가 최대가 되는 위치 i(i<k)를 찾아야 한다.

```
int length[8];
int num[8] = {6,2,5,1,7,4,8,3};

for(int k=0;k<8;k++){
  length[k]=1;
  for(int i=0;i<k;i++){
    if(num[i]<num[k]) length[k] = max(length[k],length[i]+1);
  }
}
```

>위 알고리즘은 시간 복잡도가 O(n^2)이다. 시간 복잡도가 O(nlogn)이 되는 알고리즘을 생각해보자.

### 격자상의 경로

꽤 쉬운 문제이므로 넘어가겠다.

```
int value[n][n] = ...;
int sum[n][n]

for (int y=1;y<=n;y++){
  for(int x=1; x<=n;x++){
    sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
  }
}
```

### 짐 싸기 문제

문제를 풀기 위해서 합 k를 만들 수 있는가라는 부분문제를 생각하면 된다. k 합을 만들 수 있다면, 어떠한 w에 대해서 k+w의 값을 만들 수 있기 때문이다.

```
int w[m] = ...;
bool possible[n];
for(int i=0;i<n;i++) possible[i] = false;
possible[0] = true;
for(int i=1;i<n;i++){
  for(int j=0;j<m;j++){
    if(i-w[j]>=0 && possible[i-w[j]] == true) possible[i] = true;
  }
}
```
> 오른쪽부터 왼쪽의 순서로 계산하는 트릭을 사용해야 한다고?

### 순열을 부분집합으로 바꾸기

> 뭔소리일까요?

### 타일세기

이 문제는 격자를 행 단위로 하나씩 살펴보는 동적 계획법으로 풀 수 있다.각 행은  {}의 네 글자로 이루어진 길이 m의 문자열로 나타낼 수 있다. 각 행이 유효한 경우 인지는 직전 행만 살펴보면 알 수 있기 때문에 동적 계획법을 적용할 수 있다.

하지만 이 방법은 시간복잡도가 O(n4^(2m))이 된다. 공식을 이용하면 O(nm)시간안으로 효율적으로 계산할 수 있다.
