# From section0 work

```
void f() {
    int x[10]; // this allocated on the stack
    // when returned, this memory is kept as is unless it is overwritten by some other function call or process
}

```

Size of struct NEED NOT BE sum of size of members : https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/
See the example in the section. Answers are obtained if padding considered.
https://www.includehelp.com/c/size-of-struct-in-c-padding-alignment-in-struct.aspx

<hr></hr>

`extern`
`extern int a` will define the variable but no memory will be allocated to it. Generally used in header files to just declare the variables and functions. Memory is then allocated in the actual file where the program is present.

`volatile`
`volatile int a` will cause the compiler to turn off optimizations when compiling code using this variable and always read it from its memory location. In other words if this variable is accessed and used further, it is possible that the compiler will save it in a register and access it from there. This may not be desirable when the variable has a memory location that is updated outside of what the compiler can see, for instacne an interrupt service routine updating data on a port. Hence use volatile in such cases.
Usefule link : https://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/

# Compiling
Compile to assembly : `gcc -S -o myprogram.S myprogram.c`

Some flags :
* -Wall – Enables all compiler warnings
* -m32 – Compiles the code for the i386 architecture.
* -S – Invokes the COMPILER only.
* -c – Invokes the COMPILER and ASSEMBLER only.

Assemble compiled code into exectuable : `gcc -c -o myprogram.o myprogram.S`. Can also be run on `myprogram.c`
The assembler converts the raw assembly code into an object file which contains code as well as other
data and metadata necessary for execution. Different operating systems use different types of object
files. In this class, we will be using ELF (Executable and Linkable Format), the object format used by
Linux.

Reading .o files : `objdump -D myprogram.O`

The assembler generates a symbol table which is part of the object file. The symbol table contains all
the symbols that can be globally referenced (referenced outside the object file) from another object file
(i.e. global/static variables and functions).

Printing symbol table : `objdump -t myprogram.O`

Symbol table ELF format meaning (https://stackoverflow.com/questions/6666805/what-does-each-column-of-objdumps-symbol-table-mean) (Official link : https://sourceware.org/binutils/docs/binutils/objdump.html):
* COLUMN ONE: the symbol's value

* COLUMN TWO: a set of characters and spaces indicating the flag bits that are set on the symbol. There are seven groupings which are listed below:

group one: (l,g,,!) local, global, neither, both.

group two: (w,) weak or strong symbol.

group three: (C,) symbol denotes a constructor or an ordinary symbol.

group four: (W,) symbol is warning or normal symbol.

group five: (I,) indirect reference to another symbol or normal symbol.

group six: (d,D,) debugging symbol, dynamic symbol or normal symbol.

group seven: (F,f,O,) symbol is the name of function, file, object or normal symbol.

* COLUMN THREE: the section in which the symbol lives, ABS means not associated with a certain section

* COLUMN FOUR: the symbol's size or alignment.

* COLUMN FIVE: the symbol's name.

`objdump -x -d map` prints everything