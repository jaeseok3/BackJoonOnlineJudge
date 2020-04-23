#include <iostream>
#include <vector>

using namespace std;

int get_card(int N, vector<int> arr) {
	int result = arr[0]; //제일 처음의 카드
	int best = 0;
	for (int i = 1; i <= N; i++) { //2번째부터
		for (int j = 1; j <= i; j++) { //i가 1일때 수행 X, i가 3일때 j= 2 한번수행, i가 9일때 j는 5로 수행
				result = result > arr[i-j]+arr[j] ? result : arr[i-j]+arr[j];//10번째 카드라면 5번째 * 2개, 2번째 * 5개
				
		}
		arr[i] = result;
			//arr[i]과 앞의 가격+처음의 가격의 크기를 비교해서 큰것을 result에
			
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