# C-Exercises
This repository contains exercises developed in C and C++.
<br>
## Objective
The objective of these exercises was to learn and practice C programming while developing problem-solving skills and undestanding different programming concepts.
<br>
## Contents

### **177294-178666_P9P1C_P22.c**
This program is an improved version of 177294-178666_P5P1C.c it ask for similar information but includes additional input verification:

- Age verification: it has to be a number it has to be between these values (3-89).
- Phone number verification: it has to have 10 numbers.
- Email verification: The email must contain five lowercase letters followed by @gmail.com.

Then its displayed if the user accepts the info was correct, they information is displayed in different areas of the console using gotoxy().

Concepts practiced: input validation, strings, conditional statements, and console positioning.

### **177294-178666_P5P1C.c**
The user is asked to type some personal information. After confirming that the information is correct, its displayed in the console using table-like design with gotoxy().

Concepts practiced: input validation, strings, conditional statements, and console positioning.

### **177294_P10P1C.c**
The user is asked to enter a series of numbers they must be even numbers; if an odd number is entered the user is asked again to type them.

Once the user finishes typing the numbers, three arrays are created:

- The first array is filled with random numbers between 19 and 45.
- The second one is filled with the numbers entered by the user.
- The last one is filled with 10 random odd numbers between 5 and 30.

Concepts practiced: Arrays, input validation, loops, and random number generation.

### **177294_P12P1C.c**
An array is filled with random numbers and then displayed in the console, ther is aslo a function that sums the array numbers and then displayes the value, then lastly its modified by a function that changes the numbers that are multiples of 5 into -1 and then the array is printed again with the modified numbers.

Concepts practiced: Arrays, functions, loops, and random number generation.

### **177294_P12P2A.cpp**
This program reads product information from a file name arch.txt, which is opened in read mode (r).

It displays the products and allows the user to navigate them with the right and left arrow keys. While navigating the user can see each products id, name, description, price, and rate.

The id and rate are generated randomly, This exercise is stored inside a folder so that the text file is alongside the code.

Concepts practiced: File handling, reading data from files, keyboard input, and random numbers generation.

### **177294_P13P1C.c**
This program creates an array containing six drinks and another array containing their prices for different presentations of the drinks such as 1 liter, this prices are generated randomly. 

It shows 3 results:
- The highest price for the selected presentation.
- The highest price for the 1lt presentation.
- The average price of a drink based on all its presentations.

Concepts practiced: Arrays, nested loops, functions, and basic data analysis.

### **177294_P15P1C.c**
This program is an improved version of 177294_P13P1C.c with additional functions.

The main differences are:
- The second otuput, it shows the most expensive drink and the one the second highest pric.
- In the third output instead of displaying only the average price of one drink it calculates the average of each drink and then identifies the cheapest one.

Concepts practiced: Arrays, nested loops, functions, and comparison of values.

### **177294_P1P2A.c**
This program sends an array to two different functions, the first function initializes the array by filling it with zeros , and the second function fills it with random numbers without repeating any previously generated values.

Concepts practiced: Arrays, nested loops, functions, and random numbers generation.

### **177294_P9P2A.cpp**
This program creates a visual doubly linked list which is displayed in the console using gotoxy(), it was developed in c++ and allows the user to add or remove nodes from the list.

Concepts practiced: structures, pointers, dynamic memory allocation, and doubly linked lists.

### **177294_Diagnostico**
This program reads a file opened in read mode (r). It then displays each character form the file in the console.

The source code and the file are stored inside a separate folder.

Concepts practiced: File handling, and character by character file reading.

### **5cadenas.c**
The user is asked to type 2 words then 3 words that were previously created by default plus the words the user typed are displayed with the vocals changed to the $ symbol and some words with a different color.

After that the user is asked to select one of the 5 words and replace with a new word.

Finally the list is displayed again 2 more times, once with the  number of characters next to each word and once with the number of consonants.

Concepts practiced: Strings, arrays, character manipulation, and console formatting.

### **algoritmo18.c**
This program checks all numbers from 999 down to 1 and counts how many meet six different conditions related to divisibility by 7, 11, both or neither. It ends up showing the count of each condition.

Concepts practiced: Loops, conditional statements, and divisibility.

### **algoritmos1.c**
This program performs several mathematical operations including:

- Factorials.
- Linear permutations.
- Circular permutations.
- Permutatios with repetition.
- Combinations.
- Binomial expansion.
- Object distribution.

Concepts practiced: Mathematical algorithms, funcitons, loops, and conditional statements.

### **arboles.cpp**
This program creates a binary search tree (BST), which is a hierarchical data structure.

