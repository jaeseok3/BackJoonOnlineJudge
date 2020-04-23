#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int pr[3]; //pr[0] -> -1, pr[1] -> 0, pr[2] -> 1
vector<vector<int> > input; //�Է� ���� �迭

typedef struct {
	int row;
	int col;
} place; 
void div_paper(int param, place pl) {//�迭�� �迭 ũ��, ��ġ�� ���ڷ� ����

	if (param == 1) { //ũ�Ⱑ 1���� �ٷ� return �� �� �ְ� ��.
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

	for (int i = pl.row; i < pl.row + param; i++) { //�� ����
		for (int j = pl.col; j < pl.col + param; j++) { //�� ����
			if (input[pl.row][pl.col] != input[i][j]) { //�ٸ� ���� �����ϸ�
				int next_param = param / 3; //Delimiter
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) { //9��ŭ ����
							div_paper(next_param, { pl.row + (next_param*i),pl.col + (next_param*j) });
							//���
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
	place pl = { 0,0 }; //��ġ
	input.resize(num, vector<int>(num, 0));

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d",&input[i][j]);
		}
	}

	div_paper(num, pl);

	printf("%d\n%d\n%d", pr[0], pr[1], pr[2]);
}
