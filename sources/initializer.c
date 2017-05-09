/*
** initializer.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/initializer.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 08:43:40 2017 Maxime PILLON
** Last update Tue May 09 08:43:40 2017 Maxime PILLON
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"server.h"

int			initializer_server(t_serv *server)
{
  server->socksize = sizeof(struct sockaddr_in);
  memset(&(server->serv), 0, sizeof(struct sockaddr_in));
  server->serv.sin_family = AF_INET;
  server->serv.sin_addr.s_addr = htonl(INADDR_ANY);
  server->serv.sin_port = htons((uint16_t)server->port);
  server->mysocket = socket(AF_INET, SOCK_STREAM, 0);
  if (server->mysocket == -1)
    return (-1);
  if (bind(server->mysocket, (struct sockaddr *)&server->serv, sizeof(struct sockaddr)))
    return (-1);
  if (listen(server->mysocket, 1))
    return (-1);
  server->child = NULL;
  server->nb_connections = 0;
  return (0);
}

int			initialize_process(int value, t_serv *serv)
{
  serv->nb_connections += 1;
  serv->child = realloc(serv->child, serv->nb_connections);
  serv->child[serv->nb_connections - 1] = fork();
  if (serv->child[serv->nb_connections - 1] == -1)
  {
    perror("fork");
    return (-1);
  }
  if (serv->child[serv->nb_connections - 1] == 0)
    child_exec(value);
  return (0);
}