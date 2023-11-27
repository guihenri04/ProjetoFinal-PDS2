CC = g++
CFLAGS = -std=c++11 -Wall
SOURCES = main.cpp Filmes/filme.cpp Filmes/Subclasses/DVDestoque.cpp Filmes/Subclasses/DVDlancamento.cpp Filmes/Subclasses/DVDpromocao.cpp Filmes/Subclasses/fita.cpp Cliente/cliente.cpp Locadora/locadora.cpp
HEADERS = Filmes/filme.hpp Filmes/Subclasses/DVDestoque.hpp Filmes/Subclasses/DVDlancamento.hpp Filmes/Subclasses/DVDpromocao.hpp Filmes/Subclasses/fita.hpp Cliente/cliente.hpp Locadora/locadora.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = executavel

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean
