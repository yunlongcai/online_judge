#include <iostream>
#include <string>

using std::string;

class Solution {
public:
	void  reverse_word(string &s) {
		string res;

		int i = s.length() - 1;
		while(i >= 0) {
			while(i >= 0 && s[i] == ' ') {
				i--;
			}
			if(i >= 0 && !res.empty()) {
				res.push_back(' ');
			}

			string tmp;
			while(i >= 0 && s[i] != ' ') {
				tmp.insert(tmp.begin(), s[i]);
				i--;
			}
			res.append(tmp);
		}

		s = res;
	}
};

int main() {
	string s("A BBB CCC");

	Solution solution;
	solution.reverse_word(s);

	std::cout << s << std::endl;
	std::cout << s.length() << std::endl;

	return 0;
}