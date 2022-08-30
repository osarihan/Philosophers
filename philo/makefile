CC = gcc
CFLAGS =  -Wall -Wextra -Werror -pthread
NAME = philo
SRCS = *.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)
re: clean all