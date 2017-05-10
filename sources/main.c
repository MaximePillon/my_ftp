/*
** main.c for  in /home/god/TEK2/MATH/207demography
**
** Made by Pillon maxime
** Login   <god@epitech.net>
**
** Started on  Tue May  9 08:35:19 2017 Pillon maxime
** Last update Tue May  9 08:35:21 2017 Pillon maxime
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<signal.h>
#include		"server.h"

t_serv			*g_serv;

static void		signalHandler(int signum)
{
  int			value;

  value = (int)g_serv->nb_connections;
  while (value - 1 >= 0)
  {
    if (g_serv->child[value - 1] != 0)
      kill(g_serv->child[value -1], SIGKILL);
    value--;
  }
  exit(signum);
}

static void		callSignal()
{
  signal(SIGINT, signalHandler);
  signal(SIGABRT, signalHandler);
  signal(SIGTERM, signalHandler);
  signal(SIGSEGV, signalHandler);
  signal(SIGQUIT, signalHandler);
}

int			main(int ac, char **av)
{
  callSignal();
  g_serv = malloc(sizeof(t_serv));
  if (!g_serv)
    return (throw_error("Can't allocate data"));
  if (param_parsing(ac, av, g_serv))
    return (throw_error("argument issue"));
  if (launch_server(g_serv))
    return (throw_error("execution error"));
  return (0);
}
