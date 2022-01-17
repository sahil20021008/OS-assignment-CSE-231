os assignment 2
question 1:
input format:
    in this question, the user will first input the number of rows in the matrix. then after that, they will enter the number of columns in each row in the matrix
output format:
    the contents of the matrix will be printed showing that we have created an irregular matrix with
explanation:
    after the user enters the number of rows, we create a matrix of integers with n number of rows, where n is the number of rows. after, this the user will input the number of columns in each row, which we fill with -1, to signify that that is the end of the column in that row. finally, we fill the matrix with 1's, and print the matrix.
assumptions:
    we are assuming that the user will enter less than 1000 columns for each row, and that all input will be numbers

question 2 part a:
input format:
    first the user will enter the number of operations they wish to perform. after that they will enter a choice of what operation they want to perform. they can either insert new student records, delete records of a student, search for a students records, or print the entire student records.if they want to insert, they will have to input student name, roll number, year, and academic program. if they want to delete, they will have to enter the roll number of the student whose records they want to delete. for searching for a students records, they will have to enter roll number. no additional input is required for printing the entire records.
output format:
    searching for a record will print that particular students name, roll number, year, and academic program. printing the entire records will print every students name, roll number, year and academic program. insertion and deletion make changes to the list but do not print anything.
explanation:
    for insertion, we will create a new student records temp, and input the given values into it. then we will add temp to the end of the list, and return head.
    for deletion we will remove a students records from the list and return head of list.
    for searching we will print the required students records.
    for printing entire list we simply print every students records.
assumptions:
    we are assuming that a student's name will be smaller than 100 characters, his roll number and year will be smaller than 10 digits, and that his academic program will be smaller than 200 characters.
    as scanf() is used to take input, we will only store first name of student, and academic program is assumed to have no spaces.

question 2 part b:
input format:
    first the user will enter the number of operations they wish to perform. after that they will enter a choice of what operation they want to perform. they can either insert new student records, delete records of a student, search for a students records, or print the entire student records.if they want to insert, they will have to input student name, roll number, year, and academic program. if they want to delete, they will have to enter the roll number of the student whose records they want to delete. for searching for a students records, they will have to enter roll number. no additional input is required for printing the entire records.
output format:
    searching for a record will print that particular students name, roll number, year, and academic program. printing the entire records will print every students name, roll number, year and academic program. insertion and deletion make changes to the list but do not print anything.
explanation:
    for insertion we will create a new student record temp, and input the given values in it, then we will add temp to the beginning of the list and return head of the list.
    for deletion we will remove a students records from the list and return head of list.
    for searching we will print the required students records.
    for printing entire list we simply print every students records.
assumptions:
    we are assuming that a student's name will be smaller than 100 characters, his roll number and year will be smaller than 20 digits, and that his academic program will be smaller than 200 characters.
    as scanf() is used to take input, we will only store first name of student, and academic program is assumed to have no spaces.
question 2 part c stack:
input format:
    first, the user will enter the maximum no of operations they want to perform on stack. then the user will enter their choice whether they want to push a value onto stack, pop the topmost value of stack, find top value of stack, or print all values in stack
output format:
    push function doesn't print anything and only alters the stack
    pop will remove the topmost value of stack and print it
    top will print the topmost value of stack
    stackprint() function will print all the values in the stack
explanation:
    the user initially inputs how many operations they wish to perform on stack. after that using for loop the user will enter the operation they wish to perform those many number of times. if the user wants to push a value onto stack, they will have to enter additional data to push onto stack. if user wants to delete topmost value from stack, pop() function will do that, and return the value of the previous topmost function which is printed. top() function will return value of topmost value without deleting it. stackprint() will print all the elements of the stack.
assumptions:
    we are assuming that the data input by user will be smaller than 10 digits.
question 2 part c queue:
input format:
    first, the user will enter the maximum no of operations they wish to perform on the queue. after that, the user will enter their choice as to whether they want to add a value to queue, remove a value from queue, find the value at bottom of queue, or to print all elements of the queue
output format:
    enqueue function doesn't print anything and only alters the queue
    dequeue function will remove the element at end of queue and print its value
    peek function will return the value at end of queue
    queue_print will print all the elements in queue
explanation:
    after the user has input the number of operations they wish to perform on queue, they will choose the operation they wish to perform. first the queue is initialized and head and tail pointers are set to NULL.
    for insertion if head and tail are null, they are both set to the new node. otherwise the tail pointer's next value is given to the new pointer and then tail is reset.
    for deletion, the head is set to its next pointer because of which the previous pointer cannot be accessed anymore and is essentially null, then the data of the previous head which had been saved is now returned and printed
    for peek, it essentially returns the value of the data at head, otherwise if queue is empty, it returns -1 and prints that queue is empty
    queue_print prints all elements in queue, by printing an element then traversing to the next one, and so on until the end of queue is reached.
assumptions:
    we are assuming that the data input by user will be smaller than 10 digits.
question 3:
input format:
    initially the user enters a number(between 0 and 4) which represents their choice of the operation they wish to perform. after this, the user enters two numbers which are the operands for the operation.
output format:
    after the user has entered two numbers, the output is printed and the program ends
explanation:
    we have created void* type functions, and have created an array that points to these functions. first we take input from user as to which function they wish to perform, then we take input of the two numbers the operation will be performed on. after this, the operation will be performed on the two numbers and the result would be printed. the function will return null, and finally the program will end
assumptions:
    we are assuming that the user will enter a valid choice. if user wants to use division function, we are assuming that they will not enter the second number as 0, as 0 cannot be denominator.
question 5:
input format:
    first the user will enter the number of elements in the array. after that the user will enter all the elements of the array. finally the user will choose whether they want to use selection sort or bubble sort on the array.
output format:
    the output will be the sorted array that was sorted using either selection sort or bubble sort.
explanation:
    after the array has been inputted, the user will select whether the program will perform bubble sort or selection sort. in bubble sort, we use two nested loops, and then if the succeeding element is smaller than the current element, we swap both elements. in selection sort, we use nested loops to find minimum element in array, then we place that at its respective position. 
    in this way, we can sort array through either bubble sort or selection sort.
assumptions:
    we are assuming that integers will be  input. as we are storing input in int array, numbers smaller than 2147483647 only should be input.