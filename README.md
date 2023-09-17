# C / C++ errors and concepts

## Memory Allocation

Developing an understanding of how to store and manipulate information is one of 
our primary aims as programmers. Variables, pointers, references, functions
\- these are some of the ways we organize and manage data. Within the context 
of C / C++, we can begin to develop an understanding of how these abstract things 
behave by understanding how they are related to memory. 

Over the next academic year, you will become more intimately familiar with these 
concepts since you **will have to deal with the issues they present**.  This 
section will introduce some rudimentary concepts relating to memory (
contextualized in the framework of C / C++) to help you start developing
your own mental model of what is happening within your code.

### Variables, Declaration, Initialization, and Assignment

Amongst the code you've had to read / write in these sessions, you've been using
variables. Regardless of the programming language you are using, being able to 
name values so that you can modify and manipulate them is unbelivably useful.

Declaring, initializing, modifying, comparing, assigning - these are just some 
of the actions you've taken with the value(s) stored within the variables you 
have been using.
Since C / C++ are not memory safe, you have to be conscious of what it is
you are doing when you are declaring a variable, or when you are assigning
a value to it, or adding to it, etc...

So how should we conceptualize what we are doing? Lets first get familiar with 
**memory** as it relates to **declaration**, **initialization**, and 
**assignment**.

> **Note**
> From here on out we are not going to be pedantic. These descriptions
are simplified and abstracted away for the sake of clarity, not accuracy.

### Memory as it relates to variables

Memory can be thought of as a region of your computer capable of storing 
information. For our purposes, imagine a finite sequence of 0’s and 1’s.
When your program begins to execute, it is given some memory - some 0’s and 1’s 
it can use for its own temporary storage of information. 
Note that this memory already contains data which is just random
and not particularly useful.

![Representation of variable](graphical_assets/memory.JPG)

So we have places where we can store information, which leads us to the concept 
of **memory addresses**.  Your program can read and write onto the memory it has
 been given, and it will interpret the infromation stored there in whatever way 
you tell it to.

But the program needs to know where the information is located!

In the image above, we're referring to some particular bytes within some 
region in memory as 'Byte 1', 'Byte 2', [...], 'Byte 9' and we need something 
analogous to this so that the computer can identify which regions in memory to 
access.

Just like street addresses are some abstraction we use in the real world - a name
that corresponds to the location of a place - **memory locations** can be refered 
to via **addresses**!
This is known as a memory address, and its just what the name implies, a name for
a location in memory.

Whatever random data was held in memory before your program executes isn't
particularly useful for our purposes. 
If we want to store specific information - i.e if we want to store the value of
an integer, or a string of characters, or anything at all - we have to know 
where we're storing it. 

<details open>
<summary>

### Declaring a variable

</summary>
<br> 

When we declare a variable, we are associating whatever **name** we've 
provided with some **value**. Lets see an example:

```c++
int main(){
    int year;           // <--- Declaring a variable of type int
    year = 1342;        // <--- Assigning/Initializing the value of the variable
    return 0;
}
```

We are using the name `year` in our code to mean 'some integer I will 
reference as `year`' - in other words we are associating a **name** and 
a **value**. 
When this program is executed, this variable is simply the name we've given
to some region in memory - `year` is 
a custom name we've given to some memory location!


Lets visualize how we are **naming** a region in memory, and later on
we'll look at what **assigning a value to it** would look like given 
the following code:

```c++
int main(){
    char a[4];      // <- visual aid represents this line
    a = "yes";
    return 0;
}
```

![Declaration of memory](graphical_assets/declaration.JPG)

Note that there already is data inside of `a`. Where did it come from?




</details>


### Initializing and assigning data to a variable

We've declared a variable, in turn the compiler has allocated as much memory as
we've specified or as much memory as is default. In our case, we've specified 
that `a` is an array of 4 chars (meaning each `block` contains 1 byte since
chars have that size ) 
ergo 4 bytes will be allocated to variable `a`

We would say that this region in memory is uninitialized because the compiler
has simply associated a user defined variable name with a memory region. We
now have to write onto that region in memory by initializing/assigning a value
onto our variable - otherwise we'll just have whatever garbage value/random bits 
were previously held in those memory locations (foreshadowing).

<details>
<summary>

#### What would happen if we printed the contents of `a` before it is initialized?

</summary>
<br> 

Try it! Create an empty string and print its content. You will get a random set 
of characters, maybe a few of these '�' will appear because the compiler 
interprets the bytes in `a[i]` as characters result in an "an unknown, 
unrecognised, or unrepresentable character".

</details>

To reiterate, **C / C++ do not have default values they assign to your variables
whenever you declare them**. You need to initialize them.
In other words, this code in C++ has **undefined behaviour** because the value 
of `a` will not always be the same:

```c++
#include <iostream>
int main() {
    int a;
    a = a + 5;
    cout << a << endl;
    return 0;
}
```

Meanwhile this Python code does have defined behaviour because the value of 
`a` will always start of as 0

```python
def main():
   a = int() 
   print( a )

if __name__ == "__main__":
    main()
```

Although the python example might seem a little contrived (one wouldn't 
typically initialize an integer that way), it highlights the idea that 
the code written in C++ or the analogous version in C do not initialize
variables for you.
So how could we conceive of the act of initialization/assignment?


Well, a starting point would be the **rewriting of that region of memory** with 
some value that was either input or hard coded into our code.

Consider the following visual aid that follows from the declaration of variable
`a` :

```c++
int main(){
    char a[4];
    a = "yes";      // <- visual aid represents this line
    return 0;
}
```