At the beggining fo the program some nodes are inserted following the BST rules. Each node can have up to 2 children: a left and riht child. The left contains a smaller value than its parent and the right one contains a greater value.

Like the linked list exercices, this one uses structures to represent each node and dynamic memory allocations to reserve the memory for every new node.

Besides inserting and deleting nodes, the program implemes three tree traversal algorithms: 

- Preorder.
- Inorder.
- Postorder.

These traversal algorithms are different ways of visiting and displaying the nodes of the tree.

After displaying the three orders it asks the user to delete a value and after the user types the number the three is displayed again using the postorder is printed again without the node that was eliminated.

Concepts practiced: Structures, pointers, dynamic memory allocation, recursion, bynary search trees, (node insertion and deletion), and tree traversal algorithms.

### **arreglos.c**
This program contains an array with the numbers 1 to 6. The elements are displayed in the console one by one.

After that, the program adds the elements located at even indexes and displays the result. This means it adds the elements at positions such as array[0] + array[2], rather than adding only the even numbers in the array.

Concepts practiced: Arrays, loops, indexes, and basic arithmetic operations.

### **calificacionesdinamico.c**
This program manages subjects and their grades. It uses dynamic memory, even though the same task could have been completed with simple arrays since it was created to practice pointers.

It starts by asking the user to enter:

- The number of subjects (filas or rows)
- The number of grades per subject (columnas or columns)
- The name of each subject
- The grades for each subject.

After collecting all the information it prints a table containing each subject, its grades, and in the last column its average.

The main difference in this program is the use of double pointers to create a structure similar to a 2D array using pointers to pointers.

Concepts practiced: Dynamic memory allocation, double pointers. arrays of poinetrs, 2D arrays structures, and memory deallocation.

### **ejemplo rand.c**
The user is asked to whether they want to generate a random number.
If they type 1 they get a random number between 1000 and 2500, then asks again whether they want another random number.

This process continues until the user decides to not get more typing 2. 

Concepts practiced: Random number generation, loops, and conditional statements.

### **ejemplo validaciones.c**
The user is asked to enter 1 or 2 depending on whether they are single or engaged. The program uses a switch statement to determine which status to display in the console.

If the user enters an invalid option, such as 3, the program asks them to select a valid option until the option is valid and the marital status is displayed.

Concepts practiced: loops, switch statements, and conditional logic.

### **estructura.cpp**
This program stores information about three swimmers using an array of structures.

The user is asked to enter the name and age of each swimmer, the program assigns them to one of these two categories:

- Juvenil: Ages 18 and younger.
- Veterano: Ages above 18.

After collecting the information, the program displays a table containing each swimmer's name, and assigned category.

Concepts practiced: Structures, arrays of structures, loops, string manipulation, user input handling, input buffer management, and conditional statements.

### **estructuranumeros7.c**
This program uses an array of structures to store seven integers.

The user is asked to enter seven numbers, which are stored individually in the num member of each structure. After collecting all the numbers, the program iterates through the array again and displays them in the console.

The array is declared directly after the stucture definition, combiningboth declarations into a single statement.

Concepts practiced: Structures, arrays of structures, loops, user input.

### **insertarordenado.cpp**
This program implements a singly linked list that stores contact information, including names and phone numbers.

The user can insert new contacts, display the complete list, and delete an element by specifying the name of the contact that comes before the element they want to remove.

New contacts are initially added to the end of the list. After the insertion process, the program sorts the contacs alphabetically by name.

The list uses two pointers to keep track of its first and last nodes, making it easier to insert new elements at the end.

Concepts practiced: Structures, self-referencial structures, pointers, singly linked lists, dynamic memory deallocation, string manipulation, sorting alforithms, and node insertion and deletion.

### **listadoblecircularordenada.cpp**
This program implements a circular doubly linked list that stores contact information, including names and phone numbers.

The user can insert new contacts, display the complete list in both forward and backward directions, search for a contact by name, and delete an element by specifying the name of the contact.

New contacts are initially added to the end of the list. After the insertion process, the program sorts the contacts alphabetically by name.

The list uses two pointers to keep track of its first and last nodes, making it easier to insert new elements at the end. Unlike a singly linked list, each node contains two pointers: one pointing to the next node and another pointing to the previous node. Additionally, the last node connects back to the first node, and the other way around, making the list circular.

Concepts practiced: Structures, self-referential structures, pointers, circular doubly linked lists, dynamic memory allocation, memory deallocation, string manipulation, sorting algorithms, and node insertion and deletion.

### **listadobleordenada.cpp**
This program implements a doubly linked list that stores contact information, including names and phone numbers.

