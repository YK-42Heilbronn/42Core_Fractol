NAME=fractol
TEST=test-fractol

CC=cc
CFLAGS=-Wall -Wextra -Werror -Wunreachable-code -Ofast

# HEADERS=-I./include -I$(MLX_LIB)/include
HEADERS=-I$(MLX_LIB)/include
OBJS_DIR=./objs
LIBS=./libs
LIBFT_DIR=$(LIBS)/libft
LIBFT=$(LIBFT_DIR)/libft.a
# PRINTF=$(LIBS)/printf
# PRINTF_LIB=$(PRINTF)/ft_printf.a
MLX_LIB=$(LIBS)/MLX42
MLX42=$(MLX_LIB)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC_HEADER=fractol.h
# TEST_SRC_HEADER=test_fractol.h
SRCS=1-coordinates/coordinates.c 1-coordinates/ops.c \
	2-complex_number/complex.c \
	3-colors/color.c \
	4-sets/mandelbrot.c 4-sets/julia.c 4-sets/routines.c \
	5-view_controls/data.c 5-view_controls/move.c 5-view_controls/zoom.c\
	utils/strtodouble.c \
	fractol.c
# TEST_SRCS=test_mandelbrot.c
OBJ_FILES = $(SRCS:.c=.o)  # creates .o file names as .c, does not compile
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJ_FILES))
# mlx_compile =

all: libmlx42 $(NAME)
test: libmlx42 $(TEST)

libmlx42:
	@cmake $(MLX_LIB) -B $(MLX_LIB)/build && make -C $(MLX_LIB)/build -j4

$(TEST): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) $(MLX42) -o $(TEST)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(SRC_HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

re:
	@make fclean
	@make all

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_LIB)/build
	@make -C $(LIBFT_DIR) fclean

git-mlx:
	@cd $(LIBS) && git clone https://github.com/codam-coding-college/MLX42.git
	@cd ../

.PHONY: re clean fclean all test git-mlx
