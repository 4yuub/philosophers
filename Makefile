NAME = philo
BONUS_NAME = philo_bonus
INC = includes/
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
COMMON = ft_atoi.c time.c
INIT = init_table.c get_philos.c
ROUTIN = start_routin.c routin.c check.c
SRCS =	$(addprefix common_utils/, $(COMMON))\
		$(addprefix init/, $(INIT))\
		$(addprefix routin/, $(ROUTIN))\
		garbage.c\
		philo.c
OBJS = $(SRCS:.c=.o)

BONUS = check.c do_routin.c init.c philo_bonus.c pid_list.c wait.c
BONUS_SRCS =	$(addprefix common_utils/, $(COMMON))\
				$(addprefix bonus/, $(BONUS))\
				garbage.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)
	@echo done\!

bonus:$(BONUS_OBJS)
	@$(CC) $(CFLAGS) -pthread $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo done\!


%.o:%.c $(INC)/philo.h
	@echo compiling...
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo object files removed successfully

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo philo program removed successfully

re: fclean all
