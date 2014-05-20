#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

using std::string;
using std::vector;
using std::stack;

class Solution {
public:
	int evalute_reverse_polish_notation(vector<string> &token) {
		stack<int> num_stack;

		for(int i = 0; i < token.size(); i++) {
			if(is_num(token[i])) {
				num_stack.push(atoi(token[i].c_str()));
			} else {
				int rhs = num_stack.top();
				num_stack.pop();
				int lhs = num_stack.top();
				num_stack.pop();

				switch(token[i][0]) {
					case '+':
						num_stack.push(lhs + rhs);
						break;
					case '-':
						num_stack.push(lhs - rhs);
						break;
					case '*':
						num_stack.push(lhs * rhs);
						break;
					case '/':
						num_stack.push(lhs / rhs);
						break;
					default:
						break;		
				}	
			}
		}

		return num_stack.top();
	}

	bool is_num(string &s) {
		for(int i = 0; i < s.length(); i++) {
			if(s[i] <= '9' && s[i] >= '0') {
				return true;
			}
		}
		return false;
	}

};

int main() {
	//string str[] = {"2", "1", "+", "3", "*"};
	//string str[] = {"4", "13", "5", "/", "+"};
	string str[] = {"-1","1","*","-1","+"};

	std::cout << atoi(str[0].c_str()) << std::endl;

	std::vector<string> token;
	for(int i = 0; i < 5; i++)
		token.push_back(str[i]);

	Solution solution;
	std::cout << solution.evalute_reverse_polish_notation(token) << std::endl;

	return 0;
}