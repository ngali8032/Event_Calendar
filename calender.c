#include "header.h"
char *week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
char *year[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int YEAR;
int startDate;
int monthEndCnt;
int startPos;

int MonthYear(time_t t)
{
        char cYear[6];
        char month[5];
        strncpy(month, ctime(&t)+4, 3); //copying month
        strcpy(cYear, ctime(&t)+20);  //copying year
        cYear[4]='\0';
        YEAR = atoi(cYear);
        month[3]='\0';

        int choice;
        for(int i=0; i<12; i++)
        {
                if(strcmp(month, year[i])==0){
                        choice=i+1; break;
                }
        }
        return choice;
}

int checkMonth(int choice){
        switch(choice)
        {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                        return 31;
                case 4:case 6:case 9:case 11:
                        return 30;
                case 2:
                        if((YEAR%4==0 && YEAR%100!=0)|| (YEAR%400==0))
                                return 29;
                        else
                                return 28;
        }
}

void calender(void)
{
        time_t t = time(0);

        char day[5];  //for stores which day
        char dayStart[5]; //for strores date  in character
        strncpy(dayStart, ctime(&t)+8, 3); //converting date
        strncpy(day, ctime(&t), 4); //converting day
        day[3] = '\0';
        dayStart[2] = '\0';
        startDate = atoi(dayStart); //converting ASCII to integer

        for(int i=0; i<7; i++)
        {
                if(strcmp(day, week[i])==0)
                        startPos=i;
        }
        int choice = MonthYear(t); //function call for checking month and year
while(1){
        monthEndCnt = checkMonth(choice); //function call for Month
        srand(time(0));
        int r = rand()%8;
        printf("\033[1;3%dm", r);
                /*Here on wards prints year,month, rows of week*/

        printf(" <-----%s Month,%d------>\n", year[choice-1], YEAR      );
        printf(" ");
        for(int i=0; i<7; i++)
                printf("%s ", week[i]);
        printf("\n");

        int start=0;
        for(int i=0; i<7; i++)
        {
                if(startPos<=i){
                        if(startDate>9)
                                printf("  %d", startDate+start);
                        else
                                printf("   %d", startDate+start);
                        start++;
                }
                else
                        printf("    ");
        }

        printf("\n");
        start = startDate+start;
        int i=0;
        for(; start<=monthEndCnt; start++)
        {
                if(start<10)
                        printf("   %d", start);
                else
                        printf("  %d", start);
                i++;
                if(i==7)
                {
                        printf("\n"); i=0;
                }
        }

        if(choice==12)
                YEAR += 1;
        printf(RESET);
        int option;
        printf("\n1:Next month, 2: exit\n");
        printf("Enter the choice:");
        scanf("%d", &option);
        __fpurge(stdin);
        switch(option)
        {
                case 1: startPos=i; startDate=1;
                        if(choice==12) choice=1;
                        else choice++;
                        break;
                case 2: return;
                default: printf("Invalid input\n"); return;
        }
}
}

