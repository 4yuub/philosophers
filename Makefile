NAME = philo
INC = includes
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
COMMON = ft_atoi.c
SRCS =	$(addprefix common_utils/, $(COMMON))\
		philo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

%.o:%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
