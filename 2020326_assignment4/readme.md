OS assignment 4:

Question 1:

input format:
    To run the question, first we have to run command ./p and then we have to run commands ./c

output format:
    the sample programs will give us 8 random characters that we have received from /dev/urandom

explanation:
    In the p.c sample program, we first open the /dev/urandom file using the open function. after that, we check whether or not the file was opened correctly. then we read 8 bytes of data from the file, and store them into a char array rand we make with a size of 8 bytes, and then we check if they were read correctly. finally, we call the syscall writer, and get the integer it returns. 
    in the c.c sample program, we create a char array of 8 bytes(the name of the array is rande). after that we pass it as an argument in the reader syscall. 
    In the writer syscall, we assign space to a queue we have made using the kmalloc function, and check if kernel space was properly assigned(if it wasn't we return -1), and then we enqueue the data into the queue. We use reader writer semaphores to make sure that a race condition does not occur. In the enqueue function, we use down_write() and up_write() on the semaphore, and between them, we use copy_from_user() to enqueue the data from user space to kernel space. we properly set the end index, and then we return 0.
    In the reader syscall, we call the dequeue function, and then we use copy_to_user() to dequeue the 8 bytes and we properly set the end index of the queue. we use down_read() and up_read() to lock the semaphore for reading, and use copy_to_user to copy the random 8 bytes to the char array rande. after that in the reader function, we use the kfree() function to free the data of the queue, that we had assigned using kmalloc(). finally, we return 0 in the function.
    
    initially, we initialized the original linux folder as a git directory using git init and then we added the relevant files using git add. after that, we used git commit -m init to commit the current versions of the files to git. after that, we made the necessary changes in the .tbl file and sys.c file, and added the new syscalls and functions to the linux kernel. then we compiled the kernel, and then we used git diff >> diff.txt and git diff >> diff.patch to put all the differences in a diff.txt and diff.patch file.
    In this way, we added our own custom syscall to the linux kernel.

assumptions:
    we are assuming that user will run the makefile before running the executables. we are also assuming that the user will always run p.c executable before c.c executable.