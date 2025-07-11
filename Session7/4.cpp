#include <stdio.h>
#include <string.h>

void sortString(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

int main()
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin))
    {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    if (strlen(str) == 0)
    {
        printf("Chuoi khong hop le \n");
        return 0;
    }

    printf("str = \"%s\"\n", str);
    sortString(str);
    printf("str = \"%s\"\n", str);

    return 0;
}