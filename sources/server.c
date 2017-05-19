/*
** server.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/server.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 08:28:14 2017 Maxime PILLON
** Last update Tue May 09 08:28:14 2017 Maxime PILLON
*/

#include		<signal.h>
#include                <stdio.h>
#include                <unistd.h>
#include                <stdlib.h>
#include		<string.h>
#include                "server.h"

int			g_child_consocket;

static void		signalHandler(int signum)
{
  close(g_child_consocket);
  exit(signum);
}

int			launch_server(t_serv *serv)
{
  int			value;

  value = 1;
  if (initializer_server(serv))
    return (-1);
  if (chdir(serv->pathname))
    return throw_error("can't move to the wanted directory");
  while (value)
  {
    value = accept(serv->mysocket,
		   (struct sockaddr *) &(serv->dest), &(serv->socksize));
    if (initialize_process(value, serv))
      return (-1);
  }
  close(serv->mysocket);
  return (0);
}

static int		exec_command(int consocket, t_child *child)
{
  int			cpt;

  cpt = 0;
  while (cpt != 19 &&
    strncmp(g_func_tab[cpt].keyword,
	    child->command, strlen(g_func_tab[cpt].keyword)) != 0)
    ++cpt;
  return (g_func_tab[cpt].funcptr(consocket, child));

}

static void		call_child_signal()
{
  signal(SIGINT, signalHandler);
  signal(SIGABRT, signalHandler);
  signal(SIGTERM, signalHandler);
  signal(SIGSEGV, signalHandler);
  signal(SIGQUIT, signalHandler);
}

int			child_exec(int consocket)
{
  t_child		*child;
  int			tmp;

  g_child_consocket = consocket;
  call_child_signal();
  child = initialize_child();
  if (child == NULL)
    return throw_child_error(consocket);
  write(consocket, "220 Service ready for new user.\r\n", 33);
  while (consocket)
  {
    if (read_command(consocket, child))
      return throw_child_error(consocket);
    tmp = exec_command(consocket, child);
    free(child->command);
    if (tmp == -1)
      return throw_child_error(consocket);
    if (tmp == 1)
      return quit_cmd(consocket);
  }
  return (0);
}