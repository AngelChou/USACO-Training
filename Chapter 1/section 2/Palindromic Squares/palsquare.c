/*
ID: cat77121
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
            sprintf(tmp + n, "%c", 'A' + (x % base)%10);
        else
            sprintf(tmp + n, "%d", x);
    }
    else
        n--;

    for (i = n, j = 0; i >= 0; --i, j++)
        str[j] = tmp[i];
}

int main () {
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");

    int base, i, j, n;
    char num[20] = {0}, square[20] = {0};
    fscanf (fin, "%d\n", &base);

    for (i = 1; i < 300; ++i)
    {
        change_base(i, base, num);
        change_base(i * i, base, square);

        n = strlen(square);
        for (j = 0; j < n; ++j)
        {
            if (square[j] != square[n-1-j])
                break;
        }
        if (j == n)
        {
            fprintf (fout, "%s %s\n", num, square);
            //printf ("%s %s\n", num, square);
        }
    }
    fclose(fin);
    fclose(fout);
    exit (0);
}