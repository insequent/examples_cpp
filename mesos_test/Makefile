INCLUDES=include/
LIBS=lib/

CXXFLAGS=-Wall -g -std=c++11 -I$(INCLUDES)
LDFLAGS=-L$(LIBS) -lglog -lev -lprotobuf -lprotoc

all: example

clean:
	rm -f example
