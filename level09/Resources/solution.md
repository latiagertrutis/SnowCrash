The binary in this level outputs the introduced string with each character incremented by it's position, the token is probably encoded with this method, so with a program (`inverse_ascii.go`) doing the inverse operation we get:

``` shell
➜  Resources git:(master) ✗ ./inv $(cat ./token )
f3iji1ju5yuevaus41q1afiuq
```
which is the solution
