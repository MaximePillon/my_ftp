/*
** throw_errror.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/throw_errror.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 08:05:31 2017 Maxime PILLON
** Last update Tue May 09 08:05:31 2017 Maxime PILLON
*/

#include	<stdio.h>
#include	"server.h"

int		throw_error(char *error)
{
  if (error)
    printf("%s\n", error);
  return (-1);
}