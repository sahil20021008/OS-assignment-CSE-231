OS assignment 2:
question 1:
input format:
    No input is required
output format:
    the program will keep printing numbers.
    For numbers printed by SR, a random number will be printed.
    But for ST, two numbers will be printed, one is the timestamp, and the other is a random number
explanation:
    in the main function we call a function we have named as s1. In s1, we create two new arrays, that have the filename of sr and st as elements. after that, we use fork to create a new child process s1(child). there we register signal for SIGTERM, which will send the program to a new function s1_sig_handler(). In the parent process, we again call fork to create new child process sr(sr_f).Here, we call execv() and execute the sr file. In parent process we again call fork() and create child process st(st_f). In this we call execv and execute the st file. Then, the parent process ends.
    In sr file, we register signal for SIGALRM that will take us into function srf, then we create a timer that will raise SIGALRM every half a second. After that, the srf function will get a random number using inline assembly. After that we will register signal for SIGTERM of s1_sig_handler() using sigaction(), and then we will send the signal using sigqueue with the value of the random number.
    In st file, we register signal for SIGALRM that will take us into function stf, and then we will create a timer that will raise SIGALRM every half a second. After that, the stf function will get us the timestamp and a random number using inline assembly. After that we will register the signal for SIGTERM for s1_sig_handler() using sigaction(), and then we will send two signals using sigqueue with the value of the timestamp, and the random number.
    The program will keep printing the numbers until the user closes the terminal.

    First, the user has to run the makefile. That will create executables for the three files. after that, the user has to type in the command ./q1
    This will run the question 1 executable, and keep printing numbers until the user closes terminal.

question 2:
input format:
    No input is required
output format:
    the program will first output the original matrix, then it will output the copied matrix.
explanation:
    The program will first create two matrix with 4 rows and 5 columns. After that, it will assign values to the first matrix. then, it will call kernel_2d_memcpy function, that will copy the contents of the first matrix into the second matrix. finally, it will first print the original matrix, and then the second matrix which will have the same values as the original matrix.

    To run the second question the user will have to run the command:  ./q2
    this will run the sample program of the second question

    In the syscall kernel_2d_memcpy, we create a floating point matrix temp with the same dimensions as the two matrices in the kernel space. then we use copy_from_user to copy the contents of first matrix and paste it into temp. then we copy the contents of this matrix, and then paste it into second matrix. Finally, we return 0, and this ends the function.

    In the first matrix we fill the values in matrix that are the sum of the row index and the column index. As the matrix has 4 rows and 5 columns. It should have values as
    0 1 2 3 4
    1 2 3 4 5
    2 3 4 5 6
    3 4 5 6 7

    initially, we initialized the original linux folder as a git directory using git init and then we added the relevant files using git add. after that, we used git commit -m init to commit the current versions of the files to git. after that, we made the necessary changes in the .tbl file and sys.c file, and added the new syscall to the linux kernel. then we compiled the kernel, and then we used git diff >> diff.txt and git diff >> diff.patch to put all the differences in a diff.txt and diff.patch file.
    In this way, we added our own custom syscall to the linux kernel.