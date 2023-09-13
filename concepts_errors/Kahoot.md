1. What does the act of declaring a variable in `C`/`C++` primarily do?
  - [ ] Automatically initializes the variable
  - [ ] Frees up memory
  - [x] Associates a name with a memory location
  - [ ] All of the above
  - Explanation: The declaration of a variable in `C`/`C++` tells the compiler to allocate memory space for the variable, associating a name with that space so it can be accessed later.

2. If you declare but do not initialize a variable in `C++`, what value does it hold?
  - [ ] 0
  - [x] Undefined
  - [ ] Null
  - [ ] An unchanging value throughout execution
  - Explanation: If a variable is declared but not initialized, it holds an undefined value, often referred to as a "garbage value," which is whatever data was in that memory location before.

3. What does the 'int' keyword specify in `C`/`C++`?
  - [ ] The variable can only hold characters
  - [x] The variable can hold integers
  - [ ] The variable can hold floating-point numbers
  - [ ] The variable can hold boolean values
  - Explanation: The 'int' keyword specifies that the variable will hold integer values. This also defines the size of memory that will be allocated for that variable.

4. What would happen if you try to print an uninitialized array of characters in `C`/`C++`?
  - [ ] The program will crash
  - [ ] The output will be "None"
  - [x] The output will be random characters or garbage values
  - [ ] The output will be "0"
  - Explanation: Uninitialized arrays contain "garbage values," so attempting to print them would yield unpredictable characters based on whatever was in the memory location.

5. What does 'casting' mean in `C`/`C++`?
  - [ ] Changing the memory location of a variable
  - [x] Converting one data type to another
  - [ ] Initializing a variable
  - [ ] Copying value onto a variable
  - Explanation: Casting in `C`/`C++` is the explicit conversion between compatible data types. This is useful when you want to perform operations that require different types, but should be done carefully to avoid data loss or errors.

6. What is a memory address?
  - [x] A unique identifier for a location in memory
  - [ ] The size of memory
  - [ ] The data stored in memory
  - [ ] The type of data stored in memory
  - Explanation: A memory address serves as a unique identifier for a specific location in a computer's memory. When you declare a variable, the computer reserves a spot in memory to hold its value and the variable's name is associated with this memory address.

7. What is the size of a `char` data type in `C`/`C++`?
  - [ ] 2 bytes
  - [ ] 4 bytes
  - [x] 1 byte
  - [ ] 8 bytes
  - Explanation: In `C`/`C++`, a `char` is guaranteed to be 1 byte according to the language standard. Knowing the size of your data types is crucial for understanding how much memory your program will use.

8. What will the value of `a` be? `int a; a = a + 5;`
  - [ ] 5
  - [x] Undefined
  - [ ] 0
  - [ ] 10
  - Explanation: The variable `a` is declared but not initialized. Therefore, it holds an undefined value (also known as a garbage value). Adding 5 to an undefined value will still yield an undefined result.

9. Why do you need to initialize a variable in `C`/`C++`?
  - [ ] To free memory so that it can be written onto with a value
  - [x] To avoid undefined initial values or behaviors
  - [ ] To make the variable public
  - [ ] To cast the variable to another type
  - Explanation: Initializing a variable means setting it to a value when it is declared. In `C`/`C++`, not initializing a variable could lead to undefined behavior since the variable could contain any garbage value that was previously stored in its memory location.

10. What is true about Python and `C`/`C++` variable initialization?
  - [ ] Both automatically initialize variables
  - [x] Python automatically initializes, `C`/`C++` does not
  - [ ] Neither automatically initializes variables
  - [ ] `C`/`C++` automatically initializes, Python does not
  - Explanation: Python variables are dynamically typed and automatically initialized, whereas in `C`/`C++`, the programmer has to explicitly specify the type and usually provide an initial value to avoid undefined behavior.

11. What happens when you 'read' from a memory location?
  - [ ] You copy the value stored
  - [ ] You copy then free up the memory block
  - [x] You retrieve the value stored there
  - [ ] You get the address of the memory block
  - Explanation: Reading from a memory location means retrieving the value stored at that specific address. It doesn't imply copying the value elsewhere or freeing up the memory block.

