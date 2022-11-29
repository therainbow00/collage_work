
SERVER_DIR=src/sum-server
SERVER_FILENAME=sum-server

all: server client

server: build-server pull-server

build-server:
	cd ${SERVER_DIR} && $(MAKE) CFLAGS=$(CFLAGS)

pull-server: build-server
	cp ${SERVER_DIR}/${SERVER_FILENAME} .

client: chat-client.c
	cc $(CFLAGS) chat-client.c -o chat-client

clean:
	cd ${SERVER_DIR} && $(MAKE) clean
	rm -f chat-client sum-server
