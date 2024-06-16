CC = gcc
NAME = fractol
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = minilibx-linux/libmlx_Darwin.a -L/usr/X11/lib -lX11 -lXext -lm
SRCS = mlx.c \
	mandelbrot.c \
	julia.c \

OBJS = $(SRCS:%.c=%.o);

# この下のターゲットが実行されないのはなぜ？
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# 依存ファイルにOBJSを指定するのを忘れていた。
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) main.c $(LDFLAGS) $(OBJS)

clean:
		rm -f *.o

.PHONY: all clean