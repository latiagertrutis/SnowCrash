There is a pcap file in your home, download the file in your computer, install tcpdump, and read it:

Install tcpdump for Ubuntu (use equivalent for your operating system):
``` shell
sudo apt install tcpdump
```

Download the `pcap` file:

``` shell
scp -P4242 level02@192.168.1.10:/home/user/level02/level02.pcap .
```

And execute tcpdump:

``` shell
tcpdump -Xqns 0 -A -r level02.pcap
```

There you can see that from the payload the only byte interesting to us is the one in the position `0x35`, reading this position you can find the following sequence, (`DEL` means a backspace in the keyboard):

``` 
"ft_wandr" => DEL => DEL => DEL => "NDRel" => DEL => "L0L"
```

Resulting in the following string which indeed is the password: `ft_waNDReL0L`


