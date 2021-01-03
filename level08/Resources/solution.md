If we use `level08` binary to print the token it says: `You may not access 'token'`, it performs the same with any other file that contains the word `token`, if we see the functions inside the binary with `nm`:

``` shell
level08@SnowCrash:~$ nm level08 
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
0804877c R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
080488d0 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a030 A __bss_start
0804a028 D __data_start
08048730 t __do_global_ctors_aux
080484d0 t __do_global_dtors_aux
0804a02c D __dso_handle
         w __gmon_start__
08048722 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
08048720 T __libc_csu_fini
080486b0 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
         U __stack_chk_fail@@GLIBC_2.4
0804a030 A _edata
0804a038 A _end
0804875c T _fini
08048778 R _fp_hw
080483b4 T _init
080484a0 T _start
0804a030 b completed.6159
0804a028 W data_start
0804a034 b dtor_idx.6161
         U err@@GLIBC_2.0
         U exit@@GLIBC_2.0
08048530 t frame_dummy
08048554 T main
         U open@@GLIBC_2.0
         U printf@@GLIBC_2.0
         U read@@GLIBC_2.0
         U strstr@@GLIBC_2.0
         U write@@GLIBC_2.0
```

The function `strstr` searches a sub-string so it will probably search in the file name. A way to access a file with another name without modify it is to create a soft link:

``` shell
level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/not_nekot && ./level08 /tmp/not_nekot
quif5eloekouj29ke0vouxean
```

With the token you can access flag08
