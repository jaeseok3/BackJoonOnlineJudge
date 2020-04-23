#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

typedef struct {
	int row;
	int col;
	int depth;
} Position;

int bfs_find(vector<vector<int> > arr) {
	vector<int> ar;
	Position p = { 0,0,1 };
	vector<vector<int> > check(arr.size(), vector<int>(arr[0].size(), 0));
	queue<Position> point;
	
	point.push(p);

	while (point.size() > 0) {
		
		Position pos = point.front(); //���� ��ġ
		int p = point.front().depth;
		
		 //���̰� ��������� count++
		
		point.pop(); //���� ��ġ�� ã������ pop���Ѽ� �ϳ��� �б�

		if (pos.row<arr.size()-1 && arr[pos.row + 1][pos.col] == 1 && check[pos.row + 1][pos.col] == 0) { //�ؿ��� �湮���� �ʾҰ� 1�̶��
			point.push({ pos.row + 1, pos.col,p+1}); //ť�� ����ֱ�
			check[pos.row + 1][pos.col] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point�� ���� N-1,M-1�̶��
				
				break;
			}
		}
		if (pos.col<arr[0].size()-1 && arr[pos.row][pos.col+1] == 1 && check[pos.row][pos.col+1] == 0) { //�������� �湮���� �ʾҰ� 1�̶��
			point.push({ pos.row, pos.col+1,p+1}); //ť�� ����ֱ�(depth 1����)
			check[pos.row][pos.col + 1] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point�� ���� N-1,M-1�̶��
				
				break;
			}
		}
		if (pos.row-1 >= 0 && arr[pos.row-1][pos.col] == 1 && check[pos.row-1][pos.col] == 0) { //���� �湮���� �ʾҰ� 1�̶��
			point.push({ pos.row-1, pos.col,p+1}); //ť�� ����ֱ�
			check[pos.row - 1][pos.col] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point�� ���� N-1,M-1�̶��
				
				break;
			}
		}
		if (pos.col - 1 >= 0 && arr[pos.row][pos.col-1] == 1 && check[pos.row][pos.col-1] == 0) { //���� �湮���� �ʾҰ� 1�̶��
			point.push({ pos.row, pos.col-1,p+1}); //ť�� ����ֱ�
			check[pos.row][pos.col-1] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point�� ���� N-1,M-1�̶��
				break;
			}
		}
		//���� �ƹ����� �湮�Ұ��� ������ while�� �ѹ� �� ���Եǰ� ���� queue�� Ȯ���ϰ� ��
	}
	return point.back().depth;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int> > input(N,vector<int> (M,0));
	int a = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a);
			input[i][j] = a;
		}
	}

	cout << bfs_find(input);
}