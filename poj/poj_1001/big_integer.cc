#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/**
*positive integer only
*/
class BigInteger {
public:
	BigInteger() : data("0"){
	}

	BigInteger(int n) {
	} 

	BigInteger(const std::string &n) : data(n) {
	}

	BigInteger(const BigInteger &other) : data(other.data) {
	}

	BigInteger &operator=(const BigInteger &other) {
		if(&other == this) {
			return *this;
		}
		this->data = other.data;
		return *this;
	}

	BigInteger operator*(const BigInteger &other) {
		BigInteger bi;
		bi.data.clear();
		int llen = data.length();
		int rlen = data.length();
		for(int i = 0; i < llen; i++) {
			for(int j = 0; j < rlen; j++) {
				int lv = data[i] - '0';
				int rv = other.data[j] - '0';
				int v = lv * rv;
				if(i + j >= bi.data.length()) {
					bi.data.push_back((char)('0' + (v % 10))); 
					if(v / 10) {
						bi.data.push_back((char)('0' + (v / 10))); // carry
					}
				} else {
					v += bi.data[i + j] - '0';
					bi.data[i + j] = (char)('0' + (v % 10));
					if(v / 10) {
						if(i + j + 1 >= bi.data.length()) {
							bi.data.push_back((char)('0' + (v / 10)));
						} else {
							bi.data[i + j + 1] = (char)((bi.data[i + j + 1] - '0') + (v / 10) + '0');
						}
					}
				}
			}
		}

		return bi;
	}

	BigInteger operator+(const BigInteger &other) {
		BigInteger bi;
		bi.data.clear();
		int llen = data.length();
		int rlen = other.data.length();
		int len = llen > rlen ? llen : rlen;
		int carry = 0;
		for(int i = 0; i < len; i++) {
			int lv = i < llen ? data[i] - '0' : 0;
			int rv = i < rlen ? other.data[i] - '0' : 0;
			int v = lv + rv + carry;
			carry = v / 10;
			v %= 10;
			bi.data.push_back((char)('0' + v));
		}
		if(carry) {
			bi.data.push_back((char)('0' + carry));
		}

		return bi;
	}

	friend istream &operator>>(istream &in, BigInteger &bi) {
		std::string tmp; 
		cin >> tmp;
		int len = tmp.length();
		bi.data.clear();
		for(int i = len - 1; i >= 0; i--) {
			bi.data.push_back(tmp[i]);
		}
		return in;
	}

	friend ostream &operator<<(ostream &out, const BigInteger &bi) {
		int len = bi.data.length();
		for(int i = len - 1; i >= 0; i--) {
			out << bi.data[i];
		}
		return out;
	} 

private:
	std::string data;
};

int main() {

	BigInteger a, b;
	std::cin >> a >> b;
	BigInteger sum = a + b;
	std::cout << a <<  " + " << b << " = " << sum << std::endl;
	BigInteger product = a * b;
	std::cout << a << " * " << b << " = " << product << std::endl;


	return 0;
}