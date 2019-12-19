## *알고리즘 트레이닝* 의 정리
#### ( *Guide to Competitive Programming: Learning and Improving Algorithms Through Contests* by Antti Laaksonen )

#### 1장 생략

#### 2장 : 프로그래밍 기법 *Programming Techniques*
이 장은 C++ 프로그래밍의 특징, 재귀, 비트연산을 다룬다.

1. 언어적 특성 *Language Features*
   
   표쥰적 경진 프로그래밍 코드 형태 :
   ```
   #include <bits.stdc++>
   using namespace std;
   int main(){
       //code
   }
   ```
   <bits.stdc++> 은 표준 라이브러리 전체를 포함한다. (iostream, vector, algrotihm 등 포함)

    1. 입력과 출력

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

    2. 수의 처리
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
      
    3. 짧은 코드
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

2. 재귀적 알고리즘
   
3. 비트 연산

#### 3장 : 효율성 *Programming Techniques*