#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define B "\033[1;30m"
#define R "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define Blue "\033[1;34m"
#define RESET "\033[0m"

typedef struct Event
{
        char Id[12];
        char Name[100];
        char Date[15];
        char description[300];
        struct Event *link;
}EVENT;

EVENT *add_event(EVENT *);
void display_events(EVENT *);
void save_events(EVENT *);
EVENT *sync_events(EVENT *);
void *delete(EVENT *);
void calender(void);
void find(EVENT *);

