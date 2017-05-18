##
## Makefile for libsfml in /home/loens_g/rendu/TEK2/CPP/cpp_arcade
## 
## Made by loens_g
## Login   <loens_g@epitech.net>
## 
## Started on  Thu Apr  6 21:08:23 2017 loens_g
## Last update Fri Apr  7 19:44:06 2017 loens_g
##

INCLUDE		= 	-Iincludes/

RM		=	rm -rf

CFLAGS		+=	$(INCLUDE)

CFLAGS		+=	-W -Wextra -Wall -Werror

CC		=	gcc

DEBUG		?=	0

ifeq	($(DEBUG), 1)
	CC	=	gcc
	CFLAGS	+=	-g -ggdb3
endif

NAME		=	server

SRCS		=	sources/main.c \
                        sources/parser.c \
                        sources/throw_errror.c \
                        sources/initializer.c \
                        sources/server.c \
                        sources/get_next_line.c \
                        sources/g_func_tab.c \
                        sources/respond.c \
                        sources/requirement.c \
                        sources/cmd/cdup.c \
                        sources/cmd/cwd.c \
                        sources/cmd/list.c \
                        sources/cmd/noop.c \
                        sources/cmd/pass.c \
                        sources/cmd/pasv.c \
                        sources/cmd/port.c \
                        sources/cmd/pwd.c \
                        sources/cmd/quit.c \
                        sources/cmd/sys_error.c \
                        sources/cmd/user.c \
                        sources/cmd/dele.c \
                        sources/cmd/mkd.c \
                        sources/cmd/retr.c \
                        sources/cmd/rmd.c \
                        sources/cmd/smnt.c \
                        sources/cmd/stor.c \
                        sources/cmd/stou.c \
                        sources/cmd/help.c \
                        sources/cmd/syst.c

OBJS		=	 $(SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o:	%.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(CLI)

re:	fclean
	@$(MAKE) all

.PHONY:	 all clean fclean re

-include	$(DEPS)
