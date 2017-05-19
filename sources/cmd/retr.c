/*
** retr.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/retr.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:33:10 2017 Maxime PILLON
** Last update Wed May 10 14:33:12 2017 Maxime PILLON
*/

#include		<string.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<fcntl.h>
#include		"server.h"

int			push_data(int consocket, t_child *child,
				     int serv_socket, int file)
{
  char			buf[1024];
  ssize_t		size;

  size = read(file, buf, 1024);
  while (size > 0)
  {
    write(consocket, buf, (size_t)size);
    size = read(file, buf, 1024);
  }
  close(file);
  close(consocket);
  respond("226", "Closing data connection.", serv_socket);
  free(child->data);
  child->data = NULL;
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
    return (push_data(datasocket, child, consocket, file));
  }
  connect(child->data->data_socket, (struct sockaddr*) &child->data->serv,
	  child->data->socksize);
  return (push_data(child->data->data_socket, child, consocket, file));
}

int			retr(int consocket, t_child *child)
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
  file = open(child->command + 5, O_RDONLY);
  if (file == -1)
  {
    respond("550", "Requested action not taken.", consocket);
    return (-1);
  }
  return (communication(consocket, child, file));
}