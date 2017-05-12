/*
** pwd.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/pwd.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:38:03 2017 Maxime PILLON
** Last update Wed May 10 14:38:03 2017 Maxime PILLON
*/

#include		<unistd.h>
#include		<limits.h>
#include		<string.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		"server.h"

int			pwd(int consocket, t_child *child)
{
  char buf[PATH_MAX];
  char *results;

  results = NULL;
  if (getcwd(buf, PATH_MAX) == NULL)
    return (-1);
  results = malloc(sizeof(char) * (strlen(buf) + 10));
  if (!results)
    return (-1);
  strcpy(results, buf);
  results = strcat(results, " created.");
  respond("257", results, consocket);
  free(results);
  results = NULL;
  return (0);
}