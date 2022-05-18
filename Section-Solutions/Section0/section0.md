### Makefile

When you run GNU `make` it will look into look inside a Makefile and execute commands according to the Makefile language.

```
my_first_makefile_rule:
    echo "Hello world"
```

The building block of GNU Make is a rule. We just created a rule, whose target is my_first_makefile_rule
and recipe is echo "Hello world". When we run make my_first_makefile_rule, GNU Make will
execute the steps in the recipe and print “Hello world”.

Rules can also contain a list of dependencies, which are other targets that must be executed
before the rule. In this example, the task_two rule has a single dependency: task_one. If we run
“make task_two”, then GNU Make will run task_one and then task_two.

```
task_one:
    echo 1
task_two: task_one
    echo 2
```

Indent with tabs. Use `-j $n` for `$n` number of threads in parallel make run.

### GDB


### x86 Assembly

The 32-bit x86 ISA has 8 main registers: eax, ebx, ecx, edx, esi, edi, esp, and ebp. You can omit the
“e” to reference the bottom half of each register. For example, ax refers to the bottom half of eax.

eip : Instruction Pointer/Similar to PC
esp : Stack Pointer
ebp : Frame pointer
See this for more information : https://stackoverflow.com/questions/1395591/what-is-exactly-the-base-pointer-and-stack-pointer-to-what-do-they-point#:~:text=in%20two%20words%3A%20stack%20pointer,pushed%20previously%20on%20the%20stack.

Basically ebp is preserved across a function call

x86 also has segment registers (cs, ds, es, fs, gs, and ss) and control registers (e.g., cr0). You can
think of segment registers as offsets when accessing memory in certain ways (e.g., cs is for instruction
fetches, ss is for stack memory), and control registers as configuring what features of the processor are
enabled (e.g., protected mode, floating point unit, cache, paging).

In the AT&T syntax:
• Registers are preceded by a percent sign (e.g., %eax for the register eax)
• Immediates are preceded by a dollar sign (e.g., $4 for the constant 4)
• For many (but not all!) instructions, use parentheses to dereference memory addresses (e.g., (%eax)
reads from the memory address in eax)
• You can add a constant offset by prefixing the parentheses (e.g., 8(%eax) reads from the memory
address eax + 8)
• Source operands typically precede destination operands, for instructions with two operands.

Use the suffix b to work with
8-bit bytes. Use the suffix w to work with 16-bit words. Use the suffix l to work with 32-bit longwords
(or doublewords). (Analogously, on the x86-64 ISA, append q to work with 64-bit quadwords).

See examples.

6.3
movl $0, %eax

6.6
###### Calling Conventions

Top of stack must be 16-byte aligned when pushing in caller. Pad is necessary.

edx=3
eax=4
eax=7 (return value)
eax=8 (add one)

High


ebp
4
3
ret_add
ebp
7


.

Low

6.7

Pro tip : #include "my_lib.h" inside of "my_lib.c" that is include the headers inside the files to ensure less bugs are there

#ifdef : https://www.techonthenet.com/c_language/directives/ifdef.php#:~:text=In%20the%20C%20Programming%20Language,code%20in%20the%20compilation%20process. (Conditional Compilation. If the directive is defined only then compiled)


7.3
(Minor doubt in solution given)
```
void f() {
    int x[10]; // this allocated on the stack
    // when returned, this memory is kept as is unless it is overwritten by some other function call or process
}

```

Size of struct NEED NOT BE sum of size of members : https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/
See the example in the section. Answers are obtained if padding considered.
https://www.includehelp.com/c/size-of-struct-in-c-padding-alignment-in-struct.aspx
