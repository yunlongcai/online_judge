#include <stdio.h>
#include <string.h>

typedef struct item_t
{
    int no;
    int sortness;
} item;

int cmp(const void *lhs, const void *rhs)
{
    const item *ldna = (item *) lhs;
    const item *rdna = (item *) rhs;

    return ldna->sortness - rdna->sortness;
}

int get_unsortness(char *str, int len)
{
    int unsortness = 0;
    int i, j;
    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                unsortness++;
            }
        }
    }
    return unsortness;
}


int main()
{
    int n, m;
    int i;
    char dna[100][50 + 1];
    item items[100];

    scanf("%d%d", &n, &m);

    memset(dna, 0, sizeof(dna));
    for(i = 0; i < m; i++)
    {
        scanf("%s", dna[i]);
        items[i].no = i;
        items[i].sortness = get_unsortness(dna[i], n);
    }

    qsort(items, m, sizeof(item), cmp);

    for(i = 0; i < m; i++)
    {
        printf("%s\n", dna[items[i].no]);
    }

    return 0;
}
