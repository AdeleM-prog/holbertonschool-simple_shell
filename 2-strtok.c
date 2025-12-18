#include <stdio.h>
/**
 * strtok - scinde une chaîne en une séquence d'éléments
 * @str: chaîne à scinder
 * @delim: ense des caractères qui délimitent les élements
 * de la chaîne à scinder
 * Return: char
 */
int main(void)
{
   char *str;
   char *delim = " \t\n";
   str = read(0, buffer, size);
   if (str == NULL)
   return(NULL);
   token = strtok(str, delim);
   while (token != NULL)
   {
   token = strtok(NULL, delim);
   }
}