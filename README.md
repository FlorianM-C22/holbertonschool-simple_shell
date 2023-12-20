
# Simple Shell - a [Holberton School](https://www.holbertonschool.fr/) C project

<img src="/img/header.png">

### Introduction
The goal was to reproduce a Bourne Shell terminal (sh) in C with a limited number of standard library functions and system calls.

### How to run
To run this program you need to :\
\
**Clone this repository**\
``git clone https://github.com/FlorianM-C22/holbertonschool-simple_shell``
\
**Compile it with the following arguments**\
``gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh``
\
### How to use
Open a terminal and execute the program :
``./hsh``\
It will prompt a ``$ ``waiting for you to type a command.

### Features

**Supported built-ins :**
| Command  | Description   |
| ----------- | ----------- |
| env  | Prints the environment variable   |
| exit  | Exits with the status 0       |


**Supported commands :**

* Every program included in ``$PATH`` and single words like ``pwd``
* Handling commands like ``/bin/pwd``
* Handling the "End of File" condition (``Ctrl+D``)
* Working in interactive and non-interactive mod

### Examples

**Example 1 :**
```
username@your-device:~$ ./hsh
$ pwd
/home/username/simple-shell
```
**Example 2 :**
```
username@your-device:~$ ./hsh
$ /bin/pwd
/home/username/simple-shell
```
**Example 3 :**
```
username@your-device:~$ echo "/bin/pwd" | ./hsh
/home/username/simple-shell
```
**Built-in example :**
```
username@your-device:~$ ./hsh
USER=username
LANGUAGE=fr_FR
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/username
DESKTOP_SESSION=ubuntu
LOGNAME=username
TERM=xterm-256color
PATH=/home/username/bin:/home/username/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
username@your-device:~$
```
### List of allowed functions and system calls
```

    all functions from <string.h>
    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    printf (man 3 printf)
    fprintf (man 3 fprintf)
    vfprintf (man 3 vfprintf)
    sprintf (man 3 sprintf)
    putchar (man 3 putchar)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
```
**For more information**\
\
Check the man page ``man ./man_1_simple_shell``

## Authors

- [@FlorianM-C22](https://github.com/FlorianM-C22)
