/*
** g_func_tab.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/g_func_tab.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed May 10 13:11:50 2017 Maxime PILLON
** Last update Wed May 10 13:11:50 2017 Maxime PILLON
*/

#include		<stddef.h>
#include		"server.h"

const t_func		g_func_tab[] =
  {
    {"USER", user},
    {"PASS", pass},
    {"CWD", cwd},
    {"CDUP", cdup},
    {"QUIT", quit},
    {"DELE", dele},
    {"PASV", pasv},
    {"PORT", port},
    {"HELP", help},
    {"NOOP", noop},
    {"RETR", retr},
    {"STOR", stor},
    {"SMNT", smnt},
    {"STOU", stou},
    {"RMD", rmd},
    {"MKD", mkd},
    {"LIST", list},
    {"PWD", pwd},
    {"SYST", syst},
    {NULL, sys_error}
  };