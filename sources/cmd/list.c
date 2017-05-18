/*
** list.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/list.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:37:27 2017 Maxime PILLON
** Last update Wed May 10 14:37:27 2017 Maxime PILLON
*/

#include		<sys/types.h>
#include		<sys/wait.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"server.h"

static int		exec_ls(int consocket, t_child *child, int serv_socket)
{
  int			pid;
  char			*args[3];

  args[0] = "/bin/ls";
  args[1] = "-l";
  args[2] = NULL;

  pid = fork();
  if (pid == -1)
    return (-1);
  if (pid == 0)
  {
    dup2(consocket, STDOUT_FILENO);
    execv(args[0], args);
    exit(EXIT_SUCCESS);
  }
  respond("226", "Closing data connection.", serv_socket);
  close(consocket);
  free(child->data);
  child->data = NULL;

  return (0);
}

int			list(int consocket, t_child *child)
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
  respond("125", "Data connection already open; transfer starting.", consocket);
  if (child->mode == PASSIVE)
  {
    datasocket = accept(child->data->data_socket,
			(struct sockaddr *) &(child->data->dest),
			&(child->data->socksize));
    return (exec_ls(datasocket, child, consocket));
  }
  connect(child->data->data_socket, (struct sockaddr*) &child->data->serv,
	    child->data->socksize);
  return (exec_ls(child->data->data_socket, child, consocket));
}