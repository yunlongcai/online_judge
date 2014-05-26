#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

const int MAX_LEN = 151;

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

void multiply(int *lhs, int llen, int *rhs, int rlen, int *result) {
	for(int i = 0; i < llen; i++) {
		for(int j = 0; j < rlen; j++) {
			result[i + j] += lhs[i] * rhs[j];
			result[i + j + 1] += result[i + j] / 10;
			result[i + j] %= 10;
		}
	}
}

void output(int *n, int len) {
	if(len == 0) {
		return;
	}
	for(int i = len - 1; i >= 0; i--) {
		cout << n[i];
	}
	cout << endl;
}

void output(int *n, int len, int dot_pos) {
	if(dot_pos < len) {
		for(int i = len - 1; i >= 0; i--) {
			cout << n[i];
			if(dot_pos == i && i != 0) {
				cout << '.';
			}
		}
		cout << endl;
	} else {
		int leading_zero = dot_pos - len;
		cout << ".";
		for(int i = 0; i < leading_zero; i++) {
			cout << "0";
		}
		output(n, len);
	}
}

void assign(int *n, char *input) {
	int len = strlen(input);
	for(int i = 0; i < len; i++) {
		n[i] = input[len - i - 1] - '0';
	}
}

int main() {
	int a[MAX_LEN], b[MAX_LEN], res[MAX_LEN];
	int dot_pos = 0;
	char input[MAX_LEN + 1];
	int times;


	while(cin >> input) {
		cin >> times;

		if(times == 0) {
			cout << "1" << endl;
			continue;
		}

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(res, 0, sizeof(res));

		int zero_flag = true;
		for(int i = 5, j = 0; i >= 0; i--) {
			if(input[i] == '.') {
				zero_flag = false;
				break;
			}
		}
		for(int i = 5, j = 0; i >= 0; i--) {
			if(input[i] == '.') {
				dot_pos = j;
				zero_flag = true;
			} else if(input[i] != '0'){
				res[j++] = input[i] - '0';
				zero_flag = true;
			} else if(zero_flag) {
				res[j++] = input[i] - '0';
			}
		}

		//for test
		//cout << "length: " << len_of_num(res) << ", output: ";
		//output(res, len_of_num(res));

		if(len_of_num(res) == 0) {
			cout << "0" << endl;
			continue;
		} 

		memcpy(b, res, sizeof(res));

		for(int i = 1; i < times; i++) {
			memcpy(a, res, sizeof(res));
			memset(res, 0, sizeof(res));
			multiply(a, len_of_num(a), b, len_of_num(b), res);
		}

		output(res, len_of_num(res), dot_pos * times);

	}
	return 0;
}
