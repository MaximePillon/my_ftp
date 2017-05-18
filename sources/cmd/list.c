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
#include		<unistd.h>
#include		"server.h"

static int		exec_ls(int consocket)
{
  int			status;
  int			pid;
  char			*args[2];

  args[0] = "/bin/ls";
  args[1] = NULL;

  pid = fork();
  dup2(consocket, STDOUT_FILENO);
  if (pid == 0)
    execv(args[0], args);
  else
    wait(&status);
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

  if (child->mode == PASSIVE)
  {
    datasocket = accept(child->data->data_socket,
			(struct sockaddr *) &(child->data->dest),
			&(child->data->socksize));
    return (exec_ls(datasocket));
  }
  connect(child->data->data_socket, (struct sockaddr*) &child->data->serv,
	    child->data->socksize);
  return (exec_ls(child->data->data_socket));
}