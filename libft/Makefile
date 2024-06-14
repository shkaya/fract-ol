CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -f
AR       = ar rcs
SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
	ft_striteri.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \

B_SRCS = ft_lstadd_back.c \
       ft_lstadd_front.c \
       ft_lstclear.c \
       ft_lstdelone.c \
       ft_lstiter.c \
       ft_lstlast.c \
       ft_lstmap.c \
       ft_lstnew.c \
       ft_lstsize.c \

OBJS     = $(SRCS:%.c=%.o)
B_OBJS   = $(B_SRCS:%.c=%.o)
NAME     = libft.a
# TARGET   = main.exe
# MAINFILE = mian.c
# CLIBS    = -L . -lft

ifeq ($(MAKECMDGOALS), bonus)
	OBJS += $(B_OBJS)
endif

all: $(NAME)

bonus:	$(NAME)

$(NAME): $(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(B_OBJS)

fclean: clean
				$(RM) $(NAME)

re:	fclean all

# comp: all
# 				$(CC) $(MAINFILE) $(CLIBS) -o $(TARGET)

.PHONY: all clean fclean re bonus