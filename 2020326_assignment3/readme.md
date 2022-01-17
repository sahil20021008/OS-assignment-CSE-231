OS assignment 3:

Question 1:
Input Format:
    the user has the enter the command in the terminal ./q1
Output Format:
    the sample program code will output each process's start and end time, and will print which process it is in multiple times.
Explanation:
    we made a syscall in sys.c, increase_vruntime which had one argument, the duration for which the time must be increased. after that we added to syscall to number 449 in the syscall table. then we compiled the kernel. after that we made the sample program and then we ran it. finally we used git diff >> diff.txt and git diff >> diff.patch to create diff files to store the difference between kernels in.
    in the sample program, we have made 4 c files. q1.c,p1.c,p2.c,p3.c . we have to run q1 which will run fork and then call execv to run p1,p2,p3. in this way, all 4 programs start running. then, in the q1 process, we call the syscall, to increase the vruntime of q1. after that in for loop, we print the process we are currently in. finally at end of each process's loop, we print the end time of the process. 
    We have used time and localtime functions to get the time in local units. we have also used sleep function, to make the program wait before printing the process name.
Assumptions:
    the vm version is 5.14.4


Question 2:

Input format:
    For running the socket file, 
    first ./p2_socket must be run
    then ./q2_socket must be run in separate terminals
    For running the pipe file,
    first ./p2_pipe must be run
    then ./q2_pipe must be run in separate terminals
    For running the mpq file,
    first ./p2_mpq must be run
    then ./q2_mpq must be run in separate terminals
Output Format:
    the q2 file will print out the highest index for each signal . it should print the sequence 4, 9, 14 till 49. the p2 file will print the random strings of fixed length 5 after printing the index.
Explanation:
    For Sockets:
    In p1 file, first we create a random matrix with 50 strings of length 5 each, then we register the socket using socket() function. Then we call inet_pton, to convert the ip address from text to binary, and finally we call the connect function to connect p1 to specified port. then inside loop we use write to send the strings in groups of 5, and then we use read to receive the highest index from the p2 program. At end of the program we close the socket using the close() function.
    In p2, we register the socket and bind it to the specified port using setsockopt and bind, then we call listen on it because we will be receiving signals in it. finally, we call accept to accept the connection request put forward by p1. then in loop we read from socket to get the strings sent by p1, print them and then we send back the highest index. at end of the loop, we close the sockets.
    For pipes:
    In p1 file, first we create a random matrix with 50 strings of length 5 each,then we create the pipe using mkfifo(). then we open the pipe for writing and then send the strings through it. then we close the pipe and send it again for reading, and then we receive the highest index through it, and then print it. we finally close the pipe
    In p2 file, we create the pipe using mkfifo(). then we open the pipe for reading and read the strings through it. then we close the pipe and open it again for writing, and then we send the highest index through it and then we close the pipe.
    For message passing queues:
    In p1 file, first we create a random matrix with 50 strings of length 5 each, then we use ftok to register two queues. inside the loop, we use msgget to open the queues and we send the strings, and then we send it using msgsnd, then we receive the highest index using msgrcv, and then we close the message queues.
    In p2 file, we use ftok to register both the message queues. inside the loop, we use msgget to open the queues, and then we receive the strings and print them, then we send back the highest index using msgrcv, and then we close the message queues.
Assumptions:
    we are assuming that the user will first run p2 file and then run p1 file, in all three cases.
