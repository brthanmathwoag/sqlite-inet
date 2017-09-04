# sqlite-inet

This Sqlite extension provides `inet_aton()` and `inet_ntoa()` functions
for converting IP adresses between their string and numeric representation.

## Usage

```
$ make
$ sqlite3
sqlite> .load bin/inet
sqlite> select inet_ntoa(3232235777);
192.168.1.1
```

If you don't want to compile code yourself you can download binaries from here:

| Operating System                                                    | SHA256 |
| ------------------------------------------------------------------- | ------ |
| [Linux 64-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-lin-x64.zip) | `0fd7032dd132a26fa44b33777aba1cbd841cada2a3a91aaee9379da84d627cad` |
| [Linux 32-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-lin-x86.zip)  | `be1264f95b2d2229ed9250911022ec9f1be89d29919aebc65f72131954e9a946` |
| [Windows 64-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-win-x64.zip) | `74202c3c4f13b71c85657c7ed0066eddf82055157d27678d10b27a035c4b8235` |
| [Windows 32-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-win-x86.zip) | `5416b902d8c7aa66fdd6ce1619199371f4fabffbf23c047d967fe84fd5718bca` |

## Misc

The functions behave like their [MariaDB analogs](https://mariadb.com/kb/en/mariadb/inet_ntoa/), that is,
they expect integers in host byte order,
rather than network byte order as expected by [C functions](https://linux.die.net/man/3/inet_ntoa).
For more info, see [this bug report](https://bugs.mysql.com/bug.php?id=34030#c197546).

When invoked with NULL, NULL is returned.

When invoked with otherwise incorrect data, an error is raised.
