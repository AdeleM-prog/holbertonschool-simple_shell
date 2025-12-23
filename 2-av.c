#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **split_string(char *str)
{
char *delim = " \t\n", *token;
char **array;
int i = 0, j = 0, k = 0;

if (str == NULL)
return (NULL);

while (str[k] != '\0')
{
    if (str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
    {
        if (k == 0 || str[k - 1] == '\n' || str[k - 1] == '\t' || str[k - 1] == ' ')
        i++;
    }
k++;
}

array = malloc(((i + 1) * sizeof(char*)));
if (array == NULL)
return (NULL);

token = strtok(str, delim);
if (token == NULL)
return (NULL);

while (token != NULL)
{
array[j] = token;
j++;
token = strtok(NULL, delim);
}
array[j] = NULL;

return (array);
}