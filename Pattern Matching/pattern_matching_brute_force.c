#include<stdio.h>
#include<string.h>

int main()
{
    char string[25];
    char pattern[25];
    int index;
    printf("Enter Main String: ");
    gets(string);
    printf("Enter Pattern: ");
    gets(pattern);
    index = pattern_match(string, pattern);
    if(index == -1)
    {
        printf("Pattern Not Matched\n");
    }
    else
    {
        printf("Pattern has been matched at index %d", index);
    }

    return 0;
}

int pattern_match(char string[], char pattern[])
{
    int m, n, i, j, flag;
    m = strlen(string);
    n = strlen(pattern);
    for(i=0; i<m-n+1; i++)
    {
        flag = 1;
        for(j=0; j<n; j++)
        {
            if(pattern[j] != string[j-i+1])
            {
                flag = 0;
            }
        }
        if(flag==1)
            return i;
    }
}
