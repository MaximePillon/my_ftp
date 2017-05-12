/*
** function_define.h for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/includes/function_define.h
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 07:57:10 2017 Maxime PILLON
** Last update Tue May 09 07:57:10 2017 Maxime PILLON
*/

#ifndef PSU_2016_MYFTP_FUNCTION_DEFINE_H
# define PSU_2016_MYFTP_FUNCTION_DEFINE_H

# include		<arpa/inet.h>
# include		<sys/types.h>
# include		<netinet/in.h>
# include		<sys/socket.h>

# ifndef		READ_SIZE
#  define		READ_SIZE	(256)
# endif			/* !READ_SIZE */

# ifndef		MAX_CONNECTION
#  define		MAX_CONNECTION	(42)
# endif			/* !MAX_CONNECTION */

typedef struct s_func	t_func;

typedef struct		s_serv
{
  char			*pathname;
  int			port;
  int			mysocket;
  struct sockaddr_in	dest;
  struct sockaddr_in	serv;
  socklen_t		socksize;
  size_t		nb_connections;
  int			child[MAX_CONNECTION];
}		t_serv;

typedef struct	s_child
{
  char		*username;
  char		*password;
  char		*command;
}		t_child;

typedef struct	s_func
{
  const char	*keyword;
  int		(*funcptr)(int, t_child *);
}		t_func;

#endif /* !PSU_2016_MYFTP_FUNCTION_DEFINE_H */
