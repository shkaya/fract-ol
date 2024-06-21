CC = gcc
NAME = fractol
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = minilibx-linux/libmlx_Darwin.a -L/usr/X11/lib -lX11 -lXext -lm
SRCS = src/init_mlx.c \
	src/mandelbrot.c \
	src/julia.c \
	src/burningship.c \
	src/handle.c \
	src/utils.c \
	src/atof.c	\

OBJS = $(SRCS:%.c=%.o)

# この下のターゲットが実行されないのはなぜ？
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# 依存ファイルにOBJSを指定するのを忘れていた。
$(NAME): $(OBJS)
		$(MAKE) -C ./minilibx-linux
		$(CC) $(CFLAGS) main.c $(LDFLAGS) $(OBJS) -o $(NAME)

clean:
		$(MAKE) clean -C ./minilibx-linux
		rm -f $(OBJS)
		rm -f $(NAME)

re: clean all

.PHONY: all clean re