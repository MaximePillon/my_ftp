/*
** user.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/user.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:24:09 2017 Maxime PILLON
** Last update Wed May 10 14:24:09 2017 Maxime PILLON
*/

#include		<stdio.h>
#include		<string.h>
#include		"server.h"

int			user(int consocket, t_child *child)
{
  if (strlen(child->command) == 5)
    respond("501", NULL, consocket);
  child->username = strdup((child->command + 5));
  if (!child->username)
  {
    //todo throw error and quit
    return (-1);
  }
  if (!strcmp(child->username, "Anonymous"))
  {
    respond("332", NULL, consocket);
    child->username = NULL;
    return (0);
  }
  respond("331", "User name okay, need password.", consocket);
  return (0);
}