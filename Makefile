CC=gcc
CFLAGS=-Wall -std=gnu99

app: main.c
	@echo Linking $<...
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo Cleaning...
	@rm app
