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
  int			cpt;

  cpt = 0;
  while (cpt < MAX_CONNECTION)
  {
   if (g_serv->child[cpt] != 0)
     kill(g_serv->child[cpt], SIGINT);
    ++cpt;
  }
  exit(signum);
}

static void		call_signal()
{
  signal(SIGINT, signalHandler);
  signal(SIGABRT, signalHandler);
  signal(SIGTERM, signalHandler);
  signal(SIGSEGV, signalHandler);
  signal(SIGQUIT, signalHandler);
}

int			main(int ac, char **av)
{
  call_signal();
  g_serv = malloc(sizeof(t_serv));
  if (!g_serv)
    return (throw_error("Can't allocate data"));
  if (param_parsing(ac, av, g_serv))
    return (throw_error("argument issue"));
  if (launch_server(g_serv))
    return (throw_error("execution error"));
  return (0);
}
