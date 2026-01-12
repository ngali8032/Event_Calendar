#include "header.h"
extern int size;
extern int num;

EVENT *sync_events(EVENT *ptr)
{
        EVENT *temp = ptr;

        EVENT var;
        FILE *file = fopen("event.txt", "r");

        if(file==NULL)
        {
                printf("Failed to open the file\n");
                return ptr;
        }

        EVENT *newnode = NULL;
        while(fread(&var, size, 1, file)==1)
        {
                num++;
                newnode = calloc(sizeof(EVENT), 1);
                strcpy(newnode->Id, var.Id);
               strcpy(newnode->Name, var.Name);
               strcpy(newnode->Date, var.Date);
               strcpy(newnode->description, var.description);
               if(temp==NULL)
               {
                       ptr=newnode;
                       temp=ptr;
               }
               else{
                temp->link = newnode;
                temp = temp->link;
               }
        }
        fclose(file);
        printf("Data Synced successfully\n");
        return ptr;
}

