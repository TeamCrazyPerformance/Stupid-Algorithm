# 그래프 알고리즘

## 그래프 기본

### 그래프 용어
- 그래프 : 노드와 그들을 잇는 간선으로 구성
- 경로 : 한 노드에서 그래프의 간선을 지나 다른 노드까지 가는 길을 의미
- 연결 그래프 : 모든 노드간에 경로가 있는 그래프
- 컴포넌트 : 그래프의 연결된 부분
- 방향 그래프 : 간선의 한 방향으로만 이동할 수 있는 그래프
- 가중 그래프 : 간선마다 가중치가 존재하는 그래프
- 이웃 : 간선으로 연결되어 인접한 노드
- 차수 : 이웃노드의 개수
- 정규 그래프 : 모든 노드의 차수가 같은 그래프
- 완전 그래프 : 모든 두 노드 간에 간선이 있는 그래프
- 진입 차수 : 그 노드로 향하는 간선의 개수
- 진출 차수 : 그 노드에서 시작하는 간선의 개수
- 이분 그래프 : 모든 노드를 두 가지 색깔 중 하나로 칠하되, 이웃 노드의 색깔이 같은 경우가 없는 그래프

### 그래프 표현
- 인접 리스트 : 그래프의 각 노드 x에 대한 인접 리스트, 즉 x에서 출발하는 간선이 있는 노드의 리스트
- 인접 행렬 : 그래프에 포함된 간선을 나타내는 행렬
- 간선 리스트 : 그래프의 모든 간선을 특정한 순서에 따라 저장한 리스트

## 그래프 순회

### 깊이우선탐색 DFS
- 시작 노드에서부터 출발하여 그래프의 간선을 따라 이동해가며 도달 가능한 모든 노드를 처리
![https://t1.daumcdn.net/cfile/tistory/23357644591DCAA123]


### 너비우선탐색 BFS
- 시작 노드에서 각 노드까지의 거리가 증가하는 순서대로 노드를 방문
![https://t1.daumcdn.net/cfile/tistory/23357644591DCAA123]

### 응용
- 연결성 확인 : 임의의 노드에서 출발하여 모든 노드를 방문한다면 연결 그래프라고 판단
- 사이클 찾기 : 이미 방문했던 노드가 이웃노드에 포함되어 있다면 사이클이 있다고 판단
- 이분성 확인 : 이웃한 두 노드가 같은 색깔이라면 이분 그래프라고 판단

## 최단경로
- 가중치가 없는 그래프의 경우, 경로의 길이가 간선의 개수와 같으므로 너비우선탐색을 이용하여 최단 경우를 구할 수 있음
- 가중치가 있는 그래프의 경우, 다음과 같은 알고리즘으로 구할 수 있음

### 벨만 포드 알고리즘
- 시작노드에서 다른 노드 까지의 길이를 모두 추적한다. 거리의 초깃값은 시작 노드의 경우 0 이고 다른 모든 노드의 경우 무한대의 값으로 설정된다. 그리고 이값을 계속해서 줄여나가는 과정을 더는 줄일 수 있는 값이 없을때까지 반복한다.
- 벨만 포드 알고리즘을 n번의 라운드로 진행했을 때, 마지막 라운드에서도 거리가 줄어드는 경우가 있다면 음수사이클이 존재함을 알 수 있다.

![.](http://mblogthumb3.phinf.naver.net/MjAxNzAxMDVfMTY4/MDAxNDgzNTQzMzA1MDIy.LAQdHxB9WtH_CBECnXc8ynylJmnwwLHakc0CfsRd0h4g.o4W4vUQvIsK6jw2di-IUHBCxFyRIK5Ptwvjme7LVmjEg.JPEG.yeop9657/bellman.jpg?type=w800)

### 다익스트라 알고리즘
- 효율적이지만 음수 가중치가 없는 경우에만 사용할 수 있다.
- 아직 처리하지 않은 노드 중 거리가 가장 작은 노드를 찾고, 그 노드에서 시작하는 모든 간선을 쭉 살펴보며 노드까지의 거리를 줄일 수 있다면 줄인다.

![.](https://mblogthumb-phinf.pstatic.net/20151001_11/babobigi_1443697819836o9NVh_JPEG/dijkstra.jpg?type=w2)

### 플로이드-워셜 알고리즘
- 알고리즘을 단 한번 실행하므로써 모든 노드 간 최단 경로를 구할 수 있다는 데 있다.
- 인접 행렬을 초기값으로 가진 후, 라운드마다 각 경로에서 새로운 중간 노드로 사용할 수 있는 노드를 선택하고 거리를 줄이는 과정을 반복한다.

![.](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F996CA43359E578C712C312)
![.](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F99D28C3359E578ED1CAB50)
![.](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F990A863359E5791214F6CF)
![.](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F999F2A3359E57954021647)
![.](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F996FEF3359E5798A11640A)

### 프림 알고리즘
- 모든 꼭짓점이 트리에 포함되어 있지 않은 동안 트리와 연결된 변 가운데 트리 속의 두 꼭짓점을 연결하지 않는 가장 가중치가 작은 변을 트리에 추가한다.

![.](https://gmlwjd9405.github.io/images/algorithm-mst/prim-example.png)

### 크루스칼 알고리즘
- 간선들을 오름차순으로 정렬한 뒤에 순서대로 사이클을 형성하지 않는 간선을 선택한다.

![.](https://gmlwjd9405.github.io/images/algorithm-mst/kruskal-example2.png)
