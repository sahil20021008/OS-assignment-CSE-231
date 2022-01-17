all: q1fork q1thread q2

q1fork: question_1_fork.c
	gcc -E question_1_fork.c -o question_1_fork.i
	gcc -S question_1_fork.i -o question_1_fork.s
	gcc -c question_1_fork.s -o question_1_fork.o
	gcc question_1_fork.o -o q1fork
q1thread: question_1_thread.c
	gcc -pthread -E question_1_thread.c -o question_1_thread.i
	gcc -pthread -S question_1_thread.i -o question_1_thread.s
	gcc -pthread -c question_1_thread.s -o question_1_thread.o
	gcc -pthread question_1_thread.o -o q1thread
q2: a.c b.asm c.c
	nasm -f elf64 b.asm -o b.o
	gcc a.c c.c b.o -o run -no-pie