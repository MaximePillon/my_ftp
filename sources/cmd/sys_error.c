/*
** sys_error.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/sys_error.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:41:45 2017 Maxime PILLON
** Last update Wed May 10 14:41:47 2017 Maxime PILLON
*/

#include		"server.h"

int			sys_error(int consocket, t_child *child)
{
  (void)child;
  respond("500", " Syntax error, command unrecognized.", consocket);
  return (0);
}