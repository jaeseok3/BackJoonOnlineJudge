//�ϳ���ž �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void hanoi(int a, int b, int c, int d);
vector<vector<int> > vector_hanoi;

int main() {
	int N;
	scanf("%d",&N);
	
	
	hanoi(N, 1, 2, 3);
	printf("%d\n",vector_hanoi.size());
	for (int i = 0; i < vector_hanoi.size(); i++) {
		printf("%d %d\n", vector_hanoi[i][0], vector_hanoi[i][1]);
	}
}

void hanoi(int N, int a, int b, int c) {
	if (N == 1) {
		vector_hanoi.push_back({ a,c }); //N�� 1�̸� C�� �ű��.
	}
	else {
		hanoi(N - 1, a, c, b);//�ڽ��� ������ N-1�� ž�� ������ ĭ���� �ű��.
		vector_hanoi.push_back({ a,c }); //�� ���� ž�� C�� �ű��.
		hanoi(N - 1, b, a, c); //������ ĭ�� �ִ� N-1�� ž�� C�� �ű��.
	}
}