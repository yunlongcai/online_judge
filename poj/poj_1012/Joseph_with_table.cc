#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX_K 15

int main(void)
{
    int k;
    int m;
    int rest;
    int pre_idx, cur_idx;
    int is_find;

    int table[MAX_K];

    memset(table, 0, sizeof(table));

    while(true)
    {
        scanf("%d", &k);
        if(k == 0)
        {
            break;
        }

        if(table[k] != 0)
        {
            printf("%d\n", table[k]);
            continue;
        }

        m = k;
        is_find = 0;
        while(true)
        {
            rest = k * 2;
            m++;
            cur_idx = 0;
            while(true)
            {
                cur_idx = (cur_idx + m - 1) % rest;
                if(cur_idx < k)
                {
                    break;
                }
                rest--;

                if(rest == k)
                {
                    is_find = 1;
                    break;
                }
            }
            if(is_find)
            {
                table[k] = m;
                break;
            }
        }

        printf("%d\n", m);
    }

    return 0;
}

