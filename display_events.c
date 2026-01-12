#include "header.h"
void display_events(EVENT *ptr)
{
        if(ptr==NULL)
        {
                printf("No Events available to print\n");
                return;
        }
        EVENT *temp=ptr;

        while(temp){
                printf(Y "EventID:- %s\n"RESET, temp->Id);
                printf(Blue "%s", temp->Name);
                printf("%s", temp->Date);
                printf("%s" RESET, temp->description);
                temp = temp->link;
        }
        printf("\n");
}

