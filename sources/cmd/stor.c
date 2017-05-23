/*
** stor.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/stor.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:33:48 2017 Maxime PILLON
** Last update Wed May 10 14:33:48 2017 Maxime PILLON
*/

#include		<string.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<fcntl.h>
#include		"server.h"

int			read_data(int consocket, t_child *child,
				     int serv_socket, int file)
{
  char			buf[1024];
  char			buf1[1024];
  ssize_t		size;
  ssize_t		size1;

  size = read(consocket, buf, 1024);
  while (size > 0)
  {
    size1 = read(consocket, buf1, 1024);
    if (size1 > 0)
      write(file, buf, (size_t)size);
    else
    {
      if (buf[size - 2] == '\r' && buf[size - 1] == '\n')
	write(file, buf, ((size_t) size - 2));
      else
	write(file, buf, (size_t)size);
    }
    strncpy(buf, buf1, (size_t)size1);
    size = size1;
  }
  close(consocket);
  respond("226", "Closing data connection.", serv_socket);
  free(child->data);
  return (0);
}

static int		communication(int consocket, t_child *child, int file)
{
  int			datasocket;

  respond("150", "Data connection already open; transfer starting.", consocket);
  if (child->mode == PASSIVE)
  {
    datasocket = accept(child->data->data_socket,
			(struct sockaddr *) &(child->data->dest),
			&(child->data->socksize));
    return (read_data(datasocket, child, consocket, file));
  }
  connect(child->data->data_socket, (struct sockaddr*) &child->data->serv,
	  child->data->socksize);
  return (read_data(child->data->data_socket, child, consocket, file));
}

int			stor(int consocket, t_child *child)
{
  int			file;

  if (!is_authenticated(child))
  {
    respond("530", "Not logged in.", consocket);
    return (0);
  }
  if (child->mode == NONE)
  {
    respond("425", "425 Use PORT or PASV first.", consocket);
    return (0);
  }
  clear_arg(child->command);
  file = open(child->command + 5,
	      O_WRONLY | O_CREAT | O_TRUNC,
	      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (file == -1)
  {
    respond("550", "Requested action not taken.", consocket);
    return (-1);
  }
  communication(consocket, child, file);
  close(file);
  return (0);
}