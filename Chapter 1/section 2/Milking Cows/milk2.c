/*
ID: cat77121
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");

    int n, i, j, k, tmp;
    int head = 0, tail = 0;
    int milking = 0, idle = 0;

    int *begin = NULL;
    int *end = NULL;

    fscanf (fin, "%d", &n);

    begin = (int*) malloc(sizeof(int)*n);
    end = (int*) malloc(sizeof(int)*n);

    for (i = 0; i < n; ++i){
        fscanf (fin, "%d %d", &begin[i], &end[i]);
        for (j = i - 1, k = i; j >= 0; --j)
        {
            if (begin[k] <= begin[j])
            {
                tmp = begin[k];
                begin[k] = begin[j];
                begin[j] = tmp;

                tmp = end[k];
                end[k] = end[j];
                end[j] = tmp;
                k--;
            }
        }
    }

    head = begin[0];
    tail = end[0];
    milking = tail - head;

    for (i = 0; i < n; ++i)
    {

        // case 1:
        //      head --- begin[i] --- tail --- end[i]
        // case 2:
        //      head --- tail
        //              begin[i] --- end[i]
        // action: set tail to end[i]
        if ((begin[i] < tail && end[i] > tail) || begin[i] == tail)
        {
            tail = end[i];
            //printf("[%d] tail = %d\n", i, tail);
        }
        // case 3:
        //      head --- tail --- begin[i] --- end[i]
        // action: store max milking and idle time
        else if (begin[i] > tail)
        {
            if (milking < tail - head)
                milking = tail - head;
            if(idle < begin[i] - tail)
                idle = begin[i] - tail;
            head = begin[i];
            tail = end[i];
        }

    }

    fprintf (fout, "%d %d\n", milking, idle);
    free(begin);
    free(end);
    exit (0);
}