#include <iostream>
#include <string.h>

struct Node {
	int x,y;
	int step;
};

const int WIDTH = 8;
const int HEIGHT = 8;

int dir[][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

bool visited[WIDTH][HEIGHT];
Node nodes[WIDTH * HEIGHT];

bool is_same_node(const Node &l_node, const Node &r_node) {
	return l_node.x == r_node.x && l_node.y == r_node.y;
}

bool is_valid_node(int x, int y) {
	return (x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT) && !visited[x][y];
}

int main(void)  {
	int x1, y1;	//start point
	int x2, y2;	//destination point

	char input_1[10], input_2[10];

	while(std::cin >> input_1 >> input_2) {
		memset(visited, 0, sizeof(visited));
		memset(nodes, 0, sizeof(nodes));

		x1 = input_1[0] - 'a';
		y1 = input_1[1] - '1';
		x2 = input_2[0] - 'a';
		y2 = input_2[1] - '1';

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

		std::cout << "To get from " << input_1 << " to "<< input_2 << " takes "  << nodes[start].step << " knight moves." << std::endl;
	}

	return 0;
}