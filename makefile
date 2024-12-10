CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

CLIENT := client
SERVER := server

SRC_SERVER := server.c
SRC_CLIENT := client.c

INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft
PRINTF := ./ft_printf/libftprintf.a
PRINTF_PATH := ./ft_printf
all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_PATH) 

$(PRINTF):
	make -C $(PRINTF_PATH)

$(SERVER): $(LIBFT) $(PRINTF) $(SRC_SERVER)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBFT) $(PRINTF) -o $@
$(CLIENT): $(LIBFT) $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBFT) $(PRINTF) -o $@


clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(SRC_SERVER:.c=.o) $(SRC_CLIENT:.c=.o)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all