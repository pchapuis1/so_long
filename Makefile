SRCS		=	so_long.c \
				end.c \
				parsing.c \
				check_map.c \
				get_next_line.c \
				get_next_line_utils.c \
				move.c \
				print.c \
				replace.c \
				init.c \
				path.c \
				check_doable.c

SRCS_BONUS	=	so_long_bonus.c \
				end_bonus.c \
				parsing_bonus.c \
				check_map_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				move_bonus.c \
				print_bonus.c \
				replace_bonus.c \
				init_bonus.c \
				path_bonus.c \
				check_doable_bonus.c

OBJS		= ${addprefix ./objs/, ${SRCS:.c=.o}}

OBJS_BONUS	= ${addprefix ./objs_bonus/, ${SRCS_BONUS:.c=.o}}

NAME		= so_long

NAME_BONUS	= so_long_bonus

CC			= cc

RM 			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -g3

LIBFT_LIB	= libft/libft.a

MLX_LIB		= mlx_linux/libmlx.a

MLX_FLAG	= -Lmlx_linux -L/usr/lib -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

MLX_EX		= $(MLX_LIB) $(MLX_FLAG)

MLX_HEADERS = mlx_linux/mlx.h mlx_linux/mlx_int.h

LIBFT_HEADERS = libft/libft.h

HEADERS		= includes/so_long.h 

HEADERS_BONUS = includes/so_long_bonus.h

all:		mlx libft ${NAME}

mlx:		
			$(MAKE) -sC mlx_linux

libft:		
			$(MAKE) -sC libft

./objs/%.o:	./srcs/%.c ${HEADERS} ${MLX_HEADERS} ${LIBFT_HEADERS}
			@mkdir -p objs
			${CC} ${CFLAGS} -c $< -o $@ -Imlx_linux -Ilibft -Iincludes

./objs_bonus/%.o:	./srcs_bonus/%.c ${HEADERS_BONUS} ${MLX_HEADERS} ${LIBFT_HEADERS}
					@mkdir -p objs_bonus
					${CC} ${CFLAGS} -c $< -o $@ -Imlx_linux -Ilibft -Iincludes

${NAME}: 	${OBJS} Makefile ${MLX_LIB} ${LIBFT_LIB}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB} ${MLX_EX}

${NAME_BONUS}:	${OBJS_BONUS} Makefile ${MLX_LIB} ${LIBFT_LIB}
				${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT_LIB} ${MLX_EX}

bonus:		mlx libft
			${MAKE} ${NAME_BONUS}

clean:
			$(MAKE) clean -C libft/
			$(MAKE) clean -C mlx_linux/
			${RM} objs
			${RM} objs_bonus

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME_BONUS}
			${RM} ${LIBFT_LIB}
			${RM} ${MLX_LIB}

re:			fclean all

.PHONY:		all clean fclean re bonus mlx libft