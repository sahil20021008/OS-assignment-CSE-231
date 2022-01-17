OS assignment 1

Question 1:

question_1_fork:

input format:
    no input is required for this question
output format:
    the average of each section is given as output for each assignment
explanation:
    first we call the fork function and assign it to a pid_t child. after that, we open the file with open(), and then read the file into a char array using read(). then we use strtok() to separate the strings in parts. then we use a while loop to keep going through the array, convert the strings to integers using strtol(), and if the student is in the correct section, we add their score to an array of the score we are maintaining. we do this until we reach end of char array. we also keep the number of students of that section. at the end of the loop we print the averages of all the assignments. while we are doing this, we have the parent process wait for child process to end using waitpid(). at end of child process we use exit() on the child process.we repeat the same process for the parent process, but this time we find the averages for section B.
assumptions:
    we are assuming that the same CSV file is being used that was uploaded in google classroom.
steps to compile and execute the program:
    the makefile has been made. in the makefile we have used 
    gcc -E question_1_fork.c -o question_1_fork.i
	gcc -S question_1_fork.i -o question_1_fork.s
	gcc -c question_1_fork.s -o question_1_fork.o
	gcc question_1_fork.o -o q1fork
    with these instructions, we will create .i, .s, .o and executable file for question_1_fork.c . after this, the user has to run ./q1fork to run the executable that is finally created.
arguments passed:
    open():used to open the file we want. we pass filename of the csv file, and we pass O_RDONLY to signify that we only want to read the file. we check if the filehandle is negative to make sure that file was opened properly.
    read():used to read the data in the file and store it into char array. we pass filehandle of the opened file, the char array we want to read into, and the max size we want to read.
    exit():we pass 0 as argument to signify that we exited child process with exit status 0.
    fork():fork creates a child process. it has no arguments but it returns an integer denoting process id of child process to parent process, and while it's in child process id is denoted by 0. in case child process wasn't created properly, it returns -ve number, which we check for to make sure fork() worked.
    waitpid():used to make the parent process wait for the child process to complete. as arguments, we pass the process id of the child process, the address of an integer in which the result of waitpid is written, and we pass an integer to denote what option we picked.

question_1_thread:

input format:
    no input is required for this question
output format:
    the average of each section is given as output for each assignment
explanation:
    first we call the pthread_create() function and assign it to a pthread_t child. after that, we open the file with open(), and then read the file into a char array using read(). then we use strtok() to separate the strings in parts. then we use a while loop to keep going through the array, convert the strings to integers using strtol(), and if the student is in the correct section, we add their score to an array of the score we are maintaining. we do this until we reach the end of char array. we also keep the number of students of that section. at the end of the loop we print the averages of all the assignments. while we are doing this, we have the parent process wait for child process to end using pthread_join(). we repeat the same process for the parent process, but this time we find the averages for section B.
steps to compile and execute the program:
    the makefile has been made. in the makefile we have used
    gcc -pthread -E question_1_thread.c -o question_1_thread.i
	gcc -pthread -S question_1_thread.i -o question_1_thread.s
	gcc -pthread -c question_1_thread.s -o question_1_thread.o
	gcc -pthread question_1_thread.o -o q1thread
    with these instructions, we will create .i, .s, .o and executable file for question_1_thread.c . after this, the user has to run ./q1thread to run the executable that is finally created.
assumptions:
    we are assuming that the same CSV file is being used that was uploaded in google classroom.
arguments passed:
    open():used to open the file we want. we pass filename of the csv file, and we pass O_RDONLY to signify that we only want to read the file. we check if the filehandle is negative to make sure that file was opened properly.
    read():used to read the data in the file and store it into char array. we pass filehandle of the opened file, the char array we want to read into, and the max size we want to read.
    pthread_create():used to create a new thread in which we find the average marks for the children of section a. we pass address of uninitialized thread, NULL, the function we want to run in child thread, and NULL.
    pthread_join():used to make parent thread wait for child thread.we pass child thread and NULL as the arguments.
Question 2:
input format:
    in the a() function, the user will have to input a 64 bit number.
output format:
    the program will print the function it is in, and in b function it will also print ascii string representation of the 64 bit number that was given to it as input
explanation:
    in the program, first the main function is called in a.c after that the code prints that it is in main function, and then it calls the a() function. after that the a function calls b() function. b is an assembly file. in the b function we print that the program is in b function. then we print the ascii string the user entered. then the code modifies the stack and puts the address for c function there. because of this, the b function returns to the c function instead of the a function. in the c function, we print that the program is in the c function, and then we call exit in the c function.
steps to compile and execute the program:
    the makefile has been made. in the makefile, first we use nasm -f elf64 b.asm -o b.o to create a file b.o from the assembly file. after that we use gcc a.c c.c b.o -o run -no-pie to link the three files a.c, c.c, and b.o together and create a file run that will execute them. the command to execute the file is ./run
assumption:
    we are assuming that user will enter 64 bit number in a function when it asks for input