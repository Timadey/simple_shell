#include "shell.h"
#include <stdio.h>

/**
 * main - the entry of the shell program
 * @argc - argument count
 * @argv - argument vector
 * Return: 0 on success or 1
 */

int main(int argc, char **argv)
{
    char *command;
    size_t n_get;
    shell_init();

    while (n_get = getline(&command, &n_get, STDIN) != -1)
    {

    }
    return (0);

}