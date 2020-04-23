#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

void bfs(int a, int b, int c, vector<vector<int> > arr);
void dfs(int a, int b, int c, vector<vector<int> > arr);

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	int srt, dst;
	vector<vector<int> > arr(N, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		cin >> srt >> dst;
		arr[srt - 1][dst - 1] = arr[dst - 1][srt - 1] = 1; //해당하는 배열 값 1로 초기화
	}

	dfs(N, M, V, arr);
	bfs(N, M, V, arr);
}

void dfs(int n, int m, int v, vector<vector<int> > arr) {
	int* check = new int[n] {0};
	stack<int> s;
	cout << v << " "; //첫 번째 노드를 출력
	s.push(v);
	check[v - 1] = 1;
	for (int i = 0; i < m; i++) { //branch의 갯수만큼 수행(방문 횟수)
		for (int j = 0; j < n; j++) { //node의 갯수만큼 수행(모든 노드를 탐색하는 횟수)
			
			if (s.size() == 0) { 
				//stack의 크기가 0이면 모든 node를 탐색했으므로 탐색 종료
				break;
			}
			if (arr[s.top()-1][j] == 1 && check[j] == 0) { 
				//방문하지 않은 노드중에서 현재 위치에서 이동할 수 있는 노드가 존재하는지 여부를 판단

				cout << j+1 << " "; //값 출력
				check[j] = 1;
				s.push(j+1); //해당하는 값 넣기
				break; //stack의 top이 바뀌었으므로 loop 빠져나가기
			}
			if (j == n - 1 && s.size() != 0) {
				s.pop(); //해당 node에서 더이상 방문할 곳이 없으면 pop시켜서 depth를 위로 한칸 올라가기
			}
		}
	}
	cout << endl;
}

void bfs(int n, int m, int v, vector<vector<int> > arr) {
	int* check = new int[n] {0}; //방문을 확인하기 위한 값


	cout << v << " "; //첫번째 노드를 출력
	queue<int> q;
	q.push(v); //큐에 첫번째 노드를 push
	check[v - 1] = 1;
	for (int i = 0; i < m; i++) { //두번째 노드부터 계산 
		int frontQ=0;
		if (q.size() != 0) { //큐의 사이즈가 0이 아니라면
			frontQ = q.front(); //큐의 가장 앞의 값을 받아옴. 즉, 현재 노드
			q.pop();//사용된 노드는 제거
		}
		else { //큐의 크기가 0이되면 모든 pop이 끝났으므로 종료
			break;
		}
		for (int j = 1; j < n+1; j++) {
			if (arr[frontQ-1][j-1] == 1 && check[j-1]==0) { //큐의 가장 앞에값이 중복되지 않게함
				
				q.push(j); //큐에 값을 집어넣음
				check[j-1] = 1; //중복되지 않게 flag 설정
				cout << j << " ";
			}
		}
	}
}