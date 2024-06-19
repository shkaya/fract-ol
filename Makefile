CC = gcc
NAME = fractol
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = minilibx-linux/libmlx_Darwin.a -L/usr/X11/lib -lX11 -lXext -lm
SRCS = init_mlx.c \
	mandelbrot.c \
	julia.c \
	handle_julia.c \
	handle_mandelbrot.c \
	utils.c \
	atof.c	\

OBJS = $(SRCS:%.c=%.o);

# この下のターゲットが実行されないのはなぜ？
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# 依存ファイルにOBJSを指定するのを忘れていた。
$(NAME): $(OBJS)
		$(MAKE) -C ./minilibx-linux
		$(CC) $(CFLAGS) main.c $(LDFLAGS) $(OBJS)

clean:
		$(MAKE) clean -C ./minilibx-linux
		rm -f *.o

.PHONY: all clean