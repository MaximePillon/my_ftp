/*
** noop.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/noop.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:31:03 2017 Maxime PILLON
** Last update Wed May 10 14:31:03 2017 Maxime PILLON
*/

#include		"server.h"

int			noop(int consocket, t_child *child)
{
  (void)child;
  respond("200", "Command okay.", consocket);
  return (0);
}