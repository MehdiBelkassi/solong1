CC = gcc
CFLAGS = -Wall -Wextra -Werror


printflib = printf/libftprintf.a
LIBS = -Lprintf -lftprintf

all: server client
mandatory: server client

server: server.c $(printflib)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

client: client.c $(printflib)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

$(printflib):
	make -C printf

clean:
	rm -f server client 
	make -C printf clean

fclean: clean
	rm -f server client 
	make -C printf fclean

re: fclean all

.PHONY: clean 