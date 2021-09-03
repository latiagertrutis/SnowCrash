The password hashed is on `/etc/passwd` file

``` shell
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

After, i used john the reaper for obtain the password

For Ubuntu:

``` shell
    sudo apt-get install john -y
```

For Arch:

``` shell
    pacman -S john
```

Then execute:

``` shell
echo "42hDRfypTqqnw" > hash.txt;
john hash.txt;
john --show hash.txt;
```

Remember to remove `?:` from the output of john
