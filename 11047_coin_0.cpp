#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int get_coin(vector<int> coin, int value) {
	int count = 0;
	int i = coin.size() - 1; //가장 비싼 값
	while (value != 0) { //돈이 0원이 될 때 까지
		while(1){//가장 비싼것 부터 비교
			if (value-coin[i] >= 0) { //동전의 크기가 value보다작으면
				value -= coin[i]; //계속해서 뺀다
				count++;
			}
			else {
				i--; //동전의 크기가 value보다 크면 다음으로 작은 동전 탐색
				break; 
			}
		}
	}

	return count;
}

int main() {
	int value = 0;
	int num_coin = 0;
	scanf("%d %d", &num_coin, &value);

	vector<int> coin(num_coin);
	for (int i = 0; i < coin.size(); i++) {
		scanf("%d", &coin[i]);
	}

	printf("%d", get_coin(coin, value));
}