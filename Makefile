NAME = philo
NAME_BONUS = philo_bonus
SRCS = philo_mandatory/*.c
SRCS_BONUS = philo_bonus_folder/philos/*.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo filozoflar yemek için hazır!

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: $(NAME_BONUS)
	@echo filozoflar yemek için hazır hem de bonus!

$(NAME_BONUS):
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)
	
fclean_bonus:
	@rm -rf $(NAME_BONUS)

rebonus: fclean_bonus bonus