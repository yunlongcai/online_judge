#include <iostream>
#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

typedef struct node_t
{
    int puzzle[9];
    int zero_pos;
    int pre_idx;
    char op;
} Node;

int cantor(int *arr, int len)
{
    int can = 0;
    int i, j, t;
    for(i = 0; i < len; i++)
    {
        t = 0;
        for(j = i + 1; j < len; j++)
        {
            if(arr[i] > arr[j])
            {
                t++;
            }
        }
        can += t * fact[len - i - 1];
    }
    return can;
}

void swap(int *arr, int l, int r)
{
    /*
    arr[l] ^= arr[r];
    arr[r] ^= arr[l];
    arr[l] ^= arr[r];
    */

    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}   

Node nodes[362880 + 1];
int used[362880 + 1];
int regular_puzzle[9] = {1, 2, 3,
                         4, 5, 6,
                         7, 8, 0};                         

int main(void)
{
    int puzzle[9];
    char c;
    int i;
    int cur_idx, last_idx;
    int regular_cantor, can;
    bool is_end;
    stack<Node> solution;

    for(i = 0; i < 9; i++)
    {
        //scanf("%c", &c);
        cin >> c;
        if(c == 'x')
        {
            puzzle[i] = 0;
        }
        else
        {
            puzzle[i] = c - '0';
        }
    }
   
//    for(i = 0; i < 9; i++)
//    {
//        cout << puzzle[i] << endl;
//    }

    is_end = 0;
    memset(used, 0, sizeof(used));

    //first state
    cur_idx = 0;
    last_idx = 0;
    Node init_node;
    memcpy(init_node.puzzle, puzzle, sizeof(puzzle));
    init_node.pre_idx = -1;
    init_node.op = '-';
    for(i = 0; i < 9; i++)
    {
        if(puzzle[i] == 0)
        {
            init_node.zero_pos = i;
        }
    }
    //solution.push(init_node);
    nodes[last_idx++] = init_node;
    regular_cantor = cantor(regular_puzzle, 9);

    while(!is_end && cur_idx < last_idx)
    {
        Node cur_node = nodes[cur_idx];
        for(i = 0; i < 9; i++)
        {
            if(cur_node.puzzle[i] != regular_puzzle[i])
            {
                break;
            }
        }
        if(i == 9)
        {
            is_end = 1;
            break;
        }

        Node next_node;
        //find next states
        
        //up
        if(cur_node.zero_pos >= 3)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, cur_node.zero_pos, cur_node.zero_pos - 3);
            next_node.zero_pos = cur_node.zero_pos - 3;
            next_node.pre_idx = cur_idx;
            next_node.op = 'u';

            can = cantor(next_node.puzzle, 9);
            if(!used[can])
            {
                nodes[last_idx++] = next_node;
                used[can] = 1;
            }
        }

        //down
        if(cur_node.zero_pos < 6)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, cur_node.zero_pos, cur_node.zero_pos + 3);
            next_node.zero_pos = cur_node.zero_pos +  3;
            next_node.pre_idx = cur_idx;
            next_node.op = 'd';

            can = cantor(next_node.puzzle, 9);
            if(!used[can])
            {
                nodes[last_idx++] = next_node;
                used[can] = 1;
            }
        }

        //left
        if(cur_node.zero_pos % 3 != 0)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, cur_node.zero_pos, cur_node.zero_pos - 1);
            next_node.zero_pos = cur_node.zero_pos - 1;
            next_node.pre_idx = cur_idx;
            next_node.op = 'l';

            can = cantor(next_node.puzzle, 9);
            if(!used[can])
            {
                nodes[last_idx++] = next_node;
                used[can] = 1;
            }
        }

        //right
        if((cur_node.zero_pos + 1) % 3 != 0)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, cur_node.zero_pos, cur_node.zero_pos + 1);
            next_node.zero_pos = cur_node.zero_pos + 1;
            next_node.pre_idx = cur_idx;
            next_node.op = 'r';

            can = cantor(next_node.puzzle, 9);
            if(!used[can])
            {
                nodes[last_idx++] = next_node;
                used[can] = 1;
            }
        }
        
        cur_idx++;
    }
    if(is_end)
    {
        Node node = nodes[cur_idx];
        while(node.pre_idx != -1)
        {
            solution.push(node);
            node = nodes[node.pre_idx];
        }

        while(!solution.empty())
        {
            Node node = solution.top();
            printf("%c", node.op);
            solution.pop();
        }
        printf("\n");
    }
    else
    {
        printf("unsolvable\n");
    }

    return 0;
}
