#include "header.h"
extern int size;

void save_events(EVENT *ptr)
{
        if(ptr==NULL)
        {
                printf("No Events are available\n");
                return;
        }
        FILE *file = fopen("event.txt", "w");
        EVENT *temp = ptr;

        /*while(temp){
                fputs(temp->Id, file);
                fputs(temp->Name, file);
                fputs(temp->Date, file);
                fputs(temp->description, file);
                temp = temp->link;
        }
        temp = ptr;*/
        while(temp)
        {
                fwrite(temp, size, 1, file);
                temp = temp->link;
        }
        printf("Events saved in a file sucessfully\n");
        fclose(file);
}

