NAME = philo
NAME_BONUS = philo_bonus
SRCS = philo_mandatory/*.c
SRCS_BONUS = philo_bonus_folder/*.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RACEFLACGS = -g -fsanitize=thread
##########################↓MANDATORY PART↓######################################
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo filozoflar yemek için hazır!

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
##########################↑MANDATORY PART↑######################################
##########################↓DATA RACE CHECK↓#####################################
race:
	$(CC) $(CFLAGS) $(RACEFLACGS) $(SRCS) -o philo_race

racebonus:
	$(CC) $(CFLAGS) $(RACEFLACGS) $(SRCS_BONUS) -o bonus_race
##########################↑DATA RACE CHECK↑#####################################
##########################↓BONUS PART↓##########################################
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRCS_BONUS)
	@$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)
	@echo filozoflar yemek için hazır hem de bonus!

fclean_bonus:
	@rm -rf $(NAME_BONUS)

rebonus: fclean_bonus bonus
##########################↑BONUS PART↑##########################################
fclean_all: fclean fclean_bonus

.PHONY: all clean fclean re bonus fclean_bonus fclean_all rebonus racebonus race
################################################################################