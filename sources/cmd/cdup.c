/*
** cdup.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/cdup.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:26:30 2017 Maxime PILLON
** Last update Wed May 10 14:26:30 2017 Maxime PILLON
*/

#include		<unistd.h>
#include		"server.h"

int			cdup(int consocket, t_child *child)
{
  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  if (chdir("..") == 0)
    respond("250", "Requested file action okay, completed.", consocket);
  else
    respond("550", "Requested action not taken.", consocket);
  return (0);
}