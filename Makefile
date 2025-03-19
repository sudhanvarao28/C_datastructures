CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = linked_list/linked_list.c node/node.c queue/queue.c tests/test_linked_list.c 
OUT = tll.out

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
