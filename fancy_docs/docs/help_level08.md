
We have two files: executable named `level08` and a file named `token` which we can not read. `level08` asks for a file and prints it's contents except if the file name contains the word `token`. A way to access a file with another name without modify it is to create a soft link:

``` shell
ln -s /home/user/level08/token /tmp/not_nekot && ./level08 /tmp/not_nekot
```
