a.out :  main.o add_event.o display_events.o save.o sync.o delete.o calender.o find.o
	 gcc main.o add_event.o display_events.o save.o sync.o delete.o calender.o find.o
main.o : main.c
	gcc -c main.c

add_event.o : add_event.c
	gcc -c add_event.c

display_events.o : display_events.c
	gcc -c display_events.c

save.o : save.c
	gcc -c save.c

sync.o : sync.c
	gcc -c sync.c

delete.o : delete.c
	gcc -c delete.c
calender.o : calender.c
	gcc -c calender.c
find.o : find.c
	gcc -c find.c

