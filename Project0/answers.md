# 2.1
1. 0xc0000008
2. 0x80488ee
3. `objdump -d -x do-nothing`
Function name : `_start`
080488e8 <_start>:
 80488e8:	55                   	push   %ebp
 80488e9:	89 e5                	mov    %esp,%ebp
 80488eb:	83 ec 18             	sub    $0x18,%esp
 80488ee:	8b 45 0c             	mov    0xc(%ebp),%eax # argv to eax
 80488f1:	89 44 24 04          	mov    %eax,0x4(%esp) # esp[4] stores argv
 80488f5:	8b 45 08             	mov    0x8(%ebp),%eax # argc to eax
 80488f8:	89 04 24             	mov    %eax,(%esp) # esp[0] stores argc
 80488fb:	e8 94 f7 ff ff       	call   8048094 <main>
 8048900:	89 04 24             	mov    %eax,(%esp) # argument to exit
 8048903:	e8 4f 21 00 00       	call   804aa57 <exit>
4. 