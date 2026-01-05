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
   char *token;
   int nb, i;
   char buffer[1024];
   nb = read(0, buffer, 1023);
   if (nb <= 0)
   return (1);
   else
   buffer[nb] = '\0';
   str = buffer;
   token = strtok(str, delim);
   

   while (token != NULL)
   {
      for (i = 0; token[i] != '\0'; i++)
      {}
      write (1, token, i);
   token = strtok(NULL, delim);
   }
   return (0);
}