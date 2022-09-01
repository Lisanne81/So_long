NAME 			= so_long
SRC_FILES 		= main.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
					create_map.c parse_map.c error_free_exit.c terminal_image.c \
					load_image.c clean_up.c setup_game.c update_map_components.c \
					check_input_map.c load_png.c animation.c actions.c init_game.c \
					image_on_window.c game_on_window.c action_moves.c 
HEADERS			= ./includes/*.h
LIBFT			= ./libft/libft.a

DIR_OBJ			= ./obj
OBJS_FILES 		= $(addprefix $(DIR_OBJ)/, ${SRC_FILES:.c=.o})

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra #-g -fsanitize=address

RM 				= rm -f

#-------------------------------------------#
BLUE			=	\033[38;5;30m
GREEN			= 	\033[38;5;43m
RED				=	\033[38;5;124m
PINK			= 	\033[38;5;167m
ORANGE			=	\033[38;5;208m
NO_COLOR		=	\033[0m
#-------------------------------------------#

all:			$(LIBFT) ${NAME} ${HEADERS}

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):		${OBJS_FILES}
				@make -C MLX42
				@cp MLX42/libmlx42.a ./
				@echo "\033[38;5;33mcompiling project: \033[0m"
				@$(CC) $(CFLAGS) $(OBJS_FILES) $(LIBFT) libmlx42.a -I include -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)
				@echo "\033[38;5;37mGame: Commander Keen Game Boy collecter\033[0m"
				@echo "\033[38;5;38m use⬅️ ⬆️ ⬇️ ➡️ or WASD to move in space\033[0m"
				@echo "\033[38;5;51mBeware of your Enemies!\033[m"
				@echo "\033[38;5;51mCollect all Game Boys and come back to earth!\033[m"



$(DIR_OBJ)/%.o: %.c includes/so_long.h
				@mkdir -p $(@D)
				@$(CC) -o $@ -c $< $(CFLAGS)
				@# echo $@
				@# echo $<
				@# ${CC} ${CFLAGS} -o $@ -c $<
$(LIBFT):
				printf "\033c"
				@echo "☝️ $(BLUE)First of: Make LIBFT$(NO_COLOR) 📖"
				@$(MAKE) -C./libft
clean:
				@rm -rf $(DIR_OBJ) res subject
				@${RM} ${OBJS_FILES} ./gnl/*.o
				@$(MAKE) clean -C./libft
				@$(MAKE) clean -C./MLX42

				@echo "\033[38;5;120msweep sweep: object files \033[0m"

fclean:			clean
				${RM} ${NAME} *.a
				$(MAKE) fclean -C ./libft
				$(MAKE) fclean -C ./MLX42
				@echo "\033[38;5;180mexecutable?! gone! \033[0m"

re:				fclean all
				@echo "\033[38;5;197mall done!\033[0m"
				@echo "\033[38;5;185mThank you for your time!\033[0m"
.PHONY: 		all fclean clean re

play:

				./so_long ./maps/map_7.ber 
				./so_long ./maps/map_10.ber 
				./so_long ./maps/map_15.ber 
				./so_long ./maps/map_20.ber 
				./so_long ./maps/map_big.ber 
				./so_long ./maps/map_tiny.ber 