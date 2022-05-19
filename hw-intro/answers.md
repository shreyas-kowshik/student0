### 3.3
d. 0x7fffffffdd28

e. "/media/shreyas/Data/CS162/student0/hw-intro/map"

g. 0x4005a9

l.
rax            0x2      2
rbx            0x0      0
rcx            0x7ffffffe       2147483646
rdx            0x7ffff7dd3780   140737351858048
rsi            0x1      1
rdi            0x2      2
rbp            0x7fffffffdc00   0x7fffffffdc00
rsp            0x7fffffffdbe0   0x7fffffffdbe0
r8             0x0      0
r9             0x2      2
r10            0x0      0
r11            0x246    582
r12            0x400470 4195440
r13            0x7fffffffdd20   140737488346400
r14            0x0      0
r15            0x0      0
rip            0x4005dc 0x4005dc <recur+51>
eflags         0x202    [ IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0

v.
0x4005e3 <recur+58> mov $0x0,%eax
0x4005e8 <recur+63> leaveq
0x4005e9 <recur+64> retq

### 3.4
1.
movl -20(%rbp), %eax
subl $1, %eax
movl %eax, %edi
call recur

2. .text : code, .data : static data

3. `objdump -t map.o`

4. g : global symbol, O : symbol in name of object, F : symbol in name of function, *UND* : the section is referenced in the file being dumped, but not defined there

5. In recurse.o, 0000000000000000 g     F .text	0000000000000041 recur

6. Symbols defined in `recurse.o` like `recur` do not have *UND* now

7. .text contains recur. The address is not the same due to the relocation done on loading the program by the operating system by chaning the segment register values (basically where the program is loaded will depend on runtime situation)

8. .data

9. Stack and Heap are runtime concepts which have no original segment in executable.
Since they are just scratch space used dynamically, there's no reason why they should be present in the executable; they are created automatically at process (heap) or thread (stack) creation
(https://stackoverflow.com/questions/35124088/no-stack-or-heap-when-doing-objdump)

10. In direction of decreasing addresses based on the decrementing of stack pointer each time a function call is to be made