#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int get_coin(vector<int> coin, int value) {
	int count = 0;
	int i = coin.size() - 1; //���� ��� ��
	while (value != 0) { //���� 0���� �� �� ����
		while(1){//���� ��Ѱ� ���� ��
			if (value-coin[i] >= 0) { //������ ũ�Ⱑ value����������
				value -= coin[i]; //����ؼ� ����
				count++;
			}
			else {
				i--; //������ ũ�Ⱑ value���� ũ�� �������� ���� ���� Ž��
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