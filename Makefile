.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re sanitize

NAME					= fdf

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= fdf.h
HEADER_DEF				= keycode.h

DIR						= src/
SRC			 			= 	main/main.c \
							parsing/parsing.c \
							parsing/first_parsing.c \
							utils/free_manager.c \
							utils/fdf_utils.c \
							utils/ft_atoi_base.c \
							utils/ft_atoi.c \
							graphic/mlx_setup.c \
							graphic/mlx_utils.c \
							graphic/keyhook.c \
							graphic/keyhook_bis.c \
							graphic/draw_line.c \
							graphic/rotate.c \
							graphic/rotate_x.c \
							graphic/rotate_y.c \
							graphic/rotate_z.c \
														
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

	
GCC						= gcc
CFLAGS					= -Wall -Wextra -g3 -Werror 
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

MINILIB_DIR				= minilibx-linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz 

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) $(HEADER_DIR)/$(HEADER_DEF)
						@mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -O3 -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

sanitize :				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

lib:
						@make -C $(LIB_DIR)

minilibx:
						@make -C $(MINILIB_DIR)
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@make clean -C $(MINILIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)
						@make fclean -C $(MINILIB_DIR)

re:						fclean all
						$(MAKE) all