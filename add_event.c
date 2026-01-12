#include "header.h"
extern int num;
void setEventID(char *p)
{
        time_t t = time(0);
        char time[30];
        strcpy(time, ctime(&t));
        int len = strlen(time);
        strcpy(p, "EV");
        strncpy(p+2, time+22, 2);  //setting year
        strncpy(p+4, time+4, 3);  //setting month

        if(num<10)
        sprintf(p+strlen(p), "00%d", num);
        else if(num>=10 && num<100)
                sprintf(p+strlen(p), "0%d", num);
        else
                sprintf(p+strlen(p), "%d", num);
}

EVENT *add_event(EVENT *ptr)
{
        num++; //increasing Events count
        EVENT *newnode = calloc(1, sizeof(EVENT));

        setEventID(newnode->Id); /*function call for keeping specific ID*/

        printf("Enter Event Name:-");
        __fpurge(stdin);
        fgets(newnode->Name, sizeof(newnode->Name), stdin);

        printf("Enter Event Date:-");
        __fpurge(stdin);
        fgets(newnode->Date, sizeof(newnode->Date), stdin);

        printf("Say someting about the Event:-");
        fgets(newnode->description, sizeof(newnode->description), stdin);

        if(ptr==NULL){
                return newnode;
        }
        else
        {
                EVENT *temp=ptr;
                while(temp->link!=NULL)
                {
                        temp = temp->link;
                }
                temp->link=newnode;
        }
        return ptr;
}

