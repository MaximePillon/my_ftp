/*
** respond.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/respond.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Thu May 11 11:38:41 2017 Maxime PILLON
** Last update Thu May 11 11:38:41 2017 Maxime PILLON
*/

#include		<unistd.h>
#include		<stddef.h>
#include		<string.h>
#include		"server.h"

void			respond(char *code, char *string, int consocket)
{
  write(consocket, code, strlen(code));
  if (string)
  {
    write(consocket, " ", 1);
    write(consocket, string, strlen(string));
  }
  write(consocket, "\r\n", 2);
}