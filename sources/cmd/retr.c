/*
** retr.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/retr.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:33:10 2017 Maxime PILLON
** Last update Wed May 10 14:33:12 2017 Maxime PILLON
*/

#include		"server.h"

int			push_data(int consocket, t_child *child, int serv_socket)
{
  (void)consocket;
  (void)child;
  (void)serv_socket;
  return (1);
}

int			retr(int consocket, t_child *child)
{
  int			datasocket;

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
  respond("150", "Data connection already open; transfer starting.", consocket);
  if (child->mode == PASSIVE)
  {
    datasocket = accept(child->data->data_socket,
			(struct sockaddr *) &(child->data->dest),
			&(child->data->socksize));
    return (push_data(datasocket, child, consocket));
  }
  connect(child->data->data_socket, (struct sockaddr*) &child->data->serv,
	  child->data->socksize);
  return (push_data(child->data->data_socket, child, consocket));
}