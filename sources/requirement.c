/*
** requirement.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/requirement.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Thu May 11 09:07:40 2017 Maxime PILLON
** Last update Thu May 11 09:07:40 2017 Maxime PILLON
*/

#include	<unistd.h>
#include	<string.h>
#include 	"server.h"

bool		is_authenticated(t_child *child)
{
  if (child->username)
    if (strcmp(child->username, "Anonymous") == 0 || child->password)
      return true;
  return false;
}

bool		has_username(t_child *child)
{
  if (child->username)
    return true;
  return false;
}

int		quit_cmd(int consocket)
{
  close(consocket);
  return (0);
}
