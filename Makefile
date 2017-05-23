BIN = bin

ifeq ($(OS),Windows_NT)
TARGET = inet.dll
OS_FLAGS = -I . -lws2_32
else
TARGET = inet.so
OS_FLAGS =
endif


$(BIN)/$(TARGET): \
	$(BIN) \
	inet.c

	gcc -Wall -g -fPIC -shared inet.c -o $(BIN)/$(TARGET) $(OS_FLAGS)

$(BIN):
	mkdir $(BIN)

clean:
	rm -rf $(BIN)/*

test: \
	$(BIN)/$(TARGET)

	./testsuite.sh
