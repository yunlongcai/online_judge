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
    
    int n;
    int flag;
    while(true)
    {
        scanf("%d", &k);
        if(k == 0)
        {
            break;
        }

        n = 0;
        flag = 0;
        m = k;
        is_find = 0;
        while(true)
        {
            rest = k * 2;
            cur_idx = 0;
            if(flag)
            {
                m = (k + 1) * n + 1;
                flag = 0;
                n++;
            }
            else
            {
                m = (k + 1) * n;
                flag = 1;
            }
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