![Assignment/Initialization](graphical_assets/assignment.jpg)

#### Why do I have to care about type? Why isn't it like Python?

The following is a perfectly reasonable thing to do in Python:

```python
a = None
a = ['this', 'is', 'really', 'useful']
a = 5
```

But this isn't the case in C or C++, we can't reassign variables so readily
because we are workingin a statically typed language. Python automatically 
manages memory by reclaiming objects that are no longer in use. In contrast, C/
C++ generally requires manual memory management, giving more control to the 
programmer (but also increasing the risk of memory-related errors!) because 
the 'garbage collection' must be considered by the programmers themselves. 

Statically-typed languages like C/C++ offer performance benefits in part 
because they do not need to spend time managing memory through a garbage 
collector, with the added benefit of early error detection due to type safety 
since the data type *will be set at compile-time*. Dynamically-typed languages 
like Python provide greater flexibility, so the trade-off is up to you as a 
programmer!


### Datatypes and Casting

At this point, it should be abundantly clear: we are working with data stored
in memory. Memory is just some assortment of bytes that we write to and read
from **in a particular way**. This 'particular way' in which we read and write 
data in memory is what determines the **value** of the data.


`string_datatype.c`

```c
#include <stdio.h>

int main() {
    char a[] = "yes";
    int  b[] = {121, 101, 115};
    
    for ( int i = 0; i < 4; i++ ){
        printf( "block %i char a: %c\n", i, a[i] );
        printf( "block %i char b: %c\n", i, b[i] );

        printf( "block %i int a: %i\n", i, a[i] );
        printf( "block %i int b: %i\n", i, b[i] );
        
        printf("\n");

    }

    return 0;
}
```

Pay special attention to how we are printing things. We are using format 
specifiers, '%c' and '%i', ostensibly saying "interpret whatever is in 
`variable_name[i]` as a **name_of_datatype**". 

