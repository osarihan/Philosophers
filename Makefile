NAME = philo
NAME_BONUS = philo_bonus
SRCS = philo_mandatory/*.c
SRCS_BONUS = philo_bonus_folder/*.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLACGS = -g -fsanitize=thread

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo filozoflar yemek için hazır!

race:
	$(CC) $(CFLAGS) $(RACEFLACGS) $(SRCS) -o philo_race

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: $(NAME_BONUS)

racebonus:
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(RACEFLACGS) -o race_bonus	

$(NAME_BONUS):
	@$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)
	@echo filozoflar yemek için hazır hem de bonus!	
fclean_bonus:
	@rm -rf $(NAME_BONUS)

fclean_all: fclean fclean_bonus

rebonus: fclean_bonus bonus

.PHONY: all clean fclean re bonus fclean_bonus fclean_all rebonus
