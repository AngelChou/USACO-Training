/*
ID: cat77121
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");

    int milk_wanted, famers, i, j, k, tmp, cost = 0, count = 0;
    int *price = NULL;
    int *milks_can_sell = NULL;

    fscanf(fin, "%d %d\n", &milk_wanted, &famers);
    //printf("%d %d\n", milk_wanted, famers);

    price = (int*)malloc (sizeof(int) * famers);
    milks_can_sell = (int*)malloc (sizeof(int) * famers);

    for (i = 0; i < famers; ++i)
    {
        fscanf(fin, "%d %d\n", &price[i], &milks_can_sell[i]);

        for (j = i - 1, k = i; j >= 0; --j)
        {
            if(price[k] <= price[j])
            {
                tmp = price[k];
                price[k] = price[j];
                price[j] = tmp;

                tmp = milks_can_sell[k];
                milks_can_sell[k] = milks_can_sell[j];
                milks_can_sell[j] = tmp;

                k--;
            }
        }
    }
    for (i = 0; i < famers; ++i)
    {
        //printf("%d %d\n", price[i], milks_can_sell[i]);
        if (count + milks_can_sell[i] < milk_wanted)
        {
            cost += price[i] * milks_can_sell[i];
            count += milks_can_sell[i];
        }
        else
        {
            cost += price[i] * (milk_wanted - count);
            count += milk_wanted - count;
        }
    }

    //printf("%d %d\n", cost, count);
    fprintf(fout, "%d\n", cost);



    free(price);
    free(milks_can_sell);
    fclose(fin);
    fclose(fout);
    exit (0);
}