/*
ID: cat77121
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");

    int n, day, days, month, year, week = 1, i;
    int result[7] = {0};

    fscanf (fin, "%d", &n);

    for (year = 1900; year < (1900 + n); ++year)
    {
        for(month = 1; month < 13; ++month)
        {
            if (month == 2) {
                if(year % 100 == 0) // Century year
                    days = (year % 400 == 0) ? 29 : 28;
                else
                    days = (year % 4 == 0) ? 29 : 28;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) days = 30;
            else days = 31;

            /*fprintf (fout, "===================\n [%d - %d] \n", year, month);
            if(week != 1){
                for(i = 1; i < week; ++i) fprintf(fout, "   ");
            }*/
            for (day = 1; day <= days; ++day, ++week)
            {
                if (week == 8){
                    //fprintf (fout, "\n");
                    week = 1;
                }
                //fprintf (fout, " %2d", day);
                if (day == 13) result[week-1] += 1;
            }
            //fprintf (fout, "\n\n %2d %2d %2d %2d %2d %2d %2d\n", result[0], result[1], result[2], result[3], result[4], result[5], result[6]);
        }
    }

    fprintf (fout, "%d %d %d %d %d %d %d\n", result[5], result[6], result[0], result[1], result[2], result[3], result[4]);
    exit (0);
}