12. What is the act of associating a name with a memory location called?
  - [ ] Assignation
  - [x] Declaration
  - [ ] Initialization
  - [ ] Instantiation
  - Explanation: Declaration in `C`/`C++` involves telling the compiler to reserve space in memory and associate a name with that memory space. This is distinct from initialization, which means setting an initial value in that memory space.

13. Why do data types matter in `C`/`C++`?
  - [ ] They are optional offering clarity of parameter data
  - [x] They define how much memory to allocate and how to interpret it
  - [ ] They affect speed of a program exclusively
  - [ ] They change the program's compatibility with other languages
  - Explanation: Data types in `C`/`C++` specify how much memory is to be allocated for variables and how those bits of memory are to be interpreted. This has implications for both memory usage and program correctness.

14. In `C`/`C++`, what does the following line do? `char a[4];`
  - [ ] Declares a string of length 4
  - [x] Declares a character array of size 4
  - [ ] Initializes an array with 4 zeros
  - [ ] Declares and initializes an integer array
  - Explanation: The line `char a[4];` declares a character array with a size of 4. It reserves 4 bytes in memory but doesn't initialize them.

15. What is the main reason to be cautious when using casting in `C`/`C++`?
  - [ ] It will change the variable's memory address
  - [ ] It will reset the variable to its default value
  - [x] It risks misinterpreting the data, leading to bugs
  - [ ] It will make the variable immutable
  - Explanation: Casting can be risky because it can lead to misinterpretation of data. For example, if you cast a float to an integer, you will lose the decimal part, which might not be what you intended.

16. What does the `#include <iostream>` directive do in a `C++` program?
  - [x] Imports the library making input-output stream operators available
  - [ ] Imports a library which is a required inclusion for `C++` scripts
  - [ ] Defines the variables to be used in the program
  - [ ] Includes Python's input-output functions to the `C++` program
  - Explanation: The `#include <iostream>` directive in a `C++` program includes the header for the Input/Output stream library, allowing the use of standard I/O operations like `cout` and `cin`.

17. Which of the following situations could result in the error `"foo" was not declared in this scope`?
  - [ ] The function "foo" was declared before it was called
  - [ ] You're running the code in a Python environment
  - [x] The library where function "foo" is declared in wasn't imported
  - [x] The function "foo" was called before it was defined
  - Explanation: Anything that is called without a prior declaration will raise this error. This error usually means that the compiler can't find a declaration for "foo" which could be a variable, function, or type either inside of your own program or from a library. This often occurs when the necessary header or even the namespace (consider `C++`'s 'std::') has not been included. This might also happen if there is a discrepancy between the name of the function you've declared, and the name of the function you are using (consider a typo like reverseComplement() vs reverse_Complement).

18. What type of error is presented when you try to assign a string literal to a `char` variable? (i.e when `C++` cannot resolve the discrepancy in type)
  - [ ] Run-time Error
  - [ ] Logical Error
  - [ ] Syntax Error
  - [x] Compile-time Error
  - Explanation: Trying to assign a string literal to a `char` variable results in a compile-time error. This is because a string literal is a sequence of characters, and a `char` variable can only hold a single character. The compiler detects this type mismatch during compilation and raises an error.

19. What is the default behaviour if you execute a `C++` program with a division by zero?
  - [ ] The program will terminate successfully
  - [ ] The program will hang indefinitely
  - [x] The program will throw a floating-point exception
  - [ ] The program will ask the user to enter a non-zero number
  - Explanation: Dividing by zero in `C++` results in a floating-point exception. This is a runtime error that occurs when the program attempts to perform an illegal arithmetic operation. The program will crash and terminate due to the division by zero, and the exception can be caught and handled using exception handling mechanisms.

20. What does the if __name__ == '__main__': statement do in Python?
  - [ ] Imports the main function
  - [ ] Checks if Python is installed
  - [x] Allows differentiation between module import and standalone execution
  - [ ] Declares the main function as 'main'
  - Explanation: In Python, the `if __name__ == '__main__':` statement allows you to determine whether the script is being run as the main program or imported as a module. It helps separate code that should only run when the script is executed directly from code that should not run when the script is imported as a module.

21. Which statement is used to include libraries/header files in `C++`?
  - [ ] `import`
  - [ ] `using`
  - [ ] `require`
  - [x] `#include`
  - Explanation: In `C++`, the `#include` statement is used to include libraries or header files. These files contain pre-defined functions and classes that you can use in your program. Including a library makes its functions and declarations available for use in your code.

22. What is scope in programming?
  - [ ] A library in `C++`
  - [x] The location in a program where a name is visible and accessible
  - [ ] Debugger tool that allows you to identify which functions are loaded
  - [ ] A variable declaration
  - Explanation: Scope refers to the region in your code where a variable or identifier is visible and accessible. It defines the context in which the variable can be used and accessed. Scopes help prevent naming conflicts and provide structure to your code.

23. In Python, what does the statement 'from sys import stdin' do?
  - [x] Imports the stdin function from the sys library
  - [ ] Imports all functions from the stdin library
  - [ ] Imports the sys function from the stdin library
  - [ ] Imports both the stdin and stdout functions from the sys library
  - Explanation: The statement `from sys import stdin` in Python imports only the `stdin` function from the `sys` library. This allows you to use the `stdin` function directly without referencing the `sys` module. It's a way to import specific functions from a library.

24. What happens in `C++` when you use '=' instead of '==' in an if statement like "if (a[i] = 3) return;"?
  - [ ] Compile-time Error ()
  - [ ] Syntax Error
  - [x] Semantic Error
  - [ ] Run-time Error
  - Explanation: Using `=` instead of `==` in an if statement in `C++` results in a semantic error. The `=` operator is the assignment operator, and it assigns the value on the right to the variable on the left. In an if statement, you should use `==` to compare values, not `=`.

25. What does the term "Compile-Time" refer to?
  - [ ] The time it takes to run a program
  - [x] The time taken to translate source code to an executable file
  - [ ] The time when the program is being executed
  - [ ] The time when the program is in debug mode
  - Explanation: Compile-time refers to the phase during which the source code of a program is translated by the compiler into machine code or an intermediate representation. This phase occurs before the program is executed. Errors detected during compile-time are known as compile-time errors.

26. Where are header files typically stored in `C++`?
  - [ ] /usr/bin/
  - [x] /usr/include/
  - [ ] /usr/lib/python/
  - [ ] /etc/
  - Explanation: Header files in `C++` are typically stored in the `/usr/include/` directory. These header files contain function prototypes, declarations, and other information needed to interface with libraries and source code.

27. Where are Python library files typically stored?
  - [ ] /usr/bin/
  - [ ] /usr/include/
  - [x] /usr/lib/python/
  - [ ] /etc/
  - Explanation: Python library files are typically stored in the `/usr/lib/python/` directory. These files include pre-defined modules, functions, and classes that can be imported and used in Python programs.

28. What does the -o flag do in g++ file_name.cpp -o file_name.x?
  - [x] Specifies the output file name
  - [ ] Opens the file for reading
  - [ ] Optimizes the code
  - [ ] Copies to an existing file
  - Explanation: The `-o` flag in the `g++` compiler command specifies the output file name for the compiled executable. In the example `g++ file_name.cpp -o file_name.x`, the `-o file_name.x` part indicates that the compiled output should be named `file_name.x`.

29. Which error occurs when the function definition and declaration don't match in terms of parameters?
  - [ ] Semantic Error
  - [ ] Run-time Error
  - [ ] Linker Error
  - [x] Compile-time Error
  - Explanation: When the function definition and declaration have mismatched parameters, a compile-time error occurs. The compiler checks that the function declaration and its implementation match in terms of parameter types and order. Mismatched parameters result in a compile-time error.

30. What is a Semantic Error?
  - [ ] An error that occurs during compilation
  - [ ] An error that prevents the program from running
  - [x] An error where the program runs but doesn't behave as expected
  - [ ] An error that occurs when the code is syntactically incorrect
  - Explanation: A semantic error is an error where the program compiles and runs without crashing, but it produces incorrect or unexpected results. This type of error is caused by flawed logic or incorrect use of programming constructs


Esto no se quen poner.
