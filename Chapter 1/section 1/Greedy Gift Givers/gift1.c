/*
ID: cat77121
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");

    int np, i, money, num, j, give, k, l;
    char name[14] = {0};
    char **member = NULL;
    int *init_money = NULL;
    int *final_money = NULL;
    int *group = NULL;

    // Get number of members
    fscanf (fin, "%d", &np);

    member = (char**)malloc (sizeof (char*) * np);
	init_money = (int*)malloc (sizeof(int) * np);
	final_money = (int*)malloc (sizeof(int) * np);
	group = (int*)malloc (sizeof(int) * np);

    // Get member name
	for (i = 0; i < np; ++i)
    {
    	member[i] = (char*)malloc(sizeof(char)*14);
    	fscanf (fin, "%s", name);
    	memcpy(member[i], name, sizeof(name));
    	final_money[i] = 0;
    }

    // Get give rule
    for (i = 0; i < np; ++i)
    {
    	fscanf (fin, "%s %d %d", name, &money, &num);
    	for (l = 0; l < np; ++l)
    	{
    		if (strcmp(member[l], name) == 0){
		    	init_money[l] = money;
		    	group[l] = num;
                if(num != 0){
                    give = money / num;
                    final_money[l] += money % num;
                    for(j = 0; j < num; ++j){
                        fscanf (fin, "%s", name);
                        for (k = 0; k < np; ++k)
                        {
                            if (strcmp(member[k], name) == 0){
                                final_money[k] += give;
                                break;
                            }
                        }
                    }
                }
                break;
			}
    	}
       /* for (l = 0; l < np; ++l)
            printf("%s: %4d\t%4d\t%4d\t%5d\n", member[l], init_money[l], group[l], final_money[l], final_money[l] - init_money[l]);
        printf("=====================================\n");*/
    }
    for (i = 0; i < np; ++i)
    {
    	//printf("%s: %d, %d, %d, %d\n", member[i], init_money[i], group[i], final_money[i], final_money[i] - init_money[i]);
    	fprintf (fout, "%s %d\n", member[i], final_money[i]-init_money[i]);
    	free(member[i]);
    }
    free(member);
    free(init_money);
    free(final_money);
    exit (0);
}