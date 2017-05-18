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
#include		<netdb.h>
#include		"server.h"

t_data			*data_active(t_address *address)
{
  t_data		*transfer;
  struct protoent *pe;

  pe = getprotobyname("TCP");
  if (!address)
    return (NULL);
  transfer = malloc(sizeof(t_data));
  if (!transfer)
    return (NULL);
  transfer->socksize = sizeof(struct sockaddr_in);
  transfer->data_socket = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  transfer->serv.sin_family = AF_INET;
  transfer->serv.sin_port = htons((uint16_t)address->port);
  transfer->serv.sin_addr.s_addr = inet_addr(address->addr);
  return (transfer);
}

t_data			*data_connection_initializer()
{
  t_data		*transfer;

  transfer = malloc(sizeof(t_data));
  transfer->port = DATA_CONNECTION_PORT;
  if (!transfer)
    return (NULL);
  transfer->socksize = sizeof(struct sockaddr_in);
  transfer->serv.sin_family = AF_INET;
  transfer->serv.sin_addr.s_addr = htonl(INADDR_ANY);
  transfer->serv.sin_port = htons((uint16_t)transfer->port);
  transfer->data_socket = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
  if (transfer->data_socket == -1)
    return (NULL);
  if (bind(transfer->data_socket, (struct sockaddr *)&transfer->serv, sizeof(struct sockaddr)))
    return (NULL);
  if (listen(transfer->data_socket, 1))
    return (NULL);
  return (transfer);
}

int			initializer_server(t_serv *server)
{
  server->socksize = sizeof(struct sockaddr_in);
  memset(&(server->serv), 0, sizeof(struct sockaddr_in));
  server->serv.sin_family = AF_INET;
  server->serv.sin_addr.s_addr = htonl(INADDR_ANY);
  server->serv.sin_port = htons((uint16_t)server->port);
  server->mysocket = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
  if (server->mysocket == -1)
    return (-1);
  if (bind(server->mysocket, (struct sockaddr *)&server->serv, sizeof(struct sockaddr)))
    return (-1);
  if (listen(server->mysocket, 1))
    return (-1);
  memset(server->child, 0, MAX_CONNECTION);
  server->nb_connections = 0;
  return (0);
}

int			initialize_process(int value, t_serv *serv)
{
  int			cpt;

  cpt = 0;
  while (cpt < MAX_CONNECTION && serv->child[cpt] != 0)
    ++cpt;
  serv->child[cpt] = fork();
  if (serv->child[cpt] == -1)
  {
    perror("fork");
    return (-1);
  }
  if (serv->child[cpt] == 0)
    child_exec(value);
  return (0);
}

t_child			*initialize_child()
{
  t_child		*child;

  child = malloc(sizeof(t_child));
  if (child == NULL)
    return (NULL);
  child->username = NULL;
  child->password = NULL;
  child->command = NULL;
  child->mode = NONE;
  return (child);
}