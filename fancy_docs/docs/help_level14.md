In this last level we have no clues to get the token, so a straight-forward solution by disassemble the `getflag` binary is necessary, to do so we run the binary under `gdb` and call the command `disassemble main` which will output the program in assembler. In the assembler instructions we can see 16 calls to `fputs`, assuming that this function will print the flags for each level alongside with some other messages, by trial and error (presumably one of the last ones `fputs`) we can check those print by jumping directly to it's memory addresses in the running program. Here the section that actually contains  the flag for level 14:

``` asm
   0x08048de3 <+1181>:	jmp    0x8048e2f <main+1257>
   0x08048de5 <+1183>:	mov    0x804b060,%eax
   0x08048dea <+1188>:	mov    %eax,%ebx
   0x08048dec <+1190>:	movl   $0x8049220,(%esp)
   0x08048df3 <+1197>:	call   0x8048604 <ft_des>
   0x08048df8 <+1202>:	mov    %ebx,0x4(%esp)
   0x08048dfc <+1206>:	mov    %eax,(%esp)
   0x08048dff <+1209>:	call   0x8048530 <fputs@plt>
```

so we will jump to `0x08048de5` and the program will end printing the flag for the level 14:

``` bash
➜ gdb getflag
(gdb) b main
Breakpoint 1 at 0x804894a
(gdb) run
Starting program: /home/mateo/Sync/workspace/SnowCrash/level14/Resources/getflag

Breakpoint 1, 0x0804894a in main ()
(gdb) jump *0x08048de5
Continuing at 0x8048de5.
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
*** stack smashing detected ***: terminated

Program received signal SIGABRT, Aborted.
0xf7fce569 in __kernel_vsyscall ()
```
