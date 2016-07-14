/*
ID: cat77121
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <stdlib.h>

int *set = NULL;
int n;
int check(int x)
{
	int i, mod;
	while (x != 0)
	{
		mod = x % 10;
		//printf("x: %d, mod: %d\n", x, mod);
		for (i = 0; i < n; ++i)
			if (mod == set[i])
				break;
		if (i == n)
			return -1;
		x /= 10;
	}
	return 1;
}

int main () {
    FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");

    int solution = 0;
    int i, j, k, tmp;
    int a, b, c, d, e, p, p1, p2;

    fscanf(fin, "%d\n", &n);
    set = (int*)malloc (sizeof(int) * n);

    for (i = 0; i < n; ++i)
    {
    	fscanf(fin, "%d ", &set[i]);
    	for (j = i - 1, k = i; j >= 0; j--)
    	{
    		if (set[k] <= set[j])
    		{
    			tmp = set[k];
    			set[k] = set[j];
    			set[j] = tmp;
    			k--;
    		}
    	}
    }

    for (a = 0; a < n; ++a)
    {
    	for (b = 0; b < n; ++b)
    	{
    		for (c = 0; c < n; ++c)
	    	{
	    		for (d = 0; d < n; ++d)
		    	{
		    		for (e = 0; e < n; ++e)
			    	{
			    		p1 = set[e] * (set[a] * 100 + set[b] * 10 + set[c]);
			    		p2 = set[d] * (set[a] * 100 + set[b] * 10 + set[c]);
			    		p = p1 + p2 * 10;
			    		if (p1 < 1000 && p2 < 1000 && check(p1) > 0 && check(p2) > 0 && check(p) > 0)
			    		{
			    			//printf("%d + %d = %d\n", p1, p2, p);
			    			solution++;
			    		}
			    	}
		    	}
	    	}
    	}
    }

    fprintf(fout, "%d\n", solution);
    fclose(fin);
    fclose(fout);
    exit (0);
}