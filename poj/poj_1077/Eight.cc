#include <iostream>
#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

typedef struct node_t
{
    int puzzle[9];
    int zero;
    int pre;
    char op;
} Node;

int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int cantor_expand(int *arr, int len)
{
    int cantor = 0;
    int i;
    
    for(i = 0; i < len; i++)
    {
        cantor += (arr[i]) * fact[len - i - 1];
    }

    return cantor;
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

int regular_puzzle[9] = { 
                            1, 2, 3,
                            4, 5, 6,
                            7, 8, 0
                        };    

Node states[362880 + 1];

int main()
{
    int puzzle[9], cur_puzzle[9];
    int i, j;
    char c;
    bool unsolved_state[362880 + 1];
    bool used[362880 + 1];
    bool is_end;
    int cantor;
    int unread_idx, cur_idx;
    std::stack<Node> solved_seq;

    memset(unsolved_state, 0, sizeof(unsolved_state));
    memset(used, 0, sizeof(used));

    //get all unsolevd state
    for(i = 0; i < 8; i++)
    {
        for(j = i + 1; j < 8; j++)
        {
            memcpy(cur_puzzle, regular_puzzle, sizeof(puzzle));
            swap(cur_puzzle, i, j);
            cantor = cantor_expand(cur_puzzle, 9); 
            unsolved_state[cantor_expand(cur_puzzle, 9)] = 1;
        }
    }

    for(i = 0; i < 9; i++)
    {
        scanf("%c", &c);
        if(c != 'x')
        {
            puzzle[i] = c - '0';
        }
        else
        {
            puzzle[i] = 0;
        }
    }

    //first state
    Node node;
    memcpy(node.puzzle, puzzle, sizeof(puzzle));
    node.pre = -1;
    node.op = 'x';
    for(i = 0; i < 9; i++)
    {
        if(node.puzzle[i] == 0)
        {
            node.zero = i;
            break;
        }
    }
    states[0] = node;
    cantor = cantor_expand(node.puzzle, 9);
    used[cantor] = 1;
    if(unsolved_state[cantor])
    {
        is_end = 1;
        printf("unsolvable\n");
    }

    unread_idx = 0;
    cur_idx = 0;
    while(unread_idx <= cur_idx && !is_end)
    {
        Node cur_node = states[unread_idx];
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
        if(cur_node.zero >= 3)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, next_node.zero, next_node.zero - 3);
            next_node.zero -= 3;
            next_node.pre = unread_idx;
            next_node.op = 'u';

            cantor = cantor_expand(next_node.puzzle, 9);
            if(unsolved_state[cantor])
            {
                printf("unsolvable\n");
                break;
            }

            if(!used[cantor])
            {
                states[cur_idx++] = next_node;
                used[cantor] = 1;
            }
        }
        
        //down
        if(cur_node.zero < 6)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, next_node.zero, next_node.zero + 3);
            next_node.zero += 3;
            next_node.pre = unread_idx;
            next_node.op = 'd';

            cantor = cantor_expand(next_node.puzzle, 9);
            if(unsolved_state[cantor])
            {
                printf("unsolvable\n");
                break;
            }

            if(!used[cantor])
            {
                states[cur_idx++] = next_node;
                used[cantor] = 1;
            }
        }            

        //left
        if(cur_node.zero % 3 != 0)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, next_node.zero, next_node.zero - 1);
            next_node.zero -= 1;
            next_node.pre = unread_idx;
            next_node.op = 'l';

            cantor = cantor_expand(next_node.puzzle, 9);
            if(unsolved_state[cantor])
            {
                printf("unsolvable\n");
                break;
            }

            if(!used[cantor])
            {
                states[cur_idx++] = next_node;
                used[cantor] = 1;
            }
        }

        //right
        if((cur_node.zero + 1) % 3 != 0)
        {
            memcpy(next_node.puzzle, cur_node.puzzle, sizeof(next_node.puzzle));
            swap(next_node.puzzle, next_node.zero, next_node.zero + 1);
            next_node.zero += 1;
            next_node.pre = unread_idx;
            next_node.op = 'r';

            cantor = cantor_expand(next_node.puzzle, 9);
            if(unsolved_state[cantor])
            {
                printf("unsolvable\n");
                break;
            }

            if(!used[cantor])
            {
                states[cur_idx++] = next_node;
                used[cantor] = 1;
            }
        }

        unread_idx++;
    }

    if(is_end)
    {
        Node solved_node = states[unread_idx];
        solved_seq.push(solved_node);
        
        while(solved_node.pre != -1)
        {
            solved_node = states[solved_node.pre];
            solved_seq.push(solved_node);
        }
        
        while(!solved_seq.empty())
        {
            solved_node = solved_seq.top();
            printf("%c", solved_node.op);
            solved_seq.pop();
        }
        printf("\n");
    }
        

    return 0;
}
