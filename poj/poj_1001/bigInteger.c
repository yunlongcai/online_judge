#include <stdio.h>
#include <string.h>

#define MAX_INT_LENGTH 100


static void changeCharToInt(char *str, int *int_arr, int len)
{
    int i;
    memset(int_arr, 0, sizeof(int_arr));

    for(i = MAX_INT_LENGTH - 1; i > MAX_INT_LENGTH - len; i--)
    {
        int_arr[i] = str[MAX_INT_LENGTH - i - 1] - '0';
    }
}


int main()
{
    int  num_1[MAX_INT_LENGTH], num_2[MAX_INT_LENGTH];
    char string_1[MAX_INT_LENGTH], string_2[MAX_INT_LENGTH];
    int len_1, len_2;
    int i;
    int is_begin;

    scanf("%s%s", string_1, string_2);
    len_1 = strlen(string_1);
    len_2 = strlen(string_2);
    
    changeCharToInt(string_1, num_1, len_1);

//    for(i = MAX_INT_LENGTH - len_1; i < MAX_INT_LENGTH; i++)
//    {
//        printf("%d", num_1[i]);
//    }
//    printf("\n");
    is_begin = 0;
    for(i = 0; i < MAX_INT_LENGTH; i++)
    {
        if(num_1[i] == 0 && is_begin == 0)
        {
            continue;
        }
        is_begin = 1;

        printf("%d", num_1[i]);
    }
    printf("\n");
    return 0;
}

