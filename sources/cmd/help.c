/*
** help.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/cmd/help.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 14:30:15 2017 Maxime PILLON
** Last update Wed May 10 14:30:15 2017 Maxime PILLON
*/

#include		<stdio.h>
#include		"server.h"

int			help(int consocket, t_child *child)
{
  respond("21", "Help message.", consocket);
  dprintf(consocket, " USER PASS CWD CDUP QUIT DELE\n");
  dprintf(consocket, " PASV PORT HELP NOOP RETR STOR\n");
  dprintf(consocket, " SMNT STOU RMD MKD LIST PWD SYST\r\n");
  respond("21", "Help message.", consocket);
  (void)child;
  return (0);
}