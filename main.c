#include "header.h"
int size = sizeof(EVENT)-sizeof(EVENT*);
int num;
void printMenu(void)
{
        printf("--------MENU--------\n");
        printf(R "a/A: Add a new Event\n");
        printf("p/P: Print Calender for a month\n");
        printf("v/V: view all saved Events\n");
        printf("d/D: Delete an Event\n");
        printf("s/S: Save an Event\n");
        printf("l/L: sync Events from file\n");
        printf("f/F: Find all Events on a specific date\n");
        printf("q/Q: Quit the application\n" RESET);
}

int main()
{
        EVENT *head = NULL;
        head = sync_events(head);
        char choice;
        while(1){
                printMenu();
                fflush(stdout);
                printf("Enter your choice:");
                scanf(" %c", &choice);
                __fpurge(stdin);
                switch(choice)
                {
                        case 'a': head = add_event(head); break;
                        case 'v': display_events(head); break;
                        case 'q': exit(0);
                        case 'p': calender(); break;
                        case 's': save_events(head); break;
                        case 'l': sync_events(head); break;
                        case 'd': delete(head); break;
                        case 'f': find(head); break;
                        default: printf("Invalid input\n");
                }
        }
}
