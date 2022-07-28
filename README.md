# Simple Shell project 0x16.c - tite -

This is a simple UNIX command interpreter based on bash and Sh.

## Overview

**tite** is a sh-compatible command language interpreter that executes commands read from the standard input or from a file.

### Invocation

Usage: **tite** 
tite is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o tite
./tite
```

When **tite** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. **tite** Will be using the following prompt `#tite: `.

Example:
```
$./tite
#tite:
```

If a command line argument is invoked, **tite** will take that first argument as a file from which to read commands.

Example:
```
$ ./tite
#tite: echo 'Alx'
'Alx'
$
```

### Environment

Upon invocation, **tite** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$./tite
#tite: echo $HOME
/home/vagrant
```

#### PWD
The current working directory as set by the **cd** command.

```
$./tite
#tite: echo $PWD
/home/vagrant/Alx/simple_shell
```

#### OLDPWD
The previous working directory as set by the **cd** command.

```
$./tite
#tite: echo $OLDPWD
/home/vagrant/Alx/projects
```

#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.


### Command Execution

After receiving a command, **tite** tokenizes it into words using `" "` as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. **tite** then proceeds with the following actions:
1. If the first character of the command is neither a slash (`\`) nor dot (`.`), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
2. If the first character of the command is none of a slash (`\`), dot (`.`), nor builtin, **tite** searches each element of the **PATH** environmental variable for a directory containing an executable file by that name.
3. If the first character of the command is a slash (`\`) or dot (`.`) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.

### Exit Status 

**tite** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.
If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126.
All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

### Signals

While running in interactive mode, **tite** ignores the keyboard input ctrl+c. Alternatively, an input of End-Of-File ctrl+d will exit the program.

User hits ctrl+d in the foutrh command.
```
$ ./tite
#tite: ^C
#tite: ^C
#tite: ^C
#tite:
```

### Builtin Commands

#### cd
  * Usage: `cd [DIRECTORY]`
  * Changes the current directory of the process to `DIRECTORY`.
  * If no argument is given, the command is interpreted as `cd $HOME`.
  * If the argument `-` is given, the command is interpreted as `cd $OLDPWD` and the pathname of the new working directory is printed to standad output.
  * If the argument, `--` is given, the command is interpreted as `cd $OLDPWD` but the pathname of the new working directory is not printed.
  * The environment variables `PWD` and `OLDPWD` are updated after a change of directory.

Example:
```
$ ./tite
#tite: pwd
/home/vagrant/Alx/simple_shell
#tite: ../
/home/vagrant/Alx/
#tite: pwd
/home/vagrant/Alx
#tite: cd -
/home/vagrant/Alx/simple_shell
#tite: pwd
/home/vagrant/Alx/simple_shell
```

#### exit
  * Usage: `exit [STATUS]`
  * Exits the shell.
  * The `STATUS` argument is the integer used to exit the shell.
  * If no argument is given, the command is interpreted as `exit 0`.

Example:
```
$ ./tite
$ exit
```

#### env
  * Usage: `env`
  * Prints the current environment.

Example:
```
$ ./tite
$ env
NVM_DIR=/home/vagrant/.nvm
...
```

#### setenv
  * Usage: `setenv [VARIABLE] [VALUE]`
  * Initializes a new environment variable, or modifies an existing one.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./tite
#tite: setenv NAME Alx
#tite: echo $NAME
Alx
```

#### unsetenv
  * Usage: `unsetenv [VARIABLE]`
  * Removes an environmental variable.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./tite
$ setenv NAME Alx
$ unsetenv NAME
$ echo $NAME

$
```

## Authors & Copyrights

* Timothy Adeleke
* Temitayo Akere

## More information

**tite** is a simple shell unix command interpreter that is part of the Alx low level programming module at Alx Africa and is intended to emulate the basics **sh** shell. All the information given in this README is based on the **tite** and **bash** man (1) pages.
