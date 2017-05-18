/*
** dele.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/dele.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:28:23 2017 Maxime PILLON
** Last update Wed May 10 14:28:23 2017 Maxime PILLON
*/

#include		<string.h>
#include		<stdio.h>
#include		"server.h"

int			dele(int consocket, t_child *child)
{
  char			*filename;

  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  filename = strdup(child->command + 5);
  clear_arg(filename);
  if (strlen(filename) == 0)
  {
    respond("501", "Syntax error in parameters or arguments.", consocket);
    return (0);
  }
  if (remove(filename) == -1)
  {
    respond("550", "Requested action not taken.", consocket);
    return (0);
  }
  respond("250", "Requested file action okay, completed.", consocket);
  return (0);
}