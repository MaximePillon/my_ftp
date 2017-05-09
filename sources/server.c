/*
** server.c for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/sources/server.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 08:28:14 2017 Maxime PILLON
** Last update Tue May 09 08:28:14 2017 Maxime PILLON
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"server.h"

int			launch_server(t_serv *serv)
{
  int			value;

  value = 1;
  if (initializer_server(serv))
    return (-1);
 while (value)
 {
   value = accept(serv->mysocket,
		  (struct sockaddr *)&(serv->dest), &(serv->socksize));
   if (initialize_process(value, serv))
     return (-1);
 }
}

int			child_exec(int consocket)
{
  while			(consocket)
  {
    printf("recieve the connection : %d\n", consocket);
  }
}



/*
 *
 *
 bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr));

  if (listen(mysocket, 1) == -1)
    return (-1);

  int consocket;
  if ((consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize)) == -1)
    return 1;

  while(consocket)
  {
    send(consocket, msg, strlen(msg), 0);
    char buf[MAXRCVLEN + 1];
    int len = recv(consocket, buf, MAXRCVLEN, 0);
    if (len == -1)
      return (1);
    buf[len] = '\0';
    printf("%s\n", buf);
    close(consocket);
    consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
  }
  close(mysocket);
  return EXIT_SUCCESS;
}
 *
 */