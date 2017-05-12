# sqlite-inet

This Sqlite extension provides `inet_aton()` and `inet_ntoa()` functions
for converting IP adresses between their string and numeric representation.

## Usage

```
$ make
$ sqlite3
sqlite> .load bin/inet.so
sqlite> select inet_ntoa(3232235777);
192.168.1.1
```

If you don't want to compile code yourself you can download binaries from here:

| Operating System                                                    | SHA256 |
| ------------------------------------------------------------------- | ------ |
| [Linux 64-bit](https://tznvy.eu/download/sqlite-inet/amd64/inet.so) | `4147cf5226184a5761cbe87d6a06bdf22289db57819069667cf46362c4e58fad` |
| [Linux 32-bit](https://tznvy.eu/download/sqlite-inet/i386/inet.so)  | `5912909bb63640c80b08b83e53e36c672c6474be98d56922525bae57923b718f` |

## Misc

The functions behave like their [MariaDB analogs](https://mariadb.com/kb/en/mariadb/inet_ntoa/), that is,
they expect integers in host byte order,
rather than network byte order as expected by [C functions](https://linux.die.net/man/3/inet_ntoa).
For more info, see [this bug report](https://bugs.mysql.com/bug.php?id=34030#c197546).

When invoked with NULL, NULL is returned.

When invoked with otherwise incorrect data, an error is raised.
