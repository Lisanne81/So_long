#PATH_SRC = ./so_long/
PATH_GNL = gnl/
PATH_INC = includes/
#PATH_MAP = $(PATH_SRC)map/
#PATH_UTILS = $(PATH_SRC)utils/
#PATH_ERRORS = $(PATH_SRC)errors/
#PATH_GAME = $(PATH_SRC)game/
PATH_MLX = /mlx
#PATH_OBJS = ./objs/


NAME 			= so_long
SRC_FILES 		= $(PATH_SRC)main.c $(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c
HEADER_MLX 		= mlx.h
HEADERS			= ./includes/*.h

OBJS_FILES 		= ${SRC_FILES:.c=.o}

MLX_LIB 		= /mlx

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g -fsanitize=address

RM 				= rm -f

all:			${NAME}

$(NAME):		${OBJS_FILES}
				@make -C mlx
				@cp mlx/libmlx.dylib ./
				@echo "\033[38;5;33mcompiling project: \033[0m"
				$(CC) $(CFLAGS) $(OBJS_FILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
				@echo "\033[38;5;37mcreating MAGIC \033[0m"
				@echo "\033[38;5;38m BOOM! that how we do it!\033[0m"
				@echo "\033[38;5;51mMAKE life easy! :-)\033[m"

%.o: %.c
				echo $@
				echo $<
				${CC} ${CFLAGS} -I./mlx -I./includes -o $@ -c $<
			
clean:
				@${RM} ${OBJS_FILES}
				@echo "\033[38;5;120msweep sweep: object files \033[0m"

fclean:			clean
				@${RM} ${NAME}
				@echo "\033[38;5;180mexecutable?! gone! \033[0m"

re:				fclean all
				@echo "\033[38;5;197mall done!\033[0m"
				@echo "\033[38;5;200mThank you for your time!\033[0m"
.PHONY: 		all fclean clean re
