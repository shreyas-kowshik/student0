# GDB
* Better to turn off optimizations during debugging
* Recommended options : `gcc -O0 -g3`. `-g3` includes debugging information on macros like `#define` as well unlike `-g` which does not
* Starting gdb : `gdb myprogram` where `myprogram` is an executable. Use `gdb -q` to ignore startup messages
* Passing arguments : `gdb --args myprogram 1 2 3 4` and use `show args` to see the arguments OR `gdb myprogram` and then `run 1 2 3 4`
* Setting breakpoints : `break file.c:1` sets a breakpoint at line 1
* Conditional breakpoint : `break file.c:6 if i>=ARRAYSIZE`
* Printing information : `print my_var` prints the value. Can use *,.,-> and other C operations as well. `print/x` prints in hexadecimal
* Switch to assembly mode : `layout asm`
* Step through machine code one instruction at a time : `stepi` or `si`
* Step through code : `step` gets inside function calls if required. `next` executes instructions fully and not so granular
* `info breakpoints` shows all current breakpoints
* `disable breakpoint_number` disables the breakpoint. `enable` enables it
* `info registers` shows values of all registers. `info register eax` shows %eax value
* `help command` gives the documentation
* `where` is used to print the stack frames of calls to see how you got there. `up` goes up the stack frame calls. `down` goes in the forward direction
A GREAT tutorial on using gdb and stack frames to debug : https://www.cse.unsw.edu.au/~learn/debugging/modules/gdb_call_stack/









### References
http://www.unknownroad.com/rtfm/gdbtut/gdbstep.html

https://developers.redhat.com/blog/2021/04/30/the-gdb-developers-gnu-debugger-tutorial-part-1-getting-started-with-the-debugger#compiler_options

https://www.cse.unsw.edu.au/~learn/debugging/modules/gdb_call_stack/
