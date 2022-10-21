NAME	=	so_long
LIBFT	=	libft/libft.a
MLX		=	mlx/libmlx.a
MLB		=	-Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS	=	main.c helper.c find_map.c get_next_line.c get_next_line_utils.c test_map.c render.c movment.c
CC		=	gcc
OBJS	=	$(SRCS:.c=.o)
FLAGS	=	-Wall -Werror -Wextra -Imlx
.c.o	:
			$(CC) $(FLAGS) -Iincludes -c $< -o $(<:.c=.o)
$(NAME) :	$(OBJS)
			make -C ./libft
			make -C ./mlx
#			cp $(LIBFT) $(MLX) $(NAME)
			$(CC) $(FLAGS) $(OBJS) -Llibft -lft $(MLB) -o $(NAME)
all		:	$(NAME)
clean	:
			make clean -C ./libft
			make clean -C ./mlx
			rm -rf $(OBJS)
fclean	:	clean
			rm -rf $(NAME)
			make fclean -C ./libft
#			make fclean -C ./mlx
re		:	fclean all
.PHONY	:	clean fclean re all