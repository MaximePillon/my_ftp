/*
** mkd.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/mkd.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:36:51 2017 Maxime PILLON
** Last update Wed May 10 14:36:51 2017 Maxime PILLON
*/

#include		"server.h"

int			mkd(int consocket, t_child *child)
{
  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  respond("202", "Command not implemented, superfluous at this site.",
	  consocket);
  return (0);
}