The user can insert new contacs, display the complete list in both forward and backward directions, search for a contact by name, and delete an element by specifying the name of the contact that comes before the element they want to remove.

New contacts are initially added to the end of the list. After the insertion processm the program sorts the contacts alphabetically by name.

The list uses two pointers to keep track of its first and last nodes, making it easier to insert new elements at the end. Unlike a singly linked list, each node contains two pointers: one pointing to the next node and another pointing to the previous node. This allows the list to be traversed in both directions.

Concepts practiced: Structures, self-referential structures, pointers, doubly linked lists, dynamic memory allocation, memory deallocation, string manipulation, sorting algorithms, and node insertion and deletion.

### **listasmenu.cpp**
This program implements a singly linked list that stores contact information, including names and phone  numbers.

The user can display the complete list, insert new contacts at the beggining or end of the list, insert a contact after a specific element, and delete contacts from the beginning, end, or a specific position.

Unlike the previous exercises, this program does not sort the contacts alphabetically. Instead, it allows the user to choose where new elements are inserted, giving them more control over the order of the list.

The list uses two pointers to keep track of its first and last nodes, making it easier to insert new elements at the end.

Concepts practiced: Structures, self-referential structures, pointers, singly linked lists, dynamic memory allocation, memory deallocation, string manipulation, and node insertion and deletion.

### **programa_arreglos.c**
This program declares three integer arrays, each containing 10 elements.

The first array is filled with random numbers between 19 and 45. The second array is filled with even numbers entered by the user, validating each input to ensure that only even numbers are accepted. The third array is filled with random odd numbers between 5 and 29.

Finally, the program displays the contents of all the arrays separately.

Concepts practiced: Arrays, loops, conditional statements, input validation, random number generation, and array traversal.

### **programa bidimencional.c**
This program uses a two-dimensional character array to store three words entered by the user. After collecting the input, it displays all three words separately.

Each word can contain up to 5 characters, plus the null terminator.

Concepts practiced: Two-dimensional arrays, strings, loops, and user input.

### **programa1_labo.c**
This program demostrates basic data input and output in C. It asks the user to enter the numebr of groups, an averag, a character, and the number of students, it then displays all the collected information.

Concepts practiced: Variable declaration, data types (int, float, char), format specifiers, and basic input handling.

### **programa2_labo.c**
This program demonstrates basic arithmetic operations, operator precedence, and string manipulation in C. It calculates the average of three grades, displays the quotient and remainder of integer division, and allows the user to enter an animal name. It then accesses and modifies individual characters in the string and uses strcpy() to replace its contents.

Concepts practiced: Arithmetic operators, operator precedence, modulus operator, string manipulation, and array indexing.

### **programa29_marzo.c**
This program declares a two dimensional integer array with 4 rows and 3 columns. It uses nested for loops to assign values to each element based on its row index(i * 5) and then displays the array row by row.

Concepts practiced: Two-dimensional arrays, nested loops, array indexing, and element assigment.

### **tareaprogralab177294.c**
This program creates three groups of students: Programming, Electronics, and Arts. It registers three students in each group, storing their names, randomly generated ages(12-35), and unique IDs. Each group has its own ID range: 100-111 for programming, 120-131 for Electronics, and 140-151 for Arts. It displays the registered students along with their information, organized by group.

Concepts practiced: Structures, typedef, two-dimensional arrays, functions, global variables, random number generatio, loops, and conditional statements.

### **validacioncorreo.c**
This program asks the user to enter an email address and validates it againts a specific format. The email must contain 15 characters: 5 lowercase letters(with periods or underscores allowed in this first section), followed by @, 5 lowercase letters(like for example gmail), and .com. If the input does not meet these requirements, the program asks the user to try again.

Concepts practiced: Strings, arrays, loops, conditional statements, input validation, and string indexing.

### **validacioncurp.c**
This program asks the user to enter a CURP and validates its baseic 18 character structure. It checks that each section contains the expected character types:

- First section 4 letters.
- Second section 6 digits.
- Third section 6 letters.
- Last section 1 alphanumeric character and 1 last final digit.

If the input does not match the required format, the program asks the user to try again.

Concepts practiced: Strings, arrays, loops, conditional statements, and input validation.

## Disclaimer
These exercises were developed during my learning process, so some code may not follow current profesional coding standars or best practices.

Some comments are written in Spanish, as they were used for personal notes and explanations while leaning and understanding different programming concepts

## System Requirements
- Operating System: Windows, Linux or macOS.
- IDE/Code Editor: Any C-compatible development environment such as: Dev C++ or Visual Studio.
- Compiler: GCC, Clang or MSVC
