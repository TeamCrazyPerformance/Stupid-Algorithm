# Chapter5. 자료구조
알고리즘 구현 시간을 줄일 수 있는 C++ 자료구조이다.

## 5.1 동적배열
일반적인 배열은 한 번 생성한 크기를 변경 시킬 수 없다.
`int arr[5];`

동적배열은 프로그램이 동작하는동안에 배열의 사이즈를 변경 시킬 수 있는 배열이다.

### 5.1.1 벡터
벡터는 원소를 마지막에 추가 혹은 삭제하는 과정을 효율적으로 진행 할 수 있는 동적 배열이다.
```cpp
vector<int> v;
v.push_back(3);//[3]
v.push_back(2);//[3,2]
v.push_back(5);//[3,2,5]
cout<<v[0]<<endl; // 3
cout<<v[1]<<endl; // 2
cout<<v[2]<<endl; // 5
```

위 처럼 벡터를 선언하고, 후에 데이터를 집어넣을 수 도 있지만
선언 시에 배열의 크기 혹은 초기 값을 설정해 줄 수도 있다.

```cpp
vector<int> v(8); // 사이즈 : 8, 초기값 : 0
vector<int> v1(8,2); // 사이즈 : 8, 초기값 : 2
```

마지막으로 벡터의 마지막 원소를 반환하며 삭제하는 방법은 아래와 같다.
```cpp
vector<int> v = {2,3,4,5};
cout << v.back() << endl; // 5
v.pop_back();
cout<< v.back() << endl; // 4
```

### 5.1.2 반복자의 범위
반복자는 자료구조 원소를 가리키는 변수이다.
대표적으로 `begin, end`가 존재하며 각각 자료구조의 첫 원소와 자료구조의 마지막 원소의 다음값을 가리킨다.
C++ 라이브러리에 있는 함수들은 범위를 많이 사용하는데 **어디서 어디까지 어떤 일을 할 것인지** 를 정하기 때문에 `begin, end`가 많이 쓰인다.
```cpp
sort(v.begin(), v,end()); // 정렬
reverse(v.begin(), v.end()); // 뒤집기
random_shuffle(v.begin(), v.end()); // 섞어버리기
```

또한 반복자가 가리키는 원소는 *를 이용하여 접근 할 수 있다.
`cout << *v.begin() << endl;`

또 다른 유용한 함수로  `lower_bound, upper_bound` 함수가 존재한다.
위 함수는 정렬된 배열에서 원소 x가 처음으로 나타나는 위치 혹은 x보다 큰 첫 번째 원소의 위치를 반환한다.
> 자꾸 위치라고 하는데 반복자가 맞는 말이다.
```cpp
vector<int> v = {1,2,3,4,5,6,7};
auto a = lower_bound(v.begin(), v.end(), 3);
auto b = upper_bound(v.begin(), v.end(), 3);
cout << *a << *b << endl; // 3 4
```

위 함수들은 반드시 정렬되어있어야 작동하며, 만약 찾는 값 x가 없다면 return 값은 `v.end()+1`이 return 될 것이다.

중복을 제거하는 방법
```cpp
sort(v.begin(), v.end();
v.erase(unique(v.begin(), v.end()), v.end);
```

### 5.1.3 다른 자료 구조
#### Deque
덱은 양쪽 끝 원소를 효율적으로 처리할 수 있는 동적배열이다.
`push_back, pop_back, push_front, pop_front` 함수가 존재한다.

```cpp
deque<int> d;
d.push_back(5); // [5]
d.push_front(3); //[3,5]
d.pop_front(); // [5]
d.pop_back(); // []
```

평균적으로 덱에 대한 연산은  `O(1)`만큼의 시간이 걸리지만 벡터보다 약간 느리다.
덱을 사용하려면 배열의 양 끝쪽에 대해서 연산이 필요할 경우에 사용하자.
> Stack과 Queue에 대한 내용은 생략한다. 너무 많이 써먹고 있어서..

## 5.2 집합 자료 구조
**Set** 은 원소의 집합을 관리하는 자료구조이다.
기본적인 연산으로는 추가, 탐색, 삭제이다.

### 5.2.1 셋과 멀티셋
C++ 표준 라이브러리에서는 집합 자료구조 2개를 제공한다.
* set : 균형잡힌 이진탐색트리를 기반으로 만들어져있으며 `O(log n)`시간에 동작
* unordered_set : 해시 테이블 기반으로 만들어져있으며 평균적으로 `O(1)`시간에 동작
> unordered_set의 최악의 경우는 `O(n)`이지만 드물게 발생하는 경우라 괜찮다. 하지만 알고리즘을 풀 때는 최악의 경우를 유발하는 케이스가 존재할 수도 있으므로 set을 애용하자.
두 자료구조는 제공되는 연산이 똑같다. 

셋의 특징은 모든 원소가 서로 다르다는 점이며, 이미 있는 원소에 대해서 insert가 이루어지면 무시한다는 점이다.
또한 벡터와 비슷하게 사용할 수는 있지만 **[]** 를 이용해서 원소에 접근할 수 없다.
`find(x)`를 이용하여 x의 위치를 가리키는 반복자를 return 하지만 없는 경우에는 end()를 반환한다.
```cpp
set<int> s;
s.insert(3); 
s.insert(3);
cout << s.count(3) << endl; // 1
s.erase(3);
cout << s.count(3) << endl; // 0

for(auto a : s){ cout << a << endl; }

auto it = s.find(3);
if(it == s.end()) { // 값이 없다 }
```

#### 정렬된 집합
set과 unordered_set의 큰 차이점은 정렬의 유무이다.
set은 균형잡힌 이진탐색 트리로 정렬된 상태로 저장되며, unordered_set은 그렇지 않다.
집합에서 가장 ~한 원소를 찾는 문제라면 set을 사용하는 것이 유용할 것이다.

#### 멀티셋
멀티셋은 값을 여러개 가질 수 있는 집합이다.
> 앞에서 말한 셋은 원소가 이미 있다면 무시해버린다.

멀티셋 또한 2개의 자료구조를 가지는데 `multiset, unordered_multiset`이다.
둘의 관계는 `set, unordered_set`과 동일하다.

```cpp
multiset<int> s;
s.insert(5);
s.insert(5);
cout << s.count(5) << endl; // 2

s.erase(5);
cout << s.count(5) << endl; // 0
s.insert(5);
s.insert(5);
s.erase(s.find(5));
cout << s.count(5) << endl; // 1;
```

위와 같이 특징이라면 같은 원소에 대해서 insert를 여러 번 하면 count가 증가한다.
또한 erase함수로 원소를 직접 언급하면 count가 0으로 되버리며, 만약 count를 1만 감소 시키고 싶다면 `s.erase(s.find(x))`로 지워야한다.
> count함수와 erase함수는 O(k) 의 시간복잡도를 추가로 가진다.  즉 효율적이지 못하다는 뜻이다. ( k는 삭제 또는 찾을 원소의 개수를 의미한다.)


### 5.2.2 맵
맵은 Key-Value 쌍을 저장하는 집합이다.
맵도 2개의 자료구조를 가진다. `map, unordered_map` 위에 애들이랑 같은 구조와 같은 시간복잡도를 가진다.

아래 코드와 같이 사용할 수 있다.
특징으로는 map에 key가 없는데 접근하려고 하면 map에 즉시 생성하고 Value는 default 값으로 넣어준다.

map에 해당 키가 없는지 체크하는 방법도 아래 코드에 서술하였다.

```cpp
map<string, int> m;
m["a"] = 1;
m["b"] = 2;
cout << map["a"] << map["b"] << endl; // 1 2
cout << map["c"] << endl; // 0
//check key
if(map.count("d")){ // key exist }
//all key-value
for(auto a : m){ cout << a.fisrt << a.second << endl; }
```

### 5.2.3 우선순위 큐
우선순위 큐는 기존의 Queue와 비슷하게 작동하지만 어떤 원소를 우선적으로 가장 위로 보낼지 정할 수 있는 자료구조이다.
C++에서는 `priority_queue<자료형, container, compare>` 형식으로 사용된다.
container에는 queue의 원소를 어떤 형식으로 넣을 건지에 대한 정의이다.
> 보통은 vector를 쓴다.
compare에는 어떤 비교 방식을 사용할 지에 대한 정의이다.
> 오름차순은 greater<자료형>,
> 내림차순은 less<자료형> <- 이 친구는 default 값이다!

알고리즘을 짜면서 최소 혹은 최대 원소를 빨리 구하려는 로직이 있다면 우선순위 큐를 활용하면 시간을 절약할 수 있을 것이다.
기본으로 내림차순으로 정렬되어 있으며 compare 함수를 정의하여 커스터 마이징을 할 수 있다.

```cpp
priority_queue<int> q;
q.push(3);
q.push(7);
q.push(5);
cout << q.top() << endl; // 7
priority_queue<int, vector<int>, greater<int>> q1;
q1.push(3);
q1.push(7);
q1.push(5);
cout << q1.top() << endl; // 3
```

### 5.2.4 정책 기반 집합
> 읽어봤는데 메리트가 없어 보인다, 어디에 쓸지도 모르겠다.
> 음.. 원소에 직접적으로 접근할 수 있다는 점? 말고는 없는 것 같다.

## 5.3 실험
읽어본 결과. 요약하자면 내용은 이렇다.
**입력의 크기가 매우 큰 경우 배열이 속도 가장 빠름**
**unordered가 붙은 자료구조가 붙지않은 자료구조보다 대체적으로 2배이상 빠름. But input 데이터가 최악의 경우를 만들 수 있기에 경우에 따라 다를 듯 함.**
**멀티셋 <<<<<<<< 우선순위 큐**