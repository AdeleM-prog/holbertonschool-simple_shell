#include <stdio.h>
/**
 * getline - reads from stream
 * @lineptr: stores the address of the buffer
 * @n: nb of bytes allocated to the buffer
 * Return: Always 0.
 */

int main(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t len = 0;

while (1)
{
printf("$ ");
len = getline(&line, &bufsize, stdin);

if (len == -1)
break;

printf("%s", line);
}
printf("\n");
free(line);
return (0);
}
