In the home directory we have an executable file, which has the `setuid` bit enabled:

``` shell
level13@SnowCrash:~$ ls -la
total 20
dr-x------ 1 level13 level13  120 Mar  5  2016 .
d--x--x--x 1 root    users    340 Aug 30  2015 ..
-r-x------ 1 level13 level13  220 Apr  3  2012 .bash_logout
-r-x------ 1 level13 level13 3518 Aug 30  2015 .bashrc
-r-x------ 1 level13 level13  675 Apr  3  2012 .profile
-rwsr-sr-x 1 flag13  level13 7303 Aug 30  2015 level13
```

This means that any user can execute the binary with the owners privileges.

If we execute the program it says that it's expecting 4242 as uid:

``` shell
level13@SnowCrash:~$ ./level13 
UID 2013 started us but we we expect 4242
```

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

Knowing this we can use the [LD_PRELOAD exploit](https://www.boiteaklou.fr/Abusing-Shared-Libraries.html), an environment variable which basically will tell the binary a library that will be pre-loaded before all the standard ones, so we can create our own library with our own `getuid` function that will return 4242:

`my_getuid.c`
``` C
#include <unistd.h>

uid_t getuid(void) {
	return 4242;
}
```

``` shell
level13@SnowCrash:/tmp$ cat /tmp/my_getuid.c
#include <unistd.h>

uid_t getuid(void) {
	return 4242;
}

level13@SnowCrash:/tmp$ gcc -shared -fPIC /tmp/my_getuid.c -o /tmp/my_getuid.o
level13@SnowCrash:/tmp$ cp ~/level13 .
level13@SnowCrash:/tmp$ LD_PRELOAD=/tmp/my_getuid.o ./level13
your token is 2A31L79asukciNyi8uppkEuSx
```

