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
		arr[srt - 1][dst - 1] = arr[dst - 1][srt - 1] = 1; //�ش��ϴ� �迭 �� 1�� �ʱ�ȭ
	}

	dfs(N, M, V, arr);
	bfs(N, M, V, arr);
}

void dfs(int n, int m, int v, vector<vector<int> > arr) {
	int* check = new int[n] {0};
	stack<int> s;
	cout << v << " "; //ù ��° ��带 ���
	s.push(v);
	check[v - 1] = 1;
	for (int i = 0; i < m; i++) { //branch�� ������ŭ ����(�湮 Ƚ��)
		for (int j = 0; j < n; j++) { //node�� ������ŭ ����(��� ��带 Ž���ϴ� Ƚ��)
			
			if (s.size() == 0) { 
				//stack�� ũ�Ⱑ 0�̸� ��� node�� Ž�������Ƿ� Ž�� ����
				break;
			}
			if (arr[s.top()-1][j] == 1 && check[j] == 0) { 
				//�湮���� ���� ����߿��� ���� ��ġ���� �̵��� �� �ִ� ��尡 �����ϴ��� ���θ� �Ǵ�

				cout << j+1 << " "; //�� ���
				check[j] = 1;
				s.push(j+1); //�ش��ϴ� �� �ֱ�
				break; //stack�� top�� �ٲ�����Ƿ� loop ����������
			}
			if (j == n - 1 && s.size() != 0) {
				s.pop(); //�ش� node���� ���̻� �湮�� ���� ������ pop���Ѽ� depth�� ���� ��ĭ �ö󰡱�
			}
		}
	}
	cout << endl;
}

void bfs(int n, int m, int v, vector<vector<int> > arr) {
	int* check = new int[n] {0}; //�湮�� Ȯ���ϱ� ���� ��


	cout << v << " "; //ù��° ��带 ���
	queue<int> q;
	q.push(v); //ť�� ù��° ��带 push
	check[v - 1] = 1;
	for (int i = 0; i < m; i++) { //�ι�° ������ ��� 
		int frontQ=0;
		if (q.size() != 0) { //ť�� ����� 0�� �ƴ϶��
			frontQ = q.front(); //ť�� ���� ���� ���� �޾ƿ�. ��, ���� ���
			q.pop();//���� ���� ����
		}
		else { //ť�� ũ�Ⱑ 0�̵Ǹ� ��� pop�� �������Ƿ� ����
			break;
		}
		for (int j = 1; j < n+1; j++) {
			if (arr[frontQ-1][j-1] == 1 && check[j-1]==0) { //ť�� ���� �տ����� �ߺ����� �ʰ���
				
				q.push(j); //ť�� ���� �������
				check[j-1] = 1; //�ߺ����� �ʰ� flag ����
				cout << j << " ";
			}
		}
	}
}