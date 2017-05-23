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
| [Linux 64-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-lin-x64.zip) | `ae9b8a4a07504d79bfceacf1cb38ef38e4fa8668fac7e5331f6da8fcd91fc39c` |
| [Linux 32-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-lin-x86.zip)  | `d8ae7df0fbb184e158f6ba3bda50d491eef44967e7a875acd08a61bb550d5bf2` |
| [Windows 64-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-win-x64.zip) | `46f982a79863af825d03a7c47914f51cdc97d291a9ff5d7d55472bceca561d57` |
| [Windows 32-bit](https://tznvy.eu/download/sqlite-inet/sqlite-inet-win-x86.zip) | `ca02baa64c6aaa7c20d8c18a79f499cc3732f2cffb4aab949b43bd7d2f4af2f6` |

## Misc

The functions behave like their [MariaDB analogs](https://mariadb.com/kb/en/mariadb/inet_ntoa/), that is,
they expect integers in host byte order,
rather than network byte order as expected by [C functions](https://linux.die.net/man/3/inet_ntoa).
For more info, see [this bug report](https://bugs.mysql.com/bug.php?id=34030#c197546).

When invoked with NULL, NULL is returned.

When invoked with otherwise incorrect data, an error is raised.
