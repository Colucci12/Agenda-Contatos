all: main.o agenda_contatos.o
	@gcc main.o agenda_contatos.o -o main

main.o: main.c
	@gcc main.c -c

agenda_contatos.o: agenda_contatos.c
	@gcc agenda_contatos.c -c

run:
	@./main