
We have two files: executable named `level09` and a file named `token`. The binary outputs the introduced string with each character incremented by it's position, the token is probably encoded with this method, so with a program (`inverse_ascii.c`) doing the inverse operation we get:


``` shell
scp -P 4242 ./inverse_ascii.c level09@192.168.1.10:/tmp
```

``` shell
cd /tmp && gcc -std=c99 inverse_ascii.c && ./a.out $(cat ~/token)
```

which is the solution
