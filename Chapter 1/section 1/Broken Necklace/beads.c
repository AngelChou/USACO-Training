/*
ID: cat77121
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main () {
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");

    int n, sum1 = 0, sum2 = 0, i, w_combo = 0, max = 0;
    char beads[700] = {0};
    bool w_show = false;

    fscanf (fin, "%d", &n);
    fscanf (fin, "%s", beads);
    memcpy (beads + n, beads, n);

    for (i = 0; i < (n * 2); ++i)
    {
        if (beads[i] == 'r' || beads[i] == 'b')
        {
            // get first 'r' or 'b' in the necklace, add 1 to counter and set index to the next bead.
            sum2 = 1;
            i++;
            break;
        }
        // if not found any 'r' and 'b', set counter to length of necklace.
        sum2 = n;
    }

    for (; i < (n * 2); ++i)
    {
        if (beads[i] == 'w')
        {
            // get white bead, set flag
            w_show = true;

            //
            w_combo = 1;

            // keep counting when encounting white bead
            sum2++;

            // piant white bead (same color as previous one)
            beads[i] = beads[i - 1];
        }
        else if (beads[i] == beads[i - 1])
        {
            // encounter same color, keep counting
            sum2++;
        }
        else
        {
            // encounter different, sum the counter
            if ((sum1 + sum2) > max)
                max = sum1 + sum2;
            // reset counter to keep looping for next round
            sum1 = sum2;
            sum2 = 1;
            if (w_show)
            {
                // count white bead in sum2
                sum2 += w_combo;
                sum1 -= w_combo;
            }
            w_show = false;
            w_combo = 0;
        }
    }

    if ((sum1 + sum2) > max)
        max = sum1 + sum2;
    if (max > n)
        max = n;

    fprintf (fout, "%d\n", max);
    exit (0);
}