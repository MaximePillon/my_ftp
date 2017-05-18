/*
** cwd.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/cwd.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:25:51 2017 Maxime PILLON
** Last update Wed May 10 14:25:51 2017 Maxime PILLON
*/

#include		<unistd.h>
#include		<string.h>
#include		"server.h"

int			cwd(int consocket, t_child *child)
{
  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  if (strlen(child->command) == 4)
  {
    respond("501", "Syntax error in parameters or arguments.", consocket);
    return (0);
  }
  clear_arg(child->command);
  if (chdir(child->command + 4) == 0)
    respond("250", "Requested file action okay, completed.", consocket);
  else
    respond("550", "Requested action not taken.", consocket);
  return (0);
}