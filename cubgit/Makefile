NAME = libcub.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra 

CMLXFLAGS = -lmlx -framework OpenGL -framework AppKit

AR = ar -rc

RAN = ranlib

DIR = engine/

SRCS =	cub3d.c \
		get_next_line_utils.c \
		get_next_line.c \
		map_parsing.c \
		parsing.c \
		utils.c \
		utils2.c \
		save.c

CUB_DIRSRCS = $(addprefix ${DIR}, ${SRCS})

OBJS = ${CUB_DIRSRCS:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@${RAN} ${NAME}
	@mv ${NAME} engine
	@make -C mlx
	@cp mlx/libmlx.dylib .
	@${CC} ${CMLXFLAGS} ./engine/${NAME} engine/main.c libmlx.dylib -o cub3D

clean:
	@${RM} ${OBJS}
	@make clean -C mlx

fclean: clean
	@${RM} ./engine/${NAME}
	@${RM} libmlx.dylib
	@${RM} cub3d

re: fclean all

.PHONY: all clean fclean re