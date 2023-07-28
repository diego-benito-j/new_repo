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

We will deal primarily with the latter of the two situations. Our aim is to develop a basic understanding of the particularities of C / C++ within the context of your 2nd academic year, specifically what the error messages you'll encounter reveal about the code you’ve written and what concepts are useful to become a better debugger.

<details>
<summary>

#### Knowledge

</summary>
<br>
    > Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.
    > 
    > 
    > Brian W. Kernighan.
    > 
</details>

### Format of this section:

`file_name.cpp`
```c
// Some code in C or C++

int main(){
    cout << "Hello World!";
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
    2 |     cout << "Hello World!";
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
<br> 
</details>

**Namespace & Libraries & Scope**
You've probably written a python script importing some function/class from some library, where you've had to include a statement along the lines of `import sys` or `from sys import stdin`.

These statements were making the functions (in this case `stdin()` from module `sys`) available to you in the script you were writting[^1]. Essentially, the `import` statement ensured that whenever you wrote 'sys.stdin.readline()' or 'stdin.readline()', the python interpreter would. 

You were **including** a function called `readline` within the scope of your python script.

In C and C++, any operation that requires reading from standard input (stdin) or printing to standard output (stdout) will involve using a 

<details open>
<summary>

#### Solution

</summary>
<br> 
</details>




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




[^1] If you use an import statement within the main section of your program, it will be available for the entire program, but you can technically import within functions so that there is a local scope to the imported functions. In other words, writing `import sys` at the top of your python program means all
[^2] Technically python also initializes/executes the file/module whenever one uses `import module_name` which is why one includes `if __name__ == '__main__'` 
