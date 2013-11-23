#include <iostream>
#include <cstdio>
#define MAX_K 15

int main(void)
{
    int k;
    int m;
    int rest;
    int pre_idx, cur_idx;
    int is_find;
    
    while(true)
    {
        scanf("%d", &k);
        if(k == 0)
        {
            break;
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
                break;
            }
        }

        printf("%d\n", m);
    }

    return 0;
}

