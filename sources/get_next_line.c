/*
** get_next_line.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/get_next_line.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 08:25:36 2017 Maxime PILLON
** Last update Wed May 10 08:25:36 2017 Maxime PILLON
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<string.h>
#include		"server.h"

static char			*cp_buffer(const char *buf, char *str,
				   int i, int j)
{
  if (str[j] != '\0')
    while (str[j] != '\0' && str[j] != '\n')
      j++;
  while (buf[i] != '\0' && buf[i] != '\n')
    {
      str[j] = buf[i];
      i++;
      j++;
    }
  str[j] = '\0';
  str = realloc(str, (READ_SIZE + strlen(str) + 1));
  return (str);
}

static char 		*copy_buffer_ret(const char *buf, char *str, int *ret)
{
  int			j;

  j = 0;
  (*ret)++;
  while (buf[(*ret)] != '\0' && buf[(*ret)] != '\n' && buf[*ret - 1] != '\r')
    {
      str[j] = buf[(*ret)];
      (*ret)++;
      j++;
    }
  str[j] = '\0';
  str = realloc(str, (READ_SIZE + strlen(str) + 1));
  return (str);
}

char			*get_next_line(const int fd)
{
  static int		ret = 0;
  static char		buffer[READ_SIZE];
  char			*st;
  ssize_t		tmp;

  if (((st = malloc(sizeof(char) * READ_SIZE + 1))) == NULL || (st[0] = '\0'))
    return (NULL);
  if (buffer[ret] == '\n' && buffer[ret - 1] == '\r' && buffer[ret + 1] != '\0')
    {
      st = copy_buffer_ret((const char *)buffer, st, &ret);
      if (buffer[ret] == '\n' && buffer[ret - 1] == '\r')
	return (st);
    }
  while ((tmp = read(fd, buffer, READ_SIZE)) > 0 && (ret = -1))
    {
      buffer[tmp] = '\0';
      st = cp_buffer((const char *)buffer, st, 0, 0);
      while (buffer[++ret] != '\0')
	if (buffer[ret] == '\n' && buffer[ret - 1] == '\r')
	  return (st);
    }
  if (st[0] != '\0')
    return (st);
  free(st);
  return (NULL);
}
