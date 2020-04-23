//하노이탑 만들기
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
		vector_hanoi.push_back({ a,c }); //N이 1이면 C로 옮긴다.
	}
	else {
		hanoi(N - 1, a, c, b);//자신을 제외한 N-1의 탑을 나머지 칸으로 옮긴다.
		vector_hanoi.push_back({ a,c }); //맨 밑의 탑을 C로 옮긴다.
		hanoi(N - 1, b, a, c); //나머지 칸에 있던 N-1의 탑을 C로 옮긴다.
	}
}