/*
** help.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/help.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:30:15 2017 Maxime PILLON
** Last update Wed May 10 14:30:15 2017 Maxime PILLON
*/

#include		"server.h"

int			help(int consocket, t_child *child)
{
  (void)child;
  respond("202", "Command not implemented, superfluous at this site.",
	  consocket);
  return (0);
}