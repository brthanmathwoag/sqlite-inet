BIN = bin

$(BIN)/inet.so: \
	$(BIN) \
	inet.c \

	gcc -Wall -g -fPIC -shared inet.c -o $(BIN)/inet.so


$(BIN):
	mkdir $(BIN)

clean:
	rm -rf $(BIN)/*

test: \
	$(BIN)/inet.so

	./testsuite.sh
