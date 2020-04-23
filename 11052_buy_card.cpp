#include <iostream>
#include <vector>

using namespace std;

int get_card(int N, vector<int> arr) {
	int result = arr[0]; //���� ó���� ī��
	int best = 0;
	for (int i = 1; i <= N; i++) { //2��°����
		for (int j = 1; j <= i; j++) { //i�� 1�϶� ���� X, i�� 3�϶� j= 2 �ѹ�����, i�� 9�϶� j�� 5�� ����
				result = result > arr[i-j]+arr[j] ? result : arr[i-j]+arr[j];//10��° ī���� 5��° * 2��, 2��° * 5��
				
		}
		arr[i] = result;
			//arr[i]�� ���� ����+ó���� ������ ũ�⸦ ���ؼ� ū���� result��
			
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> card(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	cout << get_card(n, card);

}