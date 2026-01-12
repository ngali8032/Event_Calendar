#include "header.h"

void *delete(EVENT *ptr)
{
        int count=0;
        if(ptr==NULL)
        {
                return NULL;
        }
        EVENT *temp = ptr;
        while(temp)
        {
                printf(G "%d:- %s\n"RESET, count+1, temp->Id);
                count++;
                temp = temp->link;
        }
        int choice, flag=0;
        printf("Enter the choice the delete:");
        scanf("%d", &choice);
        count=0;
        temp = ptr;
        while(temp)
        {
                if(choice==count+1)
                {
                        flag=1;
                        strcpy(temp->Name, " ");
                        strcpy(temp->Date, " ");
                        strcpy(temp->description, "\n");
                        break;
                }
                count++;
                temp = temp->link;
        }
        if(!flag)
                printf("Invalid choice\n");
}

