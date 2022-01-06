NAME = philo
INC = includes
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
COMMON = ft_atoi.c time.c
INIT = init_table.c get_philos.c
ROUTIN = start_routin.c routin.c
SRCS =	$(addprefix common_utils/, $(COMMON))\
		$(addprefix init/, $(INIT))\
		$(addprefix routin/, $(ROUTIN))\
		garbage.c\
		philo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)
	@echo done\!

%.o:%.c $(INC)
	@echo compiling...
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	@$(RM) $(OBJS)
	@echo object files removed successfully

fclean: clean
	@$(RM) $(NAME)
	@echo philo program removed successfully

re: fclean all
