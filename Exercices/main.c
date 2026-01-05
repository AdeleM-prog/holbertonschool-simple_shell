#include <stdio.h>
#include <stdlib.c>
/**
 * main - looks for files in the current PATH
 * @ac: argument count
 * @av: argument vector
 * @envp: environment variables
 *
 * Return: 0
 */
int main(int ac, char **av, char **envp)
{
    int i;

    if (ac < 2)
    {
        printf("Usage: %s filename ...\n", av[0]);
        return (1);
    }

    for (i = 1; av[i] != NULL; i++)
        find_in_path(av[i], envp);

    return (0);
}