/*
** main.c for  in /home/god/TEK2/MATH/207demography
**
** Made by Pillon maxime
** Login   <god@epitech.net>
**
** Started on  Tue May  9 08:35:19 2017 Pillon maxime
** Last update Tue May  9 08:35:21 2017 Pillon maxime
*/

#include		<stdlib.h>
#include		<signal.h>
#include		"server.h"


static void		signalHandler(int signum)
{
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
  t_serv		*new;

  callSignal();
  new = malloc(sizeof(t_serv));
  if (!new)
    return (throw_error("Can't allocate data"));
  if (param_parsing(ac, av, new))
    return (throw_error("argument issue"));
  if (launch_server(new))
    return (throw_error("execution error"));
  return (0);
}
