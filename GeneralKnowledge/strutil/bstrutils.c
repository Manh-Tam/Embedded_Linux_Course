#include "strutils.h"

static void swap(char *c1, char *c2)
{
    char c = *c1;
    *c1 = *c2;
    *c2 = c;
}

void str_reverse(char *str, int n)
{
    if (str != NULL)
        for (int i = 0, j = n - 1; i < j; i++, j--)
            swap(&str[i], &str[j]);
}

char* str_trim(char str[], int n)
{
    if (str == NULL)
        return NULL;
    int leading_index = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == ' ')
            leading_index++;
        else
            break;
    
    int trailing_index = n - 1;
    for (int i = n - 1; i > 0; i--)
        if (str[i] == ' ')
            trailing_index--;
        else
            break;
    printf("leading: %d trailing: %d\n", leading_index, trailing_index);
    if (leading_index <= trailing_index)
    {
        str[trailing_index + 1] = '\0';
    }
    else
        str = NULL;
    return str + leading_index;
}

int str_to_int(char *str)
{
    char *p = str;
    int sign = 1;
    if (*p == '-')
    {
        sign = -1;
        p++;
    }
    int result = 0;
    while(*p != '\0')
    {
        if (*p >= '0' && *p <= '9')
        {
            if (isdigit(*p))
            {
                if (result == 0)
                    result =  (*p - 48);
                else
                    result = (result * 10) + (*p - 48);
            } 
            p++;
        }
        else 
            break;
    }
    return result * sign;
}

