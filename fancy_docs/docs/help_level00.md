You can find a file in `/usr/sbin` named john and owned by flag00:

``` shell
level00@SnowCrash:~$ find / -user flag00 2>/dev/null 
/usr/sbin/john
/rofs/usr/sbin/john
```

If you do cat you obtain the password encrypted with cesar code:

``` shell
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

You can use key 15 to decrypt this in the following web-page: https://www.dcode.fr/caesar-cipher
