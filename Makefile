CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = minilibx-linux/libmlx_Darwin.a
LDFLAGS = -L/usr/X11/lib -lX11 -lXext -lm

all:
	$(CC) $(CFLAGS) fractol.c $(LIB) $(LDFLAGS)

Italia:
	$(CC) $(CFLAGS) Italia.c $(LIB) $(LDFLAGS)

France:
	$(CC) $(CFLAGS) France.c $(LIB) $(LDFLAGS)