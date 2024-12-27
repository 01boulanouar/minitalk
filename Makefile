CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

CLIENT_SRC = mandatory/client.c
SERVER_SRC = mandatory/server.c
UTILS_SRC = mandatory/utils/ft_printf.c mandatory/utils/number.c mandatory/utils/string.c

CLIENT_SRC_BONUS = bonus/client_bonus.c
SERVER_SRC_BONUS = bonus/server_bonus.c
UTILS_SRC_BONUS = bonus/utils/ft_printf_bonus.c bonus/utils/number_bonus.c bonus/utils/string_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
UTILS_OBJ_BONUS = $(UTILS_SRC_BONUS:.c=.o)

all : $(CLIENT_NAME) $(SERVER_NAME)

bonus : $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

mandatory/%.o : mandatory/%.c mandatory/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_NAME): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $@

$(SERVER_NAME): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $@

$(CLIENT_NAME_BONUS): $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS)
	$(CC) $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS) -o $@

$(SERVER_NAME_BONUS): $(SERVER_OBJ_BONUS) $(UTILS_OBJ_BONUS)
	$(CC) $(SERVER_OBJ_BONUS) $(UTILS_OBJ_BONUS) -o $@

clean :
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS) $(UTILS_OBJ_BONUS)

fclean : clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

re : fclean all

.PHONY : clean
.DEFAULT_RULE : all