/*
** pass.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/pass.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:25:05 2017 Maxime PILLON
** Last update Wed May 10 14:25:05 2017 Maxime PILLON
*/

#include		<string.h>
#include		"server.h"

int			pass(int consocket, t_child *child)
{
  if (!has_username(child))
  {
    respond("332", "Need account for login.",consocket);
    return (0);
  }
  child->password = strdup((child->command + 5));
  if (!child->password)
  {
    //todo throw error and quit
    return (-1);
  }
  if (!strcmp(child->password, "\r\n"))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  respond("230", "User logged in, proceed.", consocket);
  return (0);
}