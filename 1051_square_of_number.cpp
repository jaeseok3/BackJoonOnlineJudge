#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int find_square(vector<vector<int> > arr) {
	int result = 1;
	for (int i = 0; i < arr.size(); i++) { // 행 위치
		for (int j = 0; j < arr[0].size(); j++) { // 열 위치
				for (int k = 1; k < arr[0].size() - j && k < arr.size() - i; k++) { //k가 표를 벗어나지 않는 범위에서

					if (arr[i][j] == arr[i + k][j + k] &&
						arr[i][j] == arr[i + k][j] &&
						arr[i][j] == arr[i][j + k]) { //k의 거리만큼 있는 꼭짓점이 모두 같을때
						//대각선, 오른쪽, 아래를 검사
						result = result > (k + 1)*(k + 1) ? result : (k + 1)*(k + 1); //k가 변의 길이이므로 k를 제곱시킨다
					}
				}
			
		}
	}
		return result;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int> > arr(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << find_square(arr);
}

