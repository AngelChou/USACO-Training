/*
ID: cat77121
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **before = NULL;
char **after = NULL;
char **transform = NULL;
char **reflection = NULL;
char **tmp = NULL;
int n, i, j, k;

int check(int x, char** a)
{
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (a[i][j] != after[i][j])
                return -1; // It's not #1
        }
    }
    return x;
}

int main () {
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");

    int result = 0;

    fscanf (fin, "%d\n", &n);
    //printf("%d\n", n);

    // create 2d-array dynamically
    before = (char**)malloc(sizeof(char*) * n);
    after = (char**)malloc(sizeof(char*) * n);
    transform = (char**)malloc(sizeof(char*) * n);
    reflection = (char**)malloc(sizeof(char*) * n);
    tmp = (char**)malloc(sizeof(char*) * n);
    for (i = 0; i < n; ++i)
    {
        before[i] = (char*)malloc(sizeof(char) * n);
        transform[i] = (char*)malloc(sizeof(char) * n);
        reflection[i] = (char*)malloc(sizeof(char) * n);
        after[i] = (char*)malloc(sizeof(char) * n);
        tmp[i] = (char*)malloc(sizeof(char) * n);
    }

    // get before and after
    for (k = 0; k < 2; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (k == 0) // get "before"
                {
                    fscanf (fin, "%c", &before[i][j]);
                    //printf("%c", before[i][j]);
                    transform[j][n-1-i] = before[i][j]; // set transform to 90 degree
                    reflection[i][n-1-j] = before[i][j]; // set reflection
                }
                else // get "after"
                {
                    fscanf (fin, "%c", &after[i][j]);
                    //printf("%c", after[i][j]);
                    //printf("%c", transform[i][j]);
                    //if (result == 6 && before[i][j] != after[i][j]) // check content of same position for #7
                    //    result = -1;   // It's not #6
                }
            }
            fscanf (fin, "\n");
            //printf("\n");
        }
    }


    result = check(1, transform); // 90 degree
    if (result < 0)
    {
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                tmp[j][n-1-i] = transform[i][j];
        result = check(2, tmp); // 180 degree
        if (result < 0)
        {
            for (i = 0; i < n; ++i)
                for (j = 0; j < n; ++j)
                    transform[j][n-1-i] = tmp[i][j];
            result = check(3, transform); // 270 degree
            if (result < 0)
            {
                result = check(4, reflection);  //reflection
                if (result < 0)
                {
                    for (i = 0; i < n; ++i)
                        for (j = 0; j < n; ++j)
                            transform[j][n-1-i] = reflection[i][j];
                    result = check(5, transform); // reflection + 270
                    if (result < 0)
                    {
                        for (i = 0; i < n; ++i)
                            for (j = 0; j < n; ++j)
                                tmp[j][n-1-i] = transform[i][j];
                        result = check(5, tmp); // reflection + 180
                        if (result < 0)
                        {
                            for (i = 0; i < n; ++i)
                                for (j = 0; j < n; ++j)
                                    transform[j][n-1-i] = tmp[i][j];
                            result = check(5, transform); // reflection + 90
                            if (result < 0)
                            {
                                result = check(6, before);
                                if (result < 0)
                                {
                                    result = 7;
                                }
                            }
                        }
                    }
                }
            }
        }
    }



    /*result = check(6, before);  // No change
    if (result < 0)
    {
        result = check(4, reflection); // reflection
        if (result < 0)
        {
            result = check(1, transform); // 90 degree
            if (result < 0)
            {
                for (i = 0; i < n; ++i)
                    for (j = 0; j < n; ++j)
                    {
                        reflection[n-1-i][j] = transform[i][j];
                        tmp[j][n-1-i] = transform[i][j];
                    }
                result = check(5, reflection);  // reflection + 90 degree
                if (result < 0)
                {
                    result = check(2, tmp); // 180 degree
                    if (result < 0)
                    {
                        for (i = 0; i < n; ++i)
                            for (j = 0; j < n; ++j)
                            {
                                reflection[n-1-i][j] = tmp[i][j];
                                transform[j][n-1-i] = tmp[i][j];
                            }
                        result = check(5, reflection); // reflection + 180 degree
                        if (result < 0)
                        {
                            result = check(3, transform); // 270 degree
                            if (result < 0)
                            {
                                for (i = 0; i < n; ++i)
                                    for (j = 0; j < n; ++j)
                                        reflection[n-1-i][j] = transform[i][j];
                                result = check(5, reflection);  // reflection + 270 degree
                                if (result < 0)
                                {
                                    result = 7;
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/
    fprintf (fout, "%d\n", result);

    for (i = 0; i < n; ++i)
    {
        free(before[i]);
        free(after[i]);
        free(transform[i]);
        free(reflection[i]);
        free(tmp[i]);
    }
    free(before);
    free(after);
    free(transform);
    free(reflection);
    free(tmp);
    exit (0);
}