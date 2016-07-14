/*
ID: cat77121
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");

    int max_boards, total_stalls, cows, block_stall = 0;
    int i, j, k, n, num_of_interval, breakpoint;
    int *occupied_stall = NULL;
    int ** interval = NULL;
    int tmp[3] = {0};

    fscanf(fin, "%d %d %d\n", &max_boards, &total_stalls, &cows);

    occupied_stall = (int*)malloc (sizeof(int) * cows);
    interval = (int**)malloc (sizeof(int*) * (cows - 1));
    for (i = 0; i < cows - 1; ++i)
        interval[i] = (int*)malloc (sizeof(int) * 3);

    // get occupied stall
    for (i = 0; i < cows; ++i)
    {
        fscanf(fin, "%d\n", &n);
        occupied_stall[i] = n;
        for (j = i - 1, k = i; j >= 0; --j)
        {
            if (occupied_stall[k] <= occupied_stall[j])
            {
                n = occupied_stall[k];
                occupied_stall[k] = occupied_stall[j];
                occupied_stall[j] = n;
                k--;
            }
        }
    }

    /*for (i = 0; i < cows; ++i)
        printf("%d\n", occupied_stall[i]);
    printf("=============\n");*/

    if (max_boards > 1)
    {
        // get empty interval
        for (i = 1, j = 0; i < cows; ++i)
        {
            if (occupied_stall[i] - occupied_stall[i - 1] > 1)
            {
                interval[j][0] = occupied_stall[i - 1];
                interval[j][1] = occupied_stall[i];
                interval[j][2] = occupied_stall[i] - occupied_stall[i - 1];
                j++;
            }
        }
        num_of_interval = j;
        /*for (i = 0; i < num_of_interval; ++i)
            printf("%d %d %d\n", interval[i][0], interval[i][1], interval[i][2]);
        printf("=============\n");*/

        // sort empty interval from large to small
        for (i = 0; i < num_of_interval; ++i)
        {
            for (j = i - 1, k = i; j >= 0; --j)
            {
                if (interval[k][2] >= interval[j][2])
                {
                    memcpy(tmp, interval[k], sizeof(tmp));
                    memcpy(interval[k], interval[j], sizeof(tmp));
                    memcpy(interval[j], tmp, sizeof(tmp));
                    k--;
                }
            }
        }
        /*for (i = 0; i < num_of_interval; ++i)
            printf("%d %d %d\n", interval[i][0], interval[i][1], interval[i][2]);
        printf("=============\n");*/

        breakpoint = (max_boards > num_of_interval) ? num_of_interval : max_boards - 1;
        // sort breakpoint according to max_boards
        for (i = 0; i < breakpoint; ++i)
        {
            for (j = i - 1, k = i; j >= 0; --j)
            {
                if (interval[k][1] >= interval[j][1])
                {
                    memcpy(tmp, interval[k], sizeof(tmp));
                    memcpy(interval[k], interval[j], sizeof(tmp));
                    memcpy(interval[j], tmp, sizeof(tmp));
                    k--;
                }
            }
        }
        /*for (i = 0; i < breakpoint; ++i)
            printf("%d %d %d\n", interval[i][0], interval[i][1], interval[i][2]);
        printf("=============\n");*/

        // count block_stall according to sorted breakpoint
        block_stall += occupied_stall[cows - 1] - (interval[0][1] - 1);
        for (i = 1; i < breakpoint; ++i)
            block_stall += interval[i - 1][0] - (interval[i][1] - 1);
        block_stall += interval[i - 1][0] - (occupied_stall[0] - 1);
    }
    else
        block_stall += occupied_stall[cows - 1] - (occupied_stall[0] - 1);

    //printf("%d\n", block_stall);
    fprintf(fout, "%d\n", block_stall);
    for (i = 0; i < num_of_interval; ++i)
        free(interval[i]);
    free(interval);
    fclose(fin);
    fclose(fout);
    exit (0);
}