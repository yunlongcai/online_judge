#include <stdio.h>
#include <math.h>

int main(void)
{
    int p;
    int circle;
    int pre_num;
    float n, m;
    int i, j;
    int x, y;
    int dir[][2] = {
        {-1, 1},
        {-1, 0},
        {0, -1},
        {1, -1},
        {1, 0},
        {0, 1}
    };

    while(scanf("%d", &p) != EOF)
    {
        n = sqrt(12 * p - 3);
        m = n / 6 - (float)1 / 2;

        circle = ceil(m);
        if(circle == 0)
        {
            printf("0 0\n");
            continue;
        }
    

        pre_num = 3 * (circle - 1) * (circle - 1) + 3 * (circle - 1) + 1;
        x = circle - 1;
        y = 0;

        pre_num++;
        x += dir[5][0];
        y += dir[5][1];
        
        for(j = 1; j < circle && pre_num != p; j++)
        {
            x += dir[0][0];
            y += dir[0][1];

            pre_num++;
        }
    

        for(i = 1; i < 6; i++)
        {
            for(j = 0; j < circle && pre_num != p; j++)
            {
                x += dir[i][0];
                y += dir[i][1];

                pre_num++;
            }
        }
        
        printf("%d %d\n", x, y);

    }

    return 0;
}
