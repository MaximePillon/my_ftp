/*
** server.h for PSU_2016_myftp in /home/god/TEK2/NETWORK/PSU_2016_myftp/includes/server.h
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Tue May 09 07:04:09 2017 Maxime PILLON
** Last update Tue May 09 07:04:09 2017 Maxime PILLON
*/

#ifndef PSU_2016_MYFTP_SERVER_H
# define PSU_2016_MYFTP_SERVER_H

# include	"define.h"

/*
 ** Parsing function
 */
int			param_parsing(int ac, char **av, t_serv *serv);

/*
 ** Error management function
 */
int			throw_error(char *error);


/*
 ** Server management function
 */
int			launch_server(t_serv *serv);
int			child_exec(int consocket);

/*
 ** initializer function
 */
int			initializer_server(t_serv *server);
int			initialize_process(int value, t_serv *server);

#endif /* !PSU_2016_MYFTP_SERVER_H */
