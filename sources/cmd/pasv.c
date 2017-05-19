/*
** pasv.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/pasv.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:29:03 2017 Maxime PILLON
** Last update Wed May 10 14:29:03 2017 Maxime PILLON
*/

#include		<stddef.h>
#include		<stdio.h>
#include		"server.h"

int			pasv(int consocket, t_child *child)
{
  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  if (child->mode == NONE)
    child->data = data_connection_initializer();
  if (!child->data)
  {
    respond("421",
	    "Service not available, closing control connection.", consocket);
    return (0);
  }
  child->mode = PASSIVE;
  dprintf(consocket, "227 Entering Passive Mode (127,0,0,1,%d,%d).\r\n",
	  child->data->port / 256, child->data->port % 256);
  return (0);
}