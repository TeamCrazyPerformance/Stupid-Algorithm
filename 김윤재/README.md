# *알고리즘 트레이닝* 의 정리
### ( *Guide to Competitive Programming: Learning and Improving Algorithms Through Contests* by Antti Laaksonen )

## 1장 생략

## 2장 : 프로그래밍 기법 *Programming Techniques*

이 장은 C++ 프로그래밍의 특징, 재귀, 비트연산을 다룬다.

### 2.1 언어적 특성 *Language Features*
   
표쥰적 경진 프로그래밍 코드 형태 :
```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    //code
}
```
<bits.stdc++> 은 표준 라이브러리 전체를 포함한다. (iostream, vector, algrotihm 등 포함)

#### 2.1.1 입력과 출력

- 표준 stream 으로 입출력 처리한다. 
  
```cpp
int a,b;
string str;
cin>>a>>b>>str;
```

개행이나 공백으로 입력 분리된다.

- 간혹 입출력이 프로그램의 병목이 될 때가 있으면 아래와 같이 처리한다.
    
```cpp
ios::sync_with_stdio(0); //standard stream synch -> false
cin.tie(0); //unties cin from cout
```

- endl 보다 "\n" 이 더 빠르다.
        
- 데이터 양을 모를때 반복문으로 처리한다. 하나씩 읽어 들이다 데이터가 없을 때 멈춘다.

```cpp
while(cin>>x){
//code
}
```

- 데이터가 파일로 주어지면 평소처럼 표준 스트림을 이용하는 방법은 입력이 input.txt, 출력을 output.txt로 할때 다음과 같다.

```cpp
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
```

#### 2.1.2 수의 처리

- 정수의 처리
알고리즘 경진에서 int의 범위(최대 2^31-1)를 벗어나게 되는 큰 수는 보통 long long으로 처리하게 된다. 이때 조심해야 할 버그가 있다.

```cpp
int x = 6666666666;
long long y = x*x;
cout<<y<<"\n"; //Overflows.
```

이는 y의 자료형이 long long이지만 x*x에 포함된 수의 자료형이 int로 결과도 int로 처리되기 때문이다.

```cpp
long long y = (long long)x*x;
```

로 바꾸어주면 된다.

- 나머지 연산
나머지 (Modulo) 연산은 (a+b) mod m = ( (a mod m) + (b mod m) ) mod m 을 만족한다. 이를 이용하여 값을 작게 유지하기 위해 연산을 수행할 때마다 mod를 취해 주면 된다.
예를 들어 n!을 m으로 나눈 나머지를 구하는 코드가 있다.

```cpp
long long x=1;
for(int i=1;i<=n;i++) x=(x*i)%m;
cout<<x<<"\n">>;
```

C++ 언어가 음수의 나머지를 음수로 취급함에 따라 음수면 m을 더해주면 된다.
```cpp
if(x<0) x += m;
```

- 부동 소수점 실수 (float, double) 
long double이 정밀도가 높아 사용하기 좋다. 부동 소수점 오차는 == 연산자를 사용하지 않고 두 수의 차이가 ε 이하로 처리하여 사용할 수 있다. 출력도 다음과 같이 할 수 있다.\
```cpp
double b=0.7*3-1.1;
double a=0.3*3+0.1;
if(abs(a-b)<1e-9){ // ε = 10^-9
printf("%.20f\n",a);  
printf("%.20f\n",b); 
// a,b 값은 오차로 미묘하게 다르다.
}
```
      
### 2.1.3 짧은 코드

- 자료형
typedef 로 자료형을 짧게 줄일 수 있다.
```cpp
typedef long long ll;
```
- 매크로
선처리 #define 으로 매크로를 정의할 수 있다.

```cpp
#define F first
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
```

SWAP 매크로는 타입을 사용해서

```cpp
SWAP(a, b, int);
```

### 2.2 재귀적 알고리즘

### 2.2.1 부분집합 생성하기

원소가 n개인 집합의 부분집합을 모두 생산하는 알고리즘을 재귀로 구현한다.
하나의 원소씩 포함하거나 제외하는 2^n 번의 과정을 재귀로 구현하기 좋다.

```cpp
void subsets(vector<int>& A, vector<vector<int>>& save, 
                 vector<int>& currentSet, int k) 
{ 
    save.push_back(currentSet); 
    for (int i = k; i < A.size(); i++) { 
        currentSet.push_back(A[i]); // 원소 포함 
        subsets(A, save, currentSet, i+1); 
        currentSet.pop_back(); // 원소 제외
    } 
  
    return; 
} 

```

#### 2.2.2 순열 ( Permutations )

부분집합과 유사한 방법으로 각 원소를 이번 순열에 포함 시켰는지 포함하지 않았는지를 결정하는 배열을 두고 재귀한다.
```cpp
int permutations(int input, vector<vector<int>>& save) 
{
    if (permutationSet.size()==input){
        save.push_back(permutationSet);
    }
    for (int i = 1; i <= input; i++) {
        if(chosen[i])continue;
        chosen[i]=true;
        permutationSet.push_back(i);
        permutations(input,save);
        chosen[i]=false;
        permutationSet.pop_back();
    }    
    return 0; 
}

```

#### 2.2.3 퇴각 검색 ( Backtracking )

## 3장 : 효율성 

이 장은 알고리즘의 시간 복잡도를 다루어 알고리즘의 효율성을 다룬다.
빅오 표기법 (Big-O Notation) 과 앞서 소개된 문제의 시간 복잡도를 설명한다. 

## 4장 : 정렬과 탐색

4장에서는 입력된 데이터를 정렬하고 탐색하는 알고리즘을 다룬다.

### 4.1 정렬 알고리즘 

기본적인 정렬 문제는 원소가 n개 주어질 때 원소들을 크기가 증가하거나 감소하는 순서로 정렬하는 문제이다.

#### 4.1.1 Bubble Sort

버블 정렬(Bubble Sort)는 가장 직관적 정렬 알고리즘으로 *O(n^2)* 시간 동안 동작하며 간단한 2중 for 문으로 구현된다.
```cpp
for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
    }
}
```
가장 큰 원소부터 올바른 위치에 놓이게 되는 원리로 한 페어씩 비교되어 정렬된다.

##### *역위*
*역위 (inversion)* 는 정렬 알고리즘을 분석할 때 유용한 개념이다.
배열의 index 는 a<b 이지만 값 array[a]>array[b] 일때 이를 역위라 한다.
역위의 개수가 배열을 정렬하는데 필요한 작업량을 결정한다.
정렬 알고리즘이 연달아 있는 원소만 바꾼다면 역위의 개수대로 연산을 해야해서 
1+2+ ... (n-1) = n(n-1)/2 = *O(n^2)* 이 될 수 밖에 없다.

#### 4.1.2 Merge Sort

정렬 알고리즘의 효율을 높이기 위해서는 배열의 바로 옆이 아닌 다른 위치에 있는 원소들의 순서를 바로 잡아야 한다.
그러한 방식을 이용하는 병합 정렬 (Merge Sort) 은 *O(n log n)* 시간 복잡도를 가진다.

병합 정렬은 부분 배열 arr[a,...,b]에 대해 다음과 같은 절차를 따라 재귀적으로 실행된다.
1. 원소가 하나 (a==b) 라면 아무것도 하지 않는다.
2. 가운데 원소의 위치를 k = (a+b)/2 로 계산한다.
3. 재귀적으로 arr[a,...,k]를 정렬한다.
4. 재귀적으로 arr[k,...,b]를 정렬한다.
5. 3번의 부분배열과 4번의 부분배열을 병합하여 정렬된 배열 arr[a,...,b]를 만든다.

단계마다 부분배열의 크기를 절반으로 줄여 재귀 호출은 log2(n)으로 O(log n) 이 되고 각 단계의 처리가 *O(n)*이 되어 *O(n log n)* 복잡도가 된다.

```cpp
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
       
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
    else return;
}
```

#### 4.1.3 정렬의 하한 Lower Bound

배열의 원소를 비교하는 연산만으로는 *O(n log n)* 보다 빠르게 정렬할 수 없다.

#### 4.1.4 Counting Sort 

계수정렬(Counting Sort)은 배열의 원소를 직접 비교하지 않고 다른 정보를 이용하여 *O(n log n)* 이라는 하한이 적용되지 않는다. 이 알고리즘은 장부와 같은 배열을 사용하고 이 장부 배열의 인덱스가 원래 배열의 원소가 된다. 
( 원래 배열의 원소가 0 ... c 범위의 정수 일 때만 사용 할 수 있다 )
이 알고리즘은 원래 배열에 1이라는 원소가 3번 들어있으면 장부 배열의 인덱스 1의 값을 3으로 등록하는 알고리즘으로 *O(n)* 시간 만이 걸린다.

#### 4.1.5 실제 상황에서의 정렬

실제 상황에서는 정렬 알고리즘을 구현하지 않고 보통 라이브러리에 있는 정렬 함수를 사용한다.

```cpp
//일반적 벡터의 정렬
vector<int> vect = {6,3,1,5};
sort(vect.begin(),vect.end());
//일반적 배열의 정렬
int arr[] = {6,3,1,5};
int size=sizeof(arr)/sizeof(arr[0]);
sort(arr,arr+size);
```

##### 비교 연산자 (Comparison Operator)
sort 함수를 사용할 때는 원소의 자료형에 대한 비교 연산자가 정의되어 있어야한다.
대부분의 C++ 자료형은 비교연산자가 정의되어있어 숫자는 크기, 문자열은 알파벳 순으로 정렬된다.
두 원소의 pair 의 경우는 첫 원소를 기준으로, 그 다음에는 두 번째 원소를 기준으로 정렬된다.

사용자 정의 구조체는 기본 비교 연산자가 없어 operator< 형식으로 정의해야 한다.
```cpp
struct myStruct {
    int x,y;
    bool operator<(const myStruct &m){
        if(x==m.x)return y<m.y;
        else return x<m.x;
    }
}
```

##### 비교 함수 (Comparison Function)
외부에 정의한 비교 함수를 sort 함수에 콜백 형태로 넘길 수 있다.
```cpp
sort(vect.begin(),vect.end(),compare);
```

### 4.2 정렬을 이용한 문제 풀이

정렬을 하면 효율을 좋게 설게 할 수 있는 알고리즘이 많다. 예를 들어, 한 배열의 모든 원소가 같은가를 검사하는 알고리즘은 이중 for문으로 모든 원소를 모든 원소와 비교하는 방식보다 그 배열을 정렬 한 뒤 옆의 원소와의 비교만을 하는 방식이 효율이 좋다. 
( *O(n^2)* -> *O(n)*)

#### 4.2.1 스윕 라인 알고리즘 (Sweep Line Algorithm)

스윕 라인 알고리즘은 정렬된 순서대로 처리되는 이벤트의 집합으로 알고리즘을 모델링하는 방법이다.

