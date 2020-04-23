#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int pr[3]; //pr[0] -> -1, pr[1] -> 0, pr[2] -> 1
vector<vector<int> > input; //입력 받을 배열

typedef struct {
	int row;
	int col;
} place; 
void div_paper(int param, place pl) {//배열과 배열 크기, 위치를 인자로 넣음

	if (param == 1) { //크기가 1개면 바로 return 할 수 있게 함.
		if (input[pl.row][pl.col] == 1) {
			pr[2] += 1;
		}
		else if (input[pl.row][pl.col] == 0) {
			pr[1] += 1;
		}
		else if (input[pl.row][pl.col] == -1) {
			pr[0] += 1;
		}
		return;
	}

	for (int i = pl.row; i < pl.row + param; i++) { //행 범위
		for (int j = pl.col; j < pl.col + param; j++) { //열 범위
			if (input[pl.row][pl.col] != input[i][j]) { //다른 값이 존재하면
				int next_param = param / 3; //Delimiter
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) { //9만큼 수행
							div_paper(next_param, { pl.row + (next_param*i),pl.col + (next_param*j) });
							//재귀
						}
					}
					return;
			}
		}
	}
	if (input[pl.row][pl.col]==1) {
		pr[2] += 1;
		return;
	}
	if (input[pl.row][pl.col]==0) {
		pr[1] += 1;
		return;
	}
	if (input[pl.row][pl.col]==-1) {
		pr[0] += 1;
		return;
	}

	
	return;
}
int main() {
	int num = 0;
	scanf("%d", &num);
	place pl = { 0,0 }; //위치
	input.resize(num, vector<int>(num, 0));

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d",&input[i][j]);
		}
	}

	div_paper(num, pl);

	printf("%d\n%d\n%d", pr[0], pr[1], pr[2]);
}
