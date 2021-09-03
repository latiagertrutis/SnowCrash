In the home directory we have an executable file, which has the `setuid` bit enabled, we can know this by executing `ls -la`. This means that any user can execute the binary with the owners privileges. If we execute the program it says that it's expecting 4242 as uid.

It gets the user id with the `getuid` function, which is loaded as a shared library:

``` shell
level13@SnowCrash:~$ nm -D ./level13 
080486bc R _IO_stdin_used
         w __gmon_start__
         U __libc_start_main
         U exit
         U getuid
         U printf
         U strdup
```

Knowing this we can use the [LD_PRELOAD exploit](https://www.boiteaklou.fr/Abusing-Shared-Libraries.html), an environment variable which basically will tell the binary a library that will be pre-loaded before all the standard ones, so we can create our own library with our own `getuid` function (`my_getuid.c`) that will return 4242.


``` shell
gcc -shared -fPIC /tmp/my_getuid.c -o /tmp/my_getuid.o;
cp ~/level13 .;
LD_PRELOAD=/tmp/my_getuid.o ./level13;
```

Another way of solve this, is creating an user with uid=4242 and execute the binary level13 on your local machine with that user, less programatically but interesting anyway.