These format specifiers are a good demonstration of how one datatype relates 
to another. When you use %c for an int, you are telling the program to interpret 
the data (whatever is located in `a[i]` and `b[i]` - see line 7 & 8) as if it 
were a `char` (see [ASCII table](https://www.asciitable.com/)).  **Note that 
the underlying data isn't changed; what changes is how it's interpreted.** 

Casting extends this idea of **interpret the data in some manner** beyond the 
act of printing. This can be dangerous if not done carefully as you risk 
misinterpreting your data. This may lead to bugs that can be difficult to 
diagnose. A very pertinent example of how datatypes & casting matter is when 
operating on floats and integers. The set of operations that they can do 
together might become a problematic! 

Consider the following situation where we want to calculate the ratio between 
two integers. For the sake of example, imagine we were comparing the distances
between two pairs of atoms like those you would find in a .pdb file.


`distance.cpp`

```c++
#include <iostream>

using namespace std;

int main() {
    int distance1 = 1;
    int distance2 = 100;
    float ratio;

    // Incorrect calculation: integer division truncates result to zero
    ratio = distance1 / distance2;
    cout << "Incorrect ratio: " << ratio << endl;       // <-- prints 0

    // Correct calculation: type casting before division
    ratio = (float) distance1  / distance2;
    cout << "Correct ratio: " << ratio << endl;         // <-- print 0.01

    return 0;
}
```

```console
dbj@dbj:~$ g++ distance.cpp -o distance.x
dbj@dbj:~$ ./distance.x
Incorrect ratio: 0
Correct ratio: 0.01
```

As we can see, the division between integers results in an integer itself, 
which 'truncates' the result to 0 thereby generating an incorrect result. By 
casting one of the integers as a float (`(float) distance1 `) we 
can resolve this issue in a really straightforward manner! Note that no error 
is raised **because the division between integers returning an integer is 
perfectly valid behaviour**, we just have to understand that behaviour!

<details>
<summary>

#### What is variable_name[i]? 

</summary>
<br> 
As a reminder, indexing some variable like `variable_name[i]` will return
the value of the i'th block of `variable_name`. Note that we are saying 
the **value**, we are not (nor should we) deal with raw bytes.


`b[i]` will be 4\*i bytes away from `b[0]` where the 0s and 1s for each block 
of bytes are representing an integer

`a[i]` will be 1\*i bytes  away from `a[0]` where the 0s and 1s for each block 
are representing a char

</details>


### Buffer Overflow

If you ever feel confused by what something means, look at the definition.

This is especially pertinent in computer science **because things have names for
a reason**. 

> Buffer: "a section of computer memory for temporarily storing information" 
> Overflow: "to flow over the brim of" 

Buffer Overflow refers to the phenomena where data that was supposed to reside
in a region of computer memory overflows into adjacent memory. Lets look at an
example to see why **understanding how memory works helps us understand 
unexpected behaviour**

Lets consider the follwing code:

`char_arr.c`

```c
#include <stdio.h>

int main() {
    char j[2] = "jjj" ;

        printf( j );
        printf("\n");

        for ( int i = 0; i < 6; i++ ){
            printf( "%i \n", j[i] );
        }
        printf("\n");

    char b[3] = "bbb";

        printf( b );
        printf("\n");

        for ( int i = 0; i < 6; i++ ){
            printf( "%i\n", j[i] );
        }
        printf("\n");

    j[3] = 'j';                             // <-- THIS SHOULD NOT BE MODIFYING b
        
        printf( b );
        printf("\n");

        for ( int i = 0; i < 6; i++ ){
            printf( "%i\n", j[i] );
        }
        printf("\n");

    return 0;
}
```

This code results in the following:

```console
dbj@dbj:~/new_repo/code_snippets$ gcc char_arr.c -o char_arr.x

    ERRORS NOT RELEVANT 
    FOR THE PURPOSES
    OF THIS EXAMPLE

dbj@dbj:~/new_repo/code_snippets$ ./char_arr.x 
jj
106 
106 
0 
0 
0 
0 

bbb
106
106
98
98
98
0

bjb
106
106
98
106
98
0

dbj@dbj:~/new_repo/code_snippets$
```

There are three things to higlight with this example (see image for more context):

![Overflow](graphical_assets/overflow_shown.jpeg)

First, notice that our code is printing from j[0] to j[6] - since `j` and `b` 
are adjacent to each other, we see their contents (interpreted as integers) in 
each of the for loops.

Second, notice that our first initialization of `j` assigned the string "jjj",
but when we print the contents of `j` we only get "jj" and when print the 
bytes from j[0 .. 6] only the first two seem to have been assigned. As shown 
in the image, only j[0] and j[1] are regions of memory that the compiler has 
dedicated to our `j` string variable, this is because we declared `j` to be a 
string of length 2 as seen by the first declaration `char j[2];`. Thus, there 
is no assurances that the third position (corresponding to j[2]) would contain 
whatever value it was assigned.

Third, notice that after executing line `j[3] = 'j'` we see that `b` has 
changed from "bbb" to "bjb" where `b[1]` was modified. This is buffer overflow
! We've managed to flow over the limits of `j` into a region of memory that 
belongs to `b` where j[3] corresponds to b[1]. This demonstrates the that you 
have full autonomy over how memory is used within your program, and should 
serve as a reminder that variables are just pointing to some region in 
memory.


If you edit this code so that it prints out `j` after `b` has been initialized
, why doesn't it print `"jj"`? Why does it print out `"jjbjb"`?

Remember that `char arrays` are delimited by `null` characters. When you try 
to print out the contents of `j`, the `printf` function is going to interpret 
each byte from `j[0]` onwards as a char **until it finds a `null char` **. 
Since it doesn't find a `null char`, it simply keeps on printing, and the 
contents of `b` is right next to the contents of `j`, so we see `"jjbjb"`!

You should also consider that here isn't any assurances that printing `j` will 
result in `"jj"`, even before `b` is declared! Only two bytes have been 
allocated to `j`, when we would actually need an array of size 3 to hold the 
`null char` that delimits the end of `j`. In other words, if we don't
indicate the termination of the char array, or if we overshoot (`j` cannot
hold more than 2 chars, and yet we initialize it as "jjj") then we will
get **undefined behaviour**!


## Pass by Reference vs. Pass by value

One of the most effective ways to speed up our programs is by considering how 
and when our program accesses the devices memory. We want to minimize the 
amount of information that we need to read/write (or worse still, fetch from 
secondary memory) because it is a computationally expensive thing to do.

Lets see a rudimentary example in Python and C++ to understand why effective 
memory usage can make or break the efficiency of a program.

Consider some code that resolves the following problem.
`Generate the reverse complement of a DNA sequence from start codon to end codon.` 

> If no coding sequence is present, print 'No coding seq found'.
> Input will be a non-empty string, if a start codon is present an end codon 
will be present in the appropriate reading frame`

```python
from sys import stdin

def rev_complement( inp_string ):
    rev_comp = ""
    print( inp_string )
    comp = dict()
    comp['A'] = 'T'
    comp['C'] = 'G'
    comp['T'] = 'A'
    comp['G'] = 'C'
    
    for nucleotide in inp_string[::-1]:
        rev_comp += comp[nucleotide]
    
    return( rev_comp ) 
         
def main():
    print('Input DNA seq')
    initial_seq = stdin.readline().strip()
    rev_comp = rev_complement( initial_seq )
    print( f'The reverse complement is "{rev_comp}"' )



if __name__ == '__main__':
    main()
```




```c++
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

string reverseComplement( string input_seq );

int main(){
    string seq;
    string reversed_seq;

    cout << "Input DNA seq" << endl ;
    cin >> seq;
    reversed_seq = reverseComplement( seq );
    cout << "The reverse complemnt is " << reversed_seq << endl;

    return 0;
}

string reverseComplement( string input_seq ) {
    map< char , char > complement;

    complement[ 'A' ] = 'T';
    complement[ 'T' ] = 'A';
    complement[ 'C' ] = 'G';
    complement[ 'G' ] = 'C';

    string reverseStr;

    for (int i = 0; i < input_seq.length(); i++){
        reverseStr += complement[ input_seq[ i ] ];
    }

    reverse( reverseStr.begin(), reverseStr.end() );

    return( reverseStr );
}
```

We want to highlight two issues with this implementation. 

First and foremost, notice that we are storing some input into a variable of 
type string (`seq`). Then, we invoke the `reverseComplement` function by calling
`reverseComplement( seq );`. 

This is an example of variable passing (i.e argument passing) known as `Pass By Value` 

The parameter of function `reverseComplement` is a string datatype, and we are 
'passing' data by calling the function with some value 
`reverseComplement( some_value )` - in our case, some_value is string `seq`. 
Calling this function which receives the value of variable `seq` will declare a 
new variable ( reverseComplement's `input_seq`) and it will initialize this 
variable with the value that was passed as argument in the function call. This 
variable is only available within the scope of the funciton
[^stack_function_frames] and will no longer exist after the function call is
terminated. 

We are declaring a variable of the same type, initializing it with the same
value, available within the scope of the function - we are making a copy!

And that's the problem, sometimes we might generate the appropriate 
results without requiring a copy of the data to be passed into a funciton.
This is where we get to the wonderful world of pointers, and references!

As you already know, variables are just names that indicate where some 
memory is, and how it should be interpreted by default. So, instead of making 
a copy of the value of some variable, we could instead just indicate where the 
value of the variable is located (i.e we can just pass the memory address).

This is where `references` and `pointers` come in handy.

#### References & Pointers

When you pass a parameter by value, like `seq` in `reverseComplement(seq)`, the 
function creates an internal copy of that parameter. This is a separate 
instance that has the same value as the original variable `seq` but is 
completely independent of it. Any changes you make inside the function will 
not affect the original variable `seq`. This can be inefficient for large data 
structures because it involves copying all the data.

Pointers are a datatype that do **precisely what their name suggests**. They 
literally "point" to a location in memory. A pointer stores the memory address 
of another variable. For example, if you have variable `seq`, then a pointer 
`ptr_to_seq` could hold the memory address of `seq`. This pointer can then be 
passed to a function, which can be dereferenced to access or modify the 
original variable `seq`.

References are like nicknames or aliases for a pre-existing variable. When you 
declare a reference, you're saying, "I want to refer to this memory location 
using another name." From that point on, both the original variable and the 
reference can be used interchangeably. This also means that if you modify the 
reference, you are in essence modifying the original variable.

> **Note**
> In an expression, `&` denotes the address-of operator, which returns the 
address of a variable.
> When `&` is used in a declaration (including function formal parameters), it 
is part of the type identifier and is used to declare a reference variable (or 
reference or alias or alternate name). It is used to provide another name, or 
another reference, or alias to an existing variable.


If you hadn't notice, python already treats most objects as references!

```console
>>> a = [ 1, 2, 3, 4 ]
>>> def foo( some_input_parameter ):
...     some_input_parameter[3] = 'this element is different now'
...
>>> foo( a )
```

What is the contents of `a` after calling `foo(a)`?


##### Why is Pass by Value Default?

In essence, because that default behaviour prevents unintended modifications to
original values and simplifies memory management. Additionally, pass by value is
generally more efficient than pass by reference when copying small-sized 
datatypes.

So, we can rewrite the original code as follows, which will prevent our string 
from being copied EVERY TIME THE FUNCTION IS CALLED because instead of passing 
the value of the variable, we are passing the value of the reference:

```c++
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

string reverseComplement( string & input_seq ); // <-- Notice the & symbol indicating pass-by-reference!

int main(){
    string seq;
    string reversed_seq;

    cout << "Input DNA seq" << endl ;
    cin >> seq;
    reversed_seq = reverseComplement( seq );
    cout << "The reverse complemnt is " << reversed_seq << endl;
    
    return 0;
}

string reverseComplement( string & input_seq ) {
    map< char , char > complement;

    complement[ 'A' ] = 'T';
    complement[ 'T' ] = 'A';
    complement[ 'C' ] = 'G';
    complement[ 'G' ] = 'C';

    string reverseStr;

    for (int i = 0; i < input_seq.length(); i++){
        reverseStr += complement[ input_seq[ i ] ];
    }

    reverse( reverseStr.begin(), reverseStr.end() );

    return( reverseStr );
}

```

Lets see a very basic model that could be helpful. Consider a function 
`foo( param_a )` that receives some string and returns its length. The 
following would correspond to the sequence of steps that would transpire if 
we used pass by value:


![Pass by Value](graphical_assets/pass_by_value.JPG)

On the other hand, we could conceptualize what is happening when we pass by 
reference as follows:


![Pass by Reference](graphical_assets/pass_by_ref.JPG)

As we can see, the latter does not have to spend as much time copying each 
element of string `a` into `foo`'s private copy, and therefore would be more 
**time** efficient. Efficient **memory** usage is also a benefit, since we do
not need to allocate more memory than necessary!


> **Note**
>  These images are not intended to be an accurate representation of how memory 
is allocated, but rather provide some intuition as to why copying things when it
 isn't necessary wastes precious resources. Rember that each time things are 
being copied, those are CPU cycles that are being used to copy that data. So 
remember that your choices matter - if you use pass by value or pass by 
reference, it will have consequences on how your programs run!


Now that you have a general mental model on what pass-by-reference implies, lets 
actually compare the time taken by two functions.


`timing_pass_by_ref-val.x`

```c++
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Pass-by-value function
void processByValue(vector<int> data) {
                                                        // Nothing is being done!      
}

// Pass-by-reference function
void processByReference(vector<int>& data) {
                                                        // Nothing is being done!      
}

int main() {
    vector<int> largeData(1e6, 33);  // 1 million integers initialized to 33

    // Timing the pass-by-value function
    auto start = chrono::high_resolution_clock::now();
    processByValue(largeData);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by pass-by-value: " << duration.count() << " microseconds" << endl;


    // Timing the pass-by-reference function
    start = chrono::high_resolution_clock::now();
    processByReference(largeData);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by pass-by-reference: " << duration.count() << " microseconds" << endl;

    return 0;
}

```

```console
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ g++ timing_pass_by_ref-val.cpp -o timing_pass_by_ref-val.x
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ ./timing_pass_by_ref-val.x 
Time taken by pass-by-value: 2386 microseconds
Time taken by pass-by-reference: 0 microseconds
```

What happens if instead of a very large vector `largeData(1e6, 33);` we had a 
smaller vector (e.g `largeData(100, 45)` ), but called the functions multiple 
times? Will the difference in execution be significant?



# Handling Errors

Ideally, programming would require little more than a problem, some ingenuity 
in figuring out how to solve it, and writing out some code that does what it 
ought to do to solve the issue at hand. 

It is on this statement - “does what it ought to do” - that most difficulties 
in implementation arise. We typically believe we know what the intended 
behavior is way sooner than we should.

Before we enter the minutia of how to interpret and understand errors within 
the context of C / C++, you should consider that the hardships of making 
something do what it ought to do typically emerge from one of the following:

- You have misunderstood the nature of the problem
- You have misunderstood the nature of your solution

We will deal primarily with the latter of the two situations. Our aim is to 
develop a basic understanding of the particularities of C / C++ within the 
context of your 2nd academic year, specifically what the error messages you'll 
encounter reveal about the code you’ve written and what concepts are useful to 
become better debuggers.

<p align="center"><i>
"Debugging is twice as hard as writing the code in the first place. Therefore, 
if you write the code as cleverly as possible, you are, by definition, not 
smart enough to debug it."
</i></p>
<p align="right"> - Brain W. Kernighan</p>


### Types of Errors

For our purposes, we want to highlight two categories of errors: compile-time 
errors and run-time errors.

> Compile-time Errors:
> Occur during the compilation of your code (i.e., when you try to convert your 
source code into machine code).
> Examples: syntax errors, undeclared variables, type mismatches, and other 
violations of the language's grammar or semantics. These errors are detected by 
the compiler and must be corrected before the program can be successfully compiled.


> Run-time Errors:
> Occur when the program is actually running.
> Even if your code compiles successfully, it may still contain errors that only 
manifest when the code is executed.
> Examples: division by zero, attempting to access a null reference, or trying 
to access an out-of-bounds array element.  These errors can be harder to debug 
because they depend on specific conditions that arise during execution.

<details>
<summary>

#### Other Relevant Errors

</summary>
<br> 

##### Logical Errors:

Your code compiles and runs without throwing any errors, but it doesn’t 
produce the expected outcome. This can be due to flaws in the algorithm or 
misunderstandings about the problem requirements.
Examples: incorrect formulas, incorrect conditions in "if" statements, or 
loops that don't iterate the expected number of times.

##### Semantic Errors:

Your code might be syntactically correct, but it doesn't make sense in terms 
of the programming language's semantics.
Example: In some languages, comparing a string with an integer might be 
syntactically correct, but it may not have a meaningful semantic interpretation.

##### Linker Errors:

After compiling individual program units, they need to be linked together into 
a single executable. Errors during this phase are linker errors.
Examples: Missing function implementations, multiple definitions of a function
, or unresolved external references.

##### Runtime Warnings:

These are not necessarily errors, but are situations the runtime feels it's 
necessary to bring to the developer's attention. They may indicate potential 
problems or deprecated usage.

</details>



```c++
#include <iostream>

int main(){
    std::cout << "Hello World!" << endl;
    return 0;
}
```

</details>


### Practical Section on Error Handling - Format:

`file_name.cpp`

```c
// Some code in C or C++

int main(){
    cout << "Hello World!" << endl;
    return 0;
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
    2 |     cout << "Hello World!" << endl;;
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

##### Libraries & Scope

You've probably written a python program importing some function/class from 
some library[^lib], where you've had to include a statement along the lines of 
`import sys` or `from sys import stdin`.

These statements are making whatever functions you specify **visible and 
accessible** within your program - which is another way of saying that 
you are including the functions within the global **scope** [^scope] of your 
program. In this particular case, the `import` statement ensures that whenever 
the python interpreter reads `sys.stdin.readline()` or `stdin.readline()`, it 
**knows what the function `readline()` is** becuase you've specified where the 
function is defined (some module called sys). 

You are **including** all functions associated to the module sys within the 
scope of your python script, importing them from some file in your 
computer[^file_py].

In C and C++, any operation that requires reading from standard input (stdin) 
or printing to standard output (stdout) requires the use of an external 
library (**no `print()` nor `input()` without any imports like in python!**). 

In our case, we are using `cout`, which is part of the `iostream` library. In 
python we used the statement `import`, but in C and C++ we would use the 
statement `#include` followed by the name of the library/header file 
[^header_files] which contains our functions of interest!

Remember, importing/including simply gives you 
**access to some already existing repository of code**.



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

We urge you to try to understand the error before reading the concepts related 
to the issue at hand to see if you can identify the problem. 

Before reading the solution/alternative code see if you can figure out what 
the intended behavior, and modify the code appropriately so it does what it 
ought to do.

    
## Compile-Time

The computer **can’t** translate your source code into an executable file.


`data_type.cpp`

```c++
#include <iostream>

int main() {
    char myChar = "a"; 

    std::cout << myChar << std::endl;

    return 0;
}

```

<details>
<summary>

#### Compilation & Output

</summary>
<br>

```console
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ g++ data_type.cpp -o data_type.x
data_type.cpp: In function ‘int main()’:
data_type.cpp:4:19: error: invalid conversion from ‘const char*’ to ‘char’ [-fpermissive]
    4 |     char myChar = "a";
      |                   ^~~
      |                   |
      |                   const char*
```

</details>

<details>
<summary>

#### Expected Compilation & Output

</summary>
<br> 

```console
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ g++ data_type.cpp -o data_type.x
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ ./data_type.x 
a
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ 
```

</details>


<details>
<summary>

#### Concepts related to issue at hand

</summary>




##### Conversion from one data type to another


`C++` does not allow us to assign a string literal to a char. In other words, 
the missmatch in data types results in a compilation `error` because the 
compiler cannot convert our code into an executable since it doesn't know what 
to do here!

The use of " and ' signify different things. `""` implies that whatever is in 
between these double-quotes should be interpreted as a string literal (i.e 
some array of chars). `''` implies that whatever is inbetween these single-
quotes should be interpreted as an individual char.  When we declare myChar as 
a char, not an array of chars, we get a compile-time error since C++ fails to 
convert (`invalid conversion`) the array of chars it expected 
(`from ´const char\*´ `) to the data type `myChar` was declared as (`char`). 


</details>

<details>
<summary>

#### Solution

</summary>
<br> 

```c++
#include <iostream>

int main() {
    char myChar = 'a';
    
    std::cout << myChar << std::endl;

    return 0;
}

```

</details>


Now lets look at a larger piece of code, and lets try to figure out the errors 
at hand.

`reverse_string.cpp`

```c++
#include <algorithm>
#include <iostream>
#include <string>

using namespace std; 

string reverse( string & input_seq );    

int main(){
    string seq; 
    string reversed_seq; 

    cout << "Input DNA seq" << endl;
    cin >> seq;
    reversed_seq = reverse( seq );
    cout << "The reverse complemnt is " << reversed_seq << endl 

}

string reverse( string input_seq ) { 		
    map< char , char > complement;
    
    complement[ "A" ] = "T";    
    complement[ "T" ] = "A";    
    complement[ "C" ] = "G";    
    complement[ "G" ] = "C";    

    string reverseStr;
    
    for (int i = 0, i < input_seq.length(), i++){       
        reverseStr += complement[ input_seq[ i ] ];
    }
    
    reverse( reverseStr.begin(), reverseStr.end() ); 

    return( reverseStr ); 
}

```

<details>
<summary>

#### Compilation & Output

</summary>
<br>
The output has been cleaned up a bit for clarity!

```console
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ g++ reverse_string.cpp -o reverse_string.x
reverse_string.cpp: In function ‘int main()’:
reverse_string.cpp:17:66: error: expected ‘;’ before ‘}’ token
   17 |      cout << "The reverse complemnt is " << reversed_seq << endl
      |                                                                ^
reverse_string.cpp: In function ‘std::string reverse(std::string)’:
reverse_string.cpp:24:15: error: ambiguous overload for ‘operator[]’ (operand types are ‘std::map<char, char>’ and ‘const char [2]’)
   24 |     complement[ "A" ] = "T";
      |               ^
reverse_string.cpp:24:17: error: invalid conversion from ‘const char*’ to ‘std::map<char, char>::key_type’ {aka ‘char’} [-fpermissive]
   24 |     complement[ "A" ] = "T";
   25 |     complement[ "T" ] = "A";
   26 |     complement[ "C" ] = "G";
   27 |     complement[ "G" ] = "C";
      |                 ^~~
      |                 |
      |                 const char*

reverse_string.cpp:17:66: error: expected ‘;’ before ‘}’ token
   17 |      cout << "The reverse complemnt is " << reversed_seq << endl
      |                                                                 ^
      |                                                                 ;
   18 | 
   19 | }
      | ~                                                                 

reverse_string.cpp:22:5: error: ‘map’ was not declared in this scope
   22 |     map< char , char > complement;
      |     ^~~

reverse_string.cpp:22:10: error: expected primary-expression before ‘char’
   22 |     map< char , char > complement;
      |          ^~~~
reverse_string.cpp:24:5: error: ‘complement’ was not declared in this scope
   24 |     complement[ "A" ] = "T";
      |     ^~~~~~~~~~
reverse_string.cpp:31:22: error: expected ‘;’ before ‘<’ token
   31 |     for (int i = 0, i < input_seq.length(), i++){
      |                      ^~
      |                      ;
reverse_string.cpp:31:23: error: expected primary-expression before ‘<’ token
   31 |     for (int i = 0, i < input_seq.length(), i++){
      |                       ^
reverse_string.cpp:31:48: error: expected ‘;’ before ‘)’ token
   31 |     for (int i = 0, i < input_seq.length(), i++){
      |                                                ^
      |                                                ;

```

</details>

<details>
<summary>

#### Expected Compilation & Output

</summary>
<br> 

```console
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ g++ reverse_string_solution.cpp -o reverse_s
tring_solution.x                                                                             
dbj@dbj:~/laPrepa/concepts_errors/code_snippets$ ./reverse_string_solution.x                 
Input DNA seq                                                                                
TTTTTTAA                                                                                     
The reverse complemnt is "TTAAAAAA"
```

</details>


<details>
<summary>

#### Concepts related to issue at hand

</summary>

##### Inclusion of headers

Whenever we use objects that are found in the standard library, but require 
the inclusion of a header file, it is imperative you include it and convention 
is to include them at the top of your file. Otherwise, you will be writing 
code expecting the compiler to know what `reverse()` is, but since that 
function was not declared it will raise an error. Sometimes the compiler will 
inform you with a "did you forget to ‘#include <map>’?" but you shouldn't rely 
on the compiler's awareness of whatever libraries you are using!

##### Data Types

As we saw before, `"` will correspond to string literal/char array and `'` 
will correspond with chars. The inconsistency between the complement map we 
declared (`map< char, char > complement`) and our initialization/assignment 
operations raises an error!


##### Namespace Clashes

A function declaration informs the compiler about the function's name, return 
type, and parameters. This becomes a problem if we have two functions with the 
same name, which definition/implementation should the compiler use?

In C++ it's quite straightforward: you can't have two functions with the same 
name AND the same parameters. But a dangerous feature known as overloading 
exists, which is why our program can have a function called `reverse` and the 
`std::reverse` within the same script.

Although it hasn't raised an error, it is highly recommended that you leave 
the names of standard functions as they are. Thus, instead of `string reverse` 
it would probably be a good idea to name the function 
`string reverseComplement` or something you feel is even more intuitive!

##### Consistency in Declaration

If you declare a function before your main, and then proceed with the 
implementation of that function later on in your program, you have to make 
sure their parameters match. Otherwise we get to the afformentioned problem of 
"which is the appropriate definition of this function". In this case, we 
should notice that the original declaration of `string reverse(...)` expects a 
reference as a parameter, whilst the second declaration expects a string as a 
parameter. We have to be consistent!

Also consider, which should we choose in this case? Pass-by-value or 
pass-by-reference?


</details>


<details>
<summary>

#### Hints

</summary>
<br> 

```c++
#include <algorithm>
#include <iostream>
#include <string>
                                        // missing something

using namespace std;

string reverse( string & input_seq );    // IGNORE FOR NOW (function overloading)

int main(){
    string seq;
    string reversed_seq;

    cout << "Input DNA seq\n" ;
    cin >> seq;
    reversed_seq = reverse( seq );
    cout << "The reverse complemnt is " << reversed_seq << endl     // <-- missing something

}

string reverse( string input_seq ) { 		// <-- pass by ref or pass by value?
    map< char , char > complement;

    complement[ "A" ] = "T";    //  <-- map should be from char to char
    complement[ "T" ] = "A";    //  <-- map should be from char to char
    complement[ "C" ] = "G";    //  <-- map should be from char to char
    complement[ "G" ] = "C";    //  <-- map should be from char to char

    string reverseStr;

    for (int i = 0, i < input_seq.length(), i++){       // <-- incorrect separator for (`init`;`condition`;`increment`)
        reverseStr += complement[ input_seq[ i ] ];
    }

    reverse( reverseStr.begin(), reverseStr.end() );

    return( reverseStr );
}
```

</details>

<details>
<summary>

#### Solution

</summary>
<br> 

```c++
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std; 

string reverseComplement( string & input_seq ); 

int main(){
    string seq; 
    string reversed_seq; 

    cout << "Input DNA seq" << endl;
    cin >> seq;
    reversed_seq = reverseComplement( seq );
    cout << "The reverse complemnt is " << reversed_seq << endl;

}

string reverseComplement( string & input_seq ) {
    map< char , char > complement;
    
    complement[ 'A' ] = 'T';
    complement[ 'T' ] = 'A';
    complement[ 'C' ] = 'G';
    complement[ 'G' ] = 'C';

    string reverseStr;
    
    for (int i = 0; i < input_seq.length(); i++){
        reverseStr += complement[ input_seq[ i ] ];
    }
    
    reverse( reverseStr.begin(), reverseStr.end() ); 

    return( reverseStr ); 
}

```

</details>



## Run-Time Errors

The computer **can** translate your source code into an executable file. The 
computer executes the program, but before it has finished something **fails**.

We've provided an example that works for most cases, but fails in particular 
string inputs. Could you figure out which?

`GC_content.cpp`

```c++
#include <iostream>
#include <string>

using namespace std;

float calculate_gc_content(string& sequence) {
    int gc_count = 0;
    int total_sequence = 0;

    for ( int i = 0; i < sequence.length(); i++) {
        if (sequence[i] == 'G' || sequence[i] == 'C') {
            gc_count++;
        }
        if (sequence[i] == 'G' || sequence[i] == 'C' || sequence[i] == 'A' || sequence[i] == 'T') {
            total_sequence++;
        }
    }

    // G's and C's present, prevent truncation from integer division
    if (gc_count != 0) {
        return (float) gc_count / total_sequence; 
    }
    
    // G's and C's not present, meaning truncation is not a problem
    return gc_count / total_sequence;
}


int main() {
    string dna_sequence = "AATGCGGG";
    float gc_content = calculate_gc_content(dna_sequence);
    cout << "GC content: " << gc_content << endl;
    return 0;
}

```

The output of 'AATGCGGG' which is hard-coded into the code will be the following:

```console
dbj@dbj:~/new_repo/code_snippets$ g++ GC_content.cpp -o GC_content.x
dbj@dbj:~/new_repo/code_snippets$ ./GC_content.x 
GC content: 0.625
```
<details>

<summary>

#### Hint

</summary>
<br> 

Try an empty string by modifying the input to the function, what will happen?
Just modify `string dna_sequence = "AATGCGGG";`, or even better make the
program read from `stdin` via `cin` so that you can test real-time inputs!


* Also consider the following:
	*	Is the second `if` necessary?
	*	Do I need to check if each char is ATCG?
	*	Do I know the sequence length before hand?





</details>


<details>

<summary>

#### Concepts related to issue at hand

</summary>
<br> 

Yes! It's a 'division by zero' error. Since 0 / 0 is not a valid floating 
point operation, an aptly named floating point exception error has occured! 
Again, you are not supposed to know this, but a quick google search (literally 
copying and pasting "Floating point exception (core dumped)" into a search 
engine) reveals that these errors are related to invalid operations that are 
done on floating point numbers.


```console
dbj@dbj:~/new_repo/code_snippets$ g++ GC_content.cpp -o GC_content.x
dbj@dbj:~/new_repo/code_snippets$ ./GC_content.x 
Floating point exception (core dumped)
```

What would be a solution to this floating point exception? 

</details>

<details>
<summary>

#### Solution

</summary>
<br>

One possibility would be to simply check whether the sequence is of non-zero
length before we enter the body of the function.


```c++
#include <iostream>
#include <string>

using namespace std;

float calculate_gc_content(string& sequence) {
    if (sequence.length() == 0){                   // check size!
        return 0; 
    }

    int gc_count = 0;
    int total_sequence = 0;

    for ( int i = 0; i < sequence.length(); i++) {
        if (sequence[i] == 'G' || sequence[i] == 'C') {
            gc_count++;
        }                                          // removed redundnat `if`
    }

    return gc_count / sequence.length();           // using sequence.length()
}

int main() {
    
    string dna_sequence = "";                      // works with empty str

    float gc_content = calculate_gc_content(dna_sequence);
    cout << "GC content: " << gc_content << endl;

    return 0;
}

```

</details>


### Semantic Errors

Sometimes a program will not give any indication that something has gone wrong.
It will compile without warnings, it will execute, and it will gracefully exit.
It is up to you as a programmer to be aware of the desired behavior of your code.

Try to *find the error in the following code* snippet, deducing what the 
intended behaviour of the function was from its name.


`G_content.cpp`

```c++

#include <iostream>
#include <string>

using namespace std;

int calculate_G_content( string dna ){ 
    
    int g_count = 0;
    for ( int i = 0; i < dna.length(); i++ ) {
        if ( dna[i] = 'G' ) g_count++;
    }
    return( g_count ); 
    }

int main() {
    string dna = "ATGCGTAA";
    int g_content = calculate_G_content(dna);
    cout << "Guanine's observed: " << g_content << endl;
    return 0;
}

```
<details>
<summary>

#### Hint

</summary>
<br>


Did you catch it? We are trying to count the number of 'G' chars in a string, 
but we seem to be overshooting and counting every char as if it were 'G'. 
The problematic line is `if ( dna[i] = 'G' )` but could you tell us why?

</details>

<details>
<summary>

#### Concepts related to issue at hand

</summary>
<br>

In c++, the assignment operation returns the value of 
the thing being assigned. For example:

`example_assignment_nonzero.cpp`

```c++
    #include <string>
    #include <iostream>
    
    using namespace std;
    
    int main(){
        int i;
        cout << (i = 22) << endl; 
    
        string dna = "AAT";
        cout << ( dna[1] = 'r' ) << endl;

        return 0;
    }
```

When this code is compiled and executed, the following occurs:

```console
dbj@dbj:~/new_repo$ g++ example_assignment_nonzero.cpp -o example_assignment_nonzero.x -Wall
dbj@dbj:~/new_repo$ ./example_assignment_nonzero.x 
22
r
```

As we can see, the assignment operation simply returns the value of whatever 
is being assigned. Remember that 0 is false and everything else is true. 
So what happens if instead of writting `==` we write `=` inside of a 
conditional?


</details>

<details>
<summary>

#### Solution

</summary>
<br>

The reason why `if ( dna[i] = 'G' )` is problematic is because we are using `=`
instead of `==` here. When the program is executed, this line of code seems
perfectly reasonable to the compiler. When we evaluate `if ( dna[i] = 'G' )`
it's as if we are evaluating `'if 'G'`. The `if` statement is true because the
`char` 'G' is non-zero (check an ascii table if you're curious what value it 
actually has, or maybe print it as an integer!).

Remember, an assignment simply returns the value of what is assigned.

So our problematic implementation silently converts all elements of `dna`
string into 'G'´s whilst the if statement is evaluated as true. No error is
raised because this is perfectly reasonable code, it just isn't doing what you
want it to.



</details>


Let this be a reminder that semantic errors are a pain, because they require 
you to notice something in your code that you will probably gloss over 
multiple times. 

You should be wary of syntax - you ~~may~~ will have missed something.


# Time to practice
First a Kahoot!

Now, given this rudimentary introduction into C / C++ concepts relating to 
memory, and a brief introduction into the error messages themselves, try to 
complete a Jutge problem as a group in C / C++ , paying special attention to 
the error messages that may appear along the way.


> **Note**
> You should complete the following problem by:
>
> 1st Writing the pseudocode
>
> 2nd Discussing the pseudocode with other group members to see if something 
was missed
>
> 3rd Try to understand the errors you may get after you've translated the 
pseudocode into C/C++!


If you've succesfully completed this problem, feel free to practice with any
other problem that accepts solutions in C/C++!

## Extra Resources

[Pass by Reference C++](https://www.ibm.com/docs/en/zos/2.4.0?topic=calls-pass-by-reference-c-only)

[References & Aliases](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html#zz-2.1)

[Pass by Value](https://icarus.cs.weber.edu/~dab/cs1410/textbook/6.Functions/value.html)


[^lib]: Note that ANY PYTHON FILE can be imported, so you can import whatever 
file you want! On a similar note, have you wondered why we include `if __name__ 
== '__main__':` within our code? At a practical level, it has to do with how 
python imports modules - essentially, we want to differentiate from situations 
where we execute a file versus when we import the file and initialize it. Please
 watch the 4 minute video 'https://youtu.be/sugvnHA7ElY' if you're interested!

[^file_py]: These files are stored at `/usr/lib/python` if you want to have a 
look! (they may be distributed in different versions of python, feel free to 
take a look at them through vim!)

[^header_files]: These files are located in `/usr/include/`

[^scope]: "Function-definition scope. Scope is the location in a program where 
a name is visible and accessible" - Weber State University, Computer Science 
1410 6.2.2 Functions and Variable Scope

[^stack_function_frames]: When a function is called, memory for local 
variables is allocated on the stack, and when the function returns, that memory 
is deallocated. This means that the local variables' values are no longer 
available or accessible once the function exits, and any attempt to access them 
after the function call has completed will lead to undefined behavior.
