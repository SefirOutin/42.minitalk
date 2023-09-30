
NAMEC			=	client
NAMES			=	server
LIBFT			=	libft/libft.a

SRC_DIR 		=	src/
SRCC_FILES		=	client.c
SRCS_FILES		=	server.c
SRCC			=	$(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS			=	$(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC			=	${SRCC:.c=.o}
OBJS			=	${SRCS:.c=.o}

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g3
INCLUDE			=	-I include

all:			$(NAMEC) $(NAMES)

$(NAMEC):		$(OBJC)
					$(MAKE) -C libft
					$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) $(LIBFT) -o $(NAMEC)

$(NAMES):		$(OBJS)
					$(MAKE) -C libft
					$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT) -o $(NAMES)

clean:
				$(MAKE) fclean -C libft
				rm -rf ${OBJC} $(OBJS)
		
fclean:			clean
					rm -rf $(NAMEC) $(NAMES)
		
re:				fclean all

.PHONY:			all clean fclean re