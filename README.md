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

We will deal primarily with the latter of the two situations. Our aim is to develop a basic understanding of the particularities of C / C++ within the context of your 2nd academic year, specifically what the error messages you'll encounter reveal about the code you’ve written and what concepts are useful you should understand to become a better debugger.

#### Format of this section:

`file_name.cpp`
```c++
// Some code in C or C++

#include <iostream>

int main(){
    cout << "Hello World!";
}
```

<details open>
<summary>

##### Compilation & Output

</summary>
<br>

```console
dbj@dbj:~$ g++ file_name.cpp -o file_name.x
file_name.cpp: In function ‘int main()’:
file_name.cpp:4:5: error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
    4 |     cout << "Hello World!";
      |     ^~~~
      |     std::cout
In file included from file_name.cpp:1:
/usr/include/c++/11/iostream:61:18: note: ‘std::cout’ declared here
   61 |   extern ostream cout;          /// Linked to standard output
      |                  ^~~~

```

</details>

<details open>
<summary>

##### Expected Compilation & Output

</summary>
<br> 
</details>

<details open>
<summary>

##### Concepts related to issue at hand

</summary>
<br> 
</details>

<details open>
<summary>

##### Solution

</summary>
<br> 
</details>




We urge you to try to understand the error before reading the concepts related to the issue at hand to see if you can identify the problem. 

Before reading the solution/alternative code see if you can figure out what the intended behavior, and modify the code appropriately so it does what it ought to do.

- ******************Knowledge******************
    
    > Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.
    > 
    > 
    > Brian W. Kernighan.
    > 

## Compilation

Source Code →→

## Syntax

The computer **`can’t`** translate your source code into an executable file.

## Run-Time

The computer `**can**` translate your source code into an executable file.

The computer executes the program, but before it has finished* something `**fails**`

* Sometimes a program will not give any indication that something has gone wrong. It will compile without warnings, it will execute, and it will gracefully exit. It is up to you as a programmer to be aware of the desired behavior of your code ()
