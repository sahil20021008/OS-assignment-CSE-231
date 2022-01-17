OS assignment 1

question 1:
input format:
    first the path of the source file, then the path of the destination file
output:
    the contents of the source file will be copied onto the destination file
Explanation:
    after taking input and output, we find size of the file using fseek() and ftell(). then using a character array we use fread() to write the input into the character array and use fwrite() to write this output into the output file from the character array
assumption:
    we are assuming that text file will have filename less than 1000 characters.
question 2:
input format:
    two integers are to be input, one by one and enter must be pressed after inputting each number
output format:
    the sum of the two integers is the output. 
explanation:
    after taking input of numbers, we convert them into binary numbers using bint() adn divide() function. after that we store the binary numbers in 32 byte char array. then we add these char arrays and store the result in a third char array. finally, we convert this char array back to an integer and print the result
assumptions:
    we are not handling overflow case. in case of overflow, the final number will be printed with the overflowed values.
question 3:
input format:
    first, the user has to enter 0 or 1 depending on whether they want to swap numbers or arrays. after that, if we had chosen 0, we will input two integers. but, if we had chosen one, we will first input the number of elements in each array, then we will input the elements in each array.
output format:
    if we swapped two numbers, we will get output showing the initial numbers and then the swapped numbers, but if we swapped two arrays, we will get output showing the elements of the initial arrays and then the elements of the swapped arrays.
explanation:
    first, we ask user to input whether they want to swap arrays or numbers. if they want to swap numbers, we take input of both numbers. then, using a third integer, we swap the values stored in the integers.
    if they want to swap numbers, we take input array size then of both arrays, and then using a third integer to swap the elements at same indices in the arrays.
    finally, we print the swapped numbers or swapped arrays.
assumptions:
    we are assuming that there is only integer input. the choice entered by user should be valid. as we are storing in integer array, the numbers should ideally be smaller than 2147483647.
question 4:
input format:
    the user will have to input a string. the maximum length of string is 1000 characters.
output format:
    the output will be the reversed string.
explanation:
    after user has input a string, we find its length. after finding the length we add the reverse string to an extra char array using a for loop. finally, we print the reversed string using printf function. as we are using fgets() function, the user can also input strings with spaces.
assumption:
    we are assuming that the string input by the user will be smaller than 1000 characters.
question 5:
input format:
    the user will first input the number of elements in the array, then he will input the elements in the array. finally, the user will input the element whose element they want to find
output format:
    the program will print the sorted array, as well as the index the required integer is at. if the element is not in the array, it will be printed in output
explanation:
    first the user will input the length of the array, then the elements of the array. finally, the user will input the required element. the program will first sort the array using bubble sort and place all the elements at the correct positions. after that we will perform binary search on the elements and print the index at which the required element is at in the sorted array.
assumptions:
    we are assuming that the user will input the three required numbers 4294967290, 4294967295, 10400.
