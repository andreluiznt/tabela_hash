CXX = g++        
CXXFLAGS = -Wall -g  
TARGET = programa
SRC = main.cpp primeiroNivel.cpp segundoNivel.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)