os assignment 3
question 1:
input format:
    the user will enter 3 integers denoting date as dd mm yyyy format.
    eg: 24 03 2019
    the date will be entered as command line argument, and space is to be given between date month and year.
output format:
    a line will be printed denoting the date the user has entered. after that, if the date entered is a valid date, then a calendar of that month will be printed. but if the date is invalid, an error statement will be thrown that this date is invalid.
explanation:
    the user will input the date as command line arguments in format dd mm yyyy . after that, the program will check if the date is a valid date. if it isn't, an error will be thrown, that the date is invalid, otherwise the calendar for that date will be printed.

question 2:
input format:  
    in the command line argument the user will enter the operation they wish to perform(addition, subtraction, multiplication,division or exponentiation). the input should be add, sub, mul, div or exp, for the operations. then the user will enter unknown number of operands(at least 2 operands).
output format:
    the program will compute the result of the operands functions, and print the result.
explanation:
    after the user has input the arguments, we store the operation name in a variable, then we store second argument in another variable and iterate over the arguments until the end, and store the result in variable. at the end of code, we print the final result.
assumption:
    we are assuming that after operation name, the user will input at least two more operand arguments.
    the exponentiation function takes exponents from left to right instead of right to left.
question 3 a:
input format:
    first the user enters a number n which is the number of operations they wish to perform. after that, the user will make n choices, which will signify which operation they wish to perform.
    for insertion, the user will enter data to be inserted.
    for deletion, the user will enter data to be deleted.
    no additional input is required for inorder print.
    if any other choice is input, it is not accepted and user is asked to enter valid choice
output format:
    insertion and deletion do not print any output and simply alter the bst. 
    inorder print will print all elements of the bst in increasing order.
explanation:
    after the user has entered the max number of operations to be performed on the bst, they will have to input choice n times to decide which operation they wish to perform.
    insertion function will traverse through bst until it finds a null node, and then new node will be put there.
    deletion function will traverse tree until finding required node, and then that node will be removed from tree, and its root will be connected to its other nodes.
    inorder print will traverse tree, printing the nodes value in ascending order.
assumptions:
    we are assuming that only numbers will be input.
question 3 b:
input format:
    first the user enters a number n which is the number of operations they wish to perform. after that, the user will make n choices, which will signify which operation they wish to perform.
    for insertion, the user will enter data to be inserted.
    for deletion, the user will enter data to be deleted.
    no additional input is required for inorder print.
    if any other choice is input, it is not accepted and user is asked to enter valid choice
output format:
    insertion and deletion do not print any output and simply alter the avl tree. 
    inorder print will print all elements of the avl tree in increasing order.
explanation:
    insertion function will traverse the tree until finding a null node, where new node will be inserted. after inserting new node, the avl tree will be balanced, by rotating the subtrees of nodes wherever necessary.
    deletion function will traverse tree until finding the required node, and then that node will be removed from tree, and its root will be connected to the other nodes. then the tree will be balanced by rotating subtrees of nodes wherever necessary.
    inorder print will traverse the entire tree, and print the elements of the tree in ascending order.
question 4:
input format:
    first the user will enter the number of elements in the array. after that the user will enter all the elements of the array. finally the user will choose whether they want to use selection sort or bubble sort on the array.
output format:
    the output will be the sorted array that was sorted using either selection sort or bubble sort.
explanation:
    after the array has been inputted, the user will select whether the program will perform bubble sort or selection sort. in bubble sort, we use two nested loops, and then if the succeeding element is smaller than the current element, we swap both elements. in selection sort, we use nested loops to find minimum element in array, then we place that at its respective position. 
    in this way, we can sort array through either bubble sort or selection sort.
assumption:
    we are assuming that the user will only enter integers. as we are using integers, there is a possibility of overflow, so the user should ideally enter numbers less than 2147483647, otherwise they will overflow and be stored as negative integers.