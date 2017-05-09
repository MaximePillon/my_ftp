/*
** parser.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/parser.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 07:54:04 2017 Maxime PILLON
** Last update Tue May 09 07:54:04 2017 Maxime PILLON
*/

#include		<stdlib.h>
#include		<string.h>
#include		"server.h"

int			param_parsing(int ac, char **av, t_serv *serv)
{
  if (ac != 3)
    return (-1);
  serv->port = (int)strtol(av[1], NULL, 10);
  serv->pathname = strdup(av[2]);
  if (!serv->pathname)
    return (-1);
  return (0);
}