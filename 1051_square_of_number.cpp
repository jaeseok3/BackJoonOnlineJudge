#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int find_square(vector<vector<int> > arr) {
	int result = 1;
	for (int i = 0; i < arr.size(); i++) { // �� ��ġ
		for (int j = 0; j < arr[0].size(); j++) { // �� ��ġ
				for (int k = 1; k < arr[0].size() - j && k < arr.size() - i; k++) { //k�� ǥ�� ����� �ʴ� ��������

					if (arr[i][j] == arr[i + k][j + k] &&
						arr[i][j] == arr[i + k][j] &&
						arr[i][j] == arr[i][j + k]) { //k�� �Ÿ���ŭ �ִ� �������� ��� ������
						//�밢��, ������, �Ʒ��� �˻�
						result = result > (k + 1)*(k + 1) ? result : (k + 1)*(k + 1); //k�� ���� �����̹Ƿ� k�� ������Ų��
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

