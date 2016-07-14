/*
ID: cat77121
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_base(int x, int base, char str[])
{
    char tmp[20] = {0};
    int i, j, n = 0, t;
    char c;

    do{
        if (base > 10 && x % base >= 10)
            sprintf(tmp + n, "%c", 'A' + (x % base) % 10);
        else
            sprintf(tmp + n, "%d", x % base);
        x = x / base;
        n++;
    }while(x >= base);

    if (x != 0)
    {
        if (base > 10 && x % base >= 10)
            sprintf(tmp + n, "%c", 'A' + (x % base) % 10);
        else
            sprintf(tmp + n, "%d", x);
    }
    else
        n--;

    for (i = n, j = 0; i >= 0; --i, j++)
        str[j] = tmp[i];
}

int main () {
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");

    int n, s, base = 2, i = 0, j, len, k = 0, c = 0;
    char num[20] = {0};
    fscanf (fin, "%d %d\n", &n, &s);
    for (i = s + 1; i < 100000; ++i)
    {
        for (base = 2, c = 0; base <= 10; ++base)
        {
            if(c >= 2)
            {
                fprintf (fout, "%d\n", i);
                k++;
                break;
            }
            change_base(i, base, num);
            len = strlen(num);
            for (j = 0; j < len; ++j)
            {
                if (num[j] != num[len-1-j])
                    break;
            }
            if (j == len) // it's palindromic
            {
                c++;
                //printf("%d(%d): %s %d %d\n", i, base, num, k, c);
            }
            memset(num, 0x00, sizeof(num));
        }
        if (base == 11 && c >= 2)
        {
            fprintf (fout, "%d\n", i);
            k++;
        }
        if(k == n)
            break;
    }

    fclose(fin);
    fclose(fout);
    exit (0);
}