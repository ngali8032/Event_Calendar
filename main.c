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
                        case 'a': case 'A': head = add_event(head); break;
                        case 'v': case 'V': display_events(head); break;
                        case 'q': case 'Q': exit(0);
                        case 'p': case 'P': calender(); break;
                        case 's': case 'S': save_events(head); break;
                        case 'd': case 'D': delete(head); break;
                        case 'f': case 'F': find(head); break;
                        default: printf("Invalid input\n");
                }
        }
}
