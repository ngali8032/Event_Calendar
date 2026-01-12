#include "header.h"

void monthBased(EVENT *ptr)
{
        EVENT *temp = ptr;
        int flag=0;
        char month[5], convMonth[5];
        printf("Enter the month(MM):");
        scanf("%s", month);
        while(temp)
        {
                strncpy(convMonth, (temp->Date)+3, 2);
                convMonth[2]='\0';
                if(strcmp(month, convMonth)==0)
                {
                        flag=1;
                        printf(G "\n%s\n%s%s%s"RESET, temp->Id, temp->Name, temp->Date, temp->description);
                }
                temp = temp->link;
        }
        if(!flag)
        {
                printf("No matched with this %s month\n", month);
        }
}

void dayBased(EVENT *ptr)
{
        EVENT *temp = ptr;
        int flag=0;
        char monthDate[7], convMonthDate[7];
        printf("Enter date/month(dd/mm):");
        scanf("%s", monthDate);
        while(temp)
        {
                strncpy(convMonthDate, (temp->Date), 5);
                convMonthDate[6]='\0';
                if(strcmp(monthDate, convMonthDate)==0)
                {
                        flag=1;
                        printf(G "%s\n%s%s%s"RESET, temp->Id, temp->Name, temp->Date, temp->description);
                }
                temp = temp->link;
        }
        if(!flag)
        {
                printf("No matched with this %s month\n", monthDate);
        }
}

void find(EVENT* ptr)
{
        if(ptr==NULL)
        {
                printf("No Events Available to find\n");
                return;
        }
        int choice;
        printf("1: based on month\n");
        printf("2: based on day\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch(choice)
        {
                case 1: monthBased(ptr); break;
                case 2: dayBased(ptr); break;
                default: printf("Invalid choice\n");
        }
}

