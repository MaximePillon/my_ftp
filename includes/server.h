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

# include	<stdbool.h>
# include	"define.h"

/*
** Parsing function
*/
int			param_parsing(int ac, char **av, t_serv *serv);
int			read_command(int consocket, t_child *child);
char			*get_next_line(int fd);
void			clear_arg(char *str);

/*
** Error management function
*/
int			throw_error(char *error);
int			throw_child_error(int consocket);

/*
** Server management function
*/
int			launch_server(t_serv *serv);
int			child_exec(int consocket);
void			respond(char *code, char *string, int consocket);
int			quit_cmd(int consocket);

/*
** initializer function
*/
int			initializer_server(t_serv *server);
int			initialize_process(int value, t_serv *server);
void			initialize_func_tab(t_child *child);
t_child			*initialize_child();
t_data			*data_connection_initializer();
t_data			*data_active(t_address *address);


/*
** Authentication & right function
*/
bool		is_authenticated(t_child *child);
bool		has_username(t_child *child);

/*
** Execution function
*/
int			user(int consocket, t_child *child); //todo
int			pass(int consocket, t_child *child); //todo
int			cwd(int consocket, t_child *child);  //todo
int			cdup(int consocket, t_child *child); //todo
int			quit(int consocket, t_child *child); //todo
int			dele(int consocket, t_child *child); //todo
int			pasv(int consocket, t_child *child); //todo
int			port(int consocket, t_child *child); //todo
int			help(int consocket, t_child *child); //todo
int			noop(int consocket, t_child *child); //todo
int			retr(int consocket, t_child *child); //todo
int			stor(int consocket, t_child *child); //todo
int			smnt(int consocket, t_child *child); //todo
int			stou(int consocket, t_child *child); //todo
int			rmd(int consocket, t_child *child);  //todo
int			mkd(int consocket, t_child *child);  //todo
int			list(int consocket, t_child *child); //todo
int			pwd(int consocket, t_child *child);  //todo
int			syst(int consocket, t_child *child); //todo
int			sys_error(int consocket, t_child *child); //todo

/*
** Global variable server, used to handle SIGINT, SIGPIP...
*/
extern t_serv		*g_serv;

/*
** Constant configuration tab, used for execution
*/
extern const t_func	g_func_tab[];

/*
** Global variable child, used to handle SIGINT, SIGPIP...
*/
extern int		g_child_consocket;

#endif /* !PSU_2016_MYFTP_SERVER_H */
