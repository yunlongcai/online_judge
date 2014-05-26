#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

const int MAX_LEN = 1000;

int len_of_num(int *n) {
	for(int i = MAX_LEN - 1; i >= 0; i--) {
		if(n[i] != 0) {
			return i + 1;
		}
	}
	return 0;
}

void add(int *lhs, int llen, int *rhs, int rlen, int *result) {
	int len = llen > rlen ? llen : rlen;
	int carry = 0;
	for(int i = 0; i < len; i++) {
		int lv = i < llen ? lhs[i] : 0;
		int rv = i < rlen ? rhs[i] : 0;
		result[i] = lv + rv + carry;
		carry = result[i] / 10;
		result[i] %= 10;
	}
	if(carry != 0)  {
		result[len] = carry;
	}
} 

void output(int *n, int len) {
	for(int i = len - 1; i >= 0; i--) {
		cout << n[i];
	}
	cout << endl;
}

void assign(int *n, char *input) {
	int len = strlen(input);
	for(int i = 0; i < len; i++) {
		n[i] = input[len - i - 1] - '0';
	}
}

int main() {
	int a[MAX_LEN], b[MAX_LEN], res[MAX_LEN];
	char input[MAX_LEN + 1];

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(res, 0, sizeof(res));

	int N;
	while(cin >> N) {

		if(N == 0) {
			cout << "0" << endl;
			continue;
		}

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(res, 0, sizeof(res));

		cin >> input;
		assign(res, input);
		for(int i = 1; i < N; i++) {
			memcpy(a, res, sizeof(res));
			memset(res, 0, sizeof(res));
			cin >> input;
			assign(b, input);
			add(a, len_of_num(a), b, len_of_num(b), res);
		}
		output(res, len_of_num(res));
	}
	return 0;
}



