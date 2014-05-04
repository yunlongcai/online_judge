#include <iostream>
#include <string.h>

struct Node {
	int x, y;
	int step;
};

int dir[][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
const int MAX_LENGTH = 300;
int length;

bool visited[MAX_LENGTH][MAX_LENGTH];
Node nodes[MAX_LENGTH * MAX_LENGTH];

bool is_same_node(const Node &l_node, const Node &r_node) {
	return l_node.x == r_node.x && l_node.y == r_node.y;
}

bool is_valid_node(int x, int y) {
	return (x >= 0 && x < length) && (y >= 0 && y < length) && !visited[x][y];
}

int main(void) {
	int T;
	std::cin >> T;

	int x1, y1;
	int x2, y2;
	while(T--) {
		std::cin >> length >> x1 >> y1 >> x2 >> y2;
		memset(visited, 0, sizeof(visited));
		memset(nodes, 0, sizeof(nodes));

		int start = 0;
		int end = 1;

		nodes[start].x = x1;
		nodes[start].y = y1;
		nodes[start].step = 0;
		visited[x1][y1] = true;

		Node dest_node;
		dest_node.x = x2;
		dest_node.y = y2;

		while(start < end) {
			if(is_same_node(dest_node, nodes[start])) {
				break;
			}

			for(int i = 0; i < 8; i++) {
				int new_x = nodes[start].x + dir[i][0];
				int new_y = nodes[start].y + dir[i][1];

				if(is_valid_node(new_x, new_y)) {
					visited[new_x][new_y] = true;
					nodes[end].x = new_x;
					nodes[end].y = new_y;
					nodes[end].step = nodes[start].step + 1;
					end++;
				}
			}
			start++;
		}
		std::cout << nodes[start].step << std::endl;
	}

	return 0;
}
