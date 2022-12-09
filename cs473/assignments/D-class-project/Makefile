
all: server client

server: chat-server.c
	cc chat-server.c -o chat-server

client: chat-client.c
	cc chat-client.c -o chat-client

clean:
	rm -f chat-client chat-server
