/*
ID: cat77121
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
int main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char a[8] = {0}, b[8] = {0};
    int i, comet = 1, group = 1;

    fscanf (fin, "%s %s", a, b);	/* the two input string */

    for (i = 0; i < 6; ++i)
    {
    	if(a[i])
    		comet *= (a[i] - 64);
    	if(b[i])
    		group *= (b[i] - 64);
    	printf("%d, %d\n", comet, group);
    }

    comet %= 47;
    group %= 47;
    printf("%d, %d\n", comet, group);

    if(comet == group)
	    fprintf (fout, "GO\n");
	else
		fprintf (fout, "STAY\n");
    exit (0);
}