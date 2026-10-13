
NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_SRCS = $(MLX_DIR)/mlx_init.c $(MLX_DIR)/mlx_new_window.c \
	$(MLX_DIR)/mlx_pixel_put.c $(MLX_DIR)/mlx_loop.c \
	$(MLX_DIR)/mlx_mouse_hook.c $(MLX_DIR)/mlx_key_hook.c \
	$(MLX_DIR)/mlx_expose_hook.c $(MLX_DIR)/mlx_loop_hook.c \
	$(MLX_DIR)/mlx_int_anti_resize_win.c \
	$(MLX_DIR)/mlx_int_do_nothing.c \
	$(MLX_DIR)/mlx_int_wait_first_expose.c \
	$(MLX_DIR)/mlx_int_get_visual.c $(MLX_DIR)/mlx_flush_event.c \
	$(MLX_DIR)/mlx_string_put.c $(MLX_DIR)/mlx_set_font.c \
	$(MLX_DIR)/mlx_new_image.c $(MLX_DIR)/mlx_get_data_addr.c \
	$(MLX_DIR)/mlx_put_image_to_window.c \
	$(MLX_DIR)/mlx_get_color_value.c $(MLX_DIR)/mlx_clear_window.c \
	$(MLX_DIR)/mlx_xpm.c $(MLX_DIR)/mlx_int_str_to_wordtab.c \
	$(MLX_DIR)/mlx_destroy_window.c \
	$(MLX_DIR)/mlx_int_param_event.c \
	$(MLX_DIR)/mlx_int_set_win_event_mask.c $(MLX_DIR)/mlx_hook.c \
	$(MLX_DIR)/mlx_rgb.c $(MLX_DIR)/mlx_destroy_image.c \
	$(MLX_DIR)/mlx_mouse.c $(MLX_DIR)/mlx_screen_size.c \
	$(MLX_DIR)/mlx_destroy_display.c
MLX_FLAGS = -lXext -lX11 -lm -lz

SRCS = main.c events.c fractol.c render.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): $(MLX_SRCS) $(MLX_DIR)/Makefile $(MLX_DIR)/Makefile.mk $(MLX_DIR)/configure
	$(MAKE) -C $(MLX_DIR)

%.o: %.c fractol.h libft/libft.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re norm
