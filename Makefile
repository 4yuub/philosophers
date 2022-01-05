NAME = philo
INC = includes
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
COMMON = ft_atoi.c
INIT = init_table.c get_philos.c
SRCS =	$(addprefix common_utils/, $(COMMON))\
		$(addprefix init/, $(INIT))\
		garbage.c\
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
