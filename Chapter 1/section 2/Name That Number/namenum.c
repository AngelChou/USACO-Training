/*
ID: cat77121
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[8][3] = {
    {'A', 'B', 'C'},    // 2
    {'D', 'E', 'F'},    // 3
    {'G', 'H', 'I'},    // 4
    {'J', 'K', 'L'},    // 5
    {'M', 'N', 'O'},    // 6
    {'P', 'R', 'S'},    // 7
    {'T', 'U', 'V'},    // 8
    {'W', 'X', 'Y'}     // 9
};

int main () {
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *fout = fopen ("namenum.out", "w");
    FILE *fin2  = fopen ("dict.txt", "r");

    char input[13] = {0};
    char text[37] = {0};
    char valid[13] = {0};
    int n, i, j;
    int flag = 0;

    fscanf (fin, "%s\n", input);
    n = strlen(input);
    //printf("%d, %s, %s\n", n, input, text);

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            switch(input[i])
            {
                case '2':
                    text[i*3+j] = table[0][j];
                    break;
                case '3':
                    text[i*3+j] = table[1][j];
                    break;
                case '4':
                    text[i*3+j] = table[2][j];
                    break;
                case '5':
                    text[i*3+j] = table[3][j];
                    break;
                case '6':
                    text[i*3+j] = table[4][j];
                    break;
                case '7':
                    text[i*3+j] = table[5][j];
                    break;
                case '8':
                    text[i*3+j] = table[6][j];
                    break;
                case '9':
                    text[i*3+j] = table[7][j];
                    break;
                default:
                    break;
            }
            //printf("%s\n", text);
        }
    }
    //printf("%s\n", text);

    while(!feof(fin2))
    {
        fscanf (fin2, "%s\n", valid);
        if (strlen(valid) == n)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (valid[i] == text[i*3+j])
                        break;
                }
                if (j == 3)
                    break;
            }
            if (i == n)
            {
                //printf("%s\n", valid);
                fprintf (fout, "%s\n", valid);
                flag = 1;
            }
        }
    }
    if (flag != 1)
    {
        fprintf(fout, "NONE\n");
    }

    fclose(fin);
    fclose(fout);
    fclose(fin2);
    exit (0);
}