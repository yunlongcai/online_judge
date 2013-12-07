#include <iostream>
#include <cstdio>
#include <string.h>
#include <stack>

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
int main()
{
    //int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int arr[9] = {8,7,6,5,4,3,2,1,0};
    printf("%d\n", cantor_expand(arr, 9));

    return 0;
}
