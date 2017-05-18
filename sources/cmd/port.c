/*
** port.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/port.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:29:39 2017 Maxime PILLON
** Last update Wed May 10 14:29:39 2017 Maxime PILLON
*/

#include		<stdlib.h>
#include		<string.h>
#include		"server.h"

static int		str_replace(char *str, char find, char replace)
{
  int			cpt;
  int			nb_occur;

  cpt = 0;
  nb_occur = 0;
  while (str[cpt])
  {
    if (str[cpt] == find)
    {
      str[cpt] = replace;
      ++nb_occur;
    }
    ++cpt;
  }
  return (nb_occur);
}

static int		get_ip(const char *cmd)
{
  int			cpt;
  int			size;

  cpt = 0;
  size = 0;
  while (cpt != 4)
  {
    if (cmd[size] == '.')
      ++cpt;
    ++size;
  }
  return (size);
}

static t_address	*get_address(char *cmd)
{
  t_address		*port;
  int			size_ip;
  int			p1;
  int			p2;
  char			*tmp;

  port = malloc(sizeof(t_address));
  if (!port)
    return (NULL);
  if (str_replace(cmd, ',', '.') != 5)
    return (NULL);
  size_ip = get_ip(cmd) - 2;
  port->addr = strndup(cmd, (size_t)size_ip);
  if (!port->addr)
    return (NULL);
  p1 = (int)strtol(cmd + size_ip + 2, &tmp, 10);
  p2 = (int)strtol(tmp + 1, NULL, 10);
  port->port = p1 * 256 + p2;
  return port;
}

int			port(int consocket, t_child *child)
{
  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  if (child->mode == NONE)
    child->data = data_active(get_address(child->command+5));
  if (!child->data)
  {
    respond("421", "Service not available, closing control connection.", consocket);
    return (0);
  }
  child->mode = ACTIVE;
  respond("200", "Command okay.", consocket);
  return (0);
}