#include "strutils.h"

int main()
{
    char str1[] = "Hello World";
    printf("str1: %s\n", str1);
    str_reverse(str1, strlen(str1));
    printf("reversed str1: %s\n", str1);

    char str2[] = "  this is string 2  ";
    char* temp = str_trim(str2, strlen(str2));
    printf("str2: %s\n", temp);

    char str3[] = "-1234";
    printf("%d", str_to_int(str3));
    return 0;
}