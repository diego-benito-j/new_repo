# C / C++ errors and concepts

- [section: pass by reference vs. pass by value #26](https://github.com/deliaBlue/laPrepa/issues/26)
- [section: Handling errors #25](https://github.com/deliaBlue/laPrepa/issues/25)
- [section: dynamic memory allocation #24](https://github.com/deliaBlue/laPrepa/issues/24)

# Handling Errors

Ideally, programming would require little more than a problem, some ingenuity in figuring out how to solve it, and writing out some code that does what it ought to do to solve the issue at hand. 

It is on this statement - “does what it ought to do” - that most difficulties in implementation arise, since we typically believe we know what the intended behavior should be way sooner than we ought to.

Before we enter the minutia of how to interpret and understand errors within the context of C / C++, you should consider that the hardships of making something do what it ought to do typically emerge from one of the following:

- You have misunderstood the nature of the problem
- You have misunderstood the nature of your solution

We will deal primarily with the latter of the two situations. Our aim is to develop a basic understanding of the particularities of C / C++ within the context of your 2nd academic year, specifically what the error messages you'll encounter reveal about the code you’ve written and what concepts are useful to become better debuggers.

> Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.
> 
> 
> Brian W. Kernighan.
> 

### Format of this section:

`file_name.cpp`
```c
// Some code in C or C++

int main(){
    cout << "Hello World!\n";
}
```

<details open>
<summary>

#### Compilation & Output

</summary>
<br>

```console
dbj@dbj:~$ g++ file_name.cpp -o file_name.x
file_name.cpp: In function ‘int main()’:
file_name.cpp:2:5: error: ‘cout’ was not declared in this scope
    2 |     cout << "Hello World!\n";
      |     ^~~~

```

</details>

<details open>
<summary>

#### Expected Compilation & Output

</summary>
<br> 

```console
dbj@dbj:~$ g++ file_name.cpp -o file_name.x 
dbj@dbj:~$ chmod +x file_name.x  # technically not necessary - file_name.x is already executable
dbj@dbj:~$ ./file_name.x
Hello World!
dbj@dbj:~$
```

</details>


<details open>
<summary>

#### Concepts related to issue at hand

</summary>

##### Libraries & Scope (INCLUDE NAMESPACE???? STD::)

You've probably written a python program importing some function/class from some library[^lib], where you've had to include a statement along the lines of `import sys` or `from sys import stdin`.

These statements are making whatever functions you specify **visible and accessible** within your program [^1] - which is another way of saying that you are including the funcitons within the global **scope** [^scope] of your program. In this particular case, the `import` statement ensures that whenever the python interpreter reads 'sys.stdin.readline()' or 'stdin.readline()', it **knows what the function `readline()` is** since you've specified where the function is defined (some module called sys). 

You are **including** all funcitons associated to the module sys within the scope of your python script, importing them from some file in your computer[^file_py].

In C and C++, any operation that requires reading from standard input (stdin) or printing to standard output (stdout) requires the use of an external library (**no `print()` nor `input()` without any imports like in python!**). 

In our case, we are using `cout`, which is part of the `iostream` library. In python we used the statement `import`, but in C and C++ we would use the statement `#include` followed by the name of the library/header file [^header_files] which contains our functions of interest!



</details>







<details open>
<summary>

#### Solution

</summary>
<br> 

```c++
#include <iostream>

int main(){
    std::cout << "Hello World!";
}
```

</details>



---
We urge you to try to understand the error before reading the concepts related to the issue at hand to see if you can identify the problem. 

Before reading the solution/alternative code see if you can figure out what the intended behavior, and modify the code appropriately so it does what it ought to do.

    

## Compilation

Source Code →→

## Syntax

The computer **`can’t`** translate your source code into an executable file.

## Run-Time

The computer `**can**` translate your source code into an executable file.

The computer executes the program, but before it has finished* something `**fails**`

*** Sometimes a program will not give any indication that something has gone wrong. It will compile without warnings, it will execute, and it will gracefully exit. It is up to you as a programmer to be aware of the desired behavior of your code () ***




[^1]: If you use an import statement within the main section of your program, it will be available for the entire program like when you write `import os` at the beginning of the file. You can technically import within functions, so that there is a local scope to the imported functions.

[^lib]: Note that ANY PYTHON FILE can be imported, so you can import whatever file you want! On a similar note, have you wondered why we include `if __name__ == '__main__':` within our code? At a practical level, it has to do with how python imports modules - essentially, we want to differentiate from situations where we execute a file versus when we import the file and initialize it. Please watch the 4 minute video 'https://youtu.be/sugvnHA7ElY' if you're interested!

[^file_py]: These files are stored at `/usr/lib/python` if you want to have a look! (they may be distributed in different versions of python, feel free to take a look at them through vim!)

[^header_files]: These files are located in `/usr/include/`

[^scope]: "Function-definition scope. Scope is the location in a program where a name is visible and accessible" - Weber State University, Computer Science 1410 6.2.2 Functions and Variable Scope
