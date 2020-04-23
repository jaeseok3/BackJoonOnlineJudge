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
		
		Position pos = point.front(); //현재 위치
		int p = point.front().depth;
		
		 //깊이가 길어질수록 count++
		
		point.pop(); //현재 위치를 찾았으니 pop시켜서 하나씩 밀기

		if (pos.row<arr.size()-1 && arr[pos.row + 1][pos.col] == 1 && check[pos.row + 1][pos.col] == 0) { //밑에를 방문하지 않았고 1이라면
			point.push({ pos.row + 1, pos.col,p+1}); //큐에 집어넣기
			check[pos.row + 1][pos.col] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point의 끝이 N-1,M-1이라면
				
				break;
			}
		}
		if (pos.col<arr[0].size()-1 && arr[pos.row][pos.col+1] == 1 && check[pos.row][pos.col+1] == 0) { //오른쪽을 방문하지 않았고 1이라면
			point.push({ pos.row, pos.col+1,p+1}); //큐에 집어넣기(depth 1증가)
			check[pos.row][pos.col + 1] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point의 끝이 N-1,M-1이라면
				
				break;
			}
		}
		if (pos.row-1 >= 0 && arr[pos.row-1][pos.col] == 1 && check[pos.row-1][pos.col] == 0) { //위를 방문하지 않았고 1이라면
			point.push({ pos.row-1, pos.col,p+1}); //큐에 집어넣기
			check[pos.row - 1][pos.col] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point의 끝이 N-1,M-1이라면
				
				break;
			}
		}
		if (pos.col - 1 >= 0 && arr[pos.row][pos.col-1] == 1 && check[pos.row][pos.col-1] == 0) { //위를 방문하지 않았고 1이라면
			point.push({ pos.row, pos.col-1,p+1}); //큐에 집어넣기
			check[pos.row][pos.col-1] = 1;
			if (point.back().row == arr.size() - 1 && point.back().col == arr[0].size() - 1) { //point의 끝이 N-1,M-1이라면
				break;
			}
		}
		//만약 아무곳도 방문할곳이 없으면 while을 한번 더 돌게되고 다음 queue를 확인하게 됨
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