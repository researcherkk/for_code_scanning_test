TARGET = sensor_monitor
SRC = sensor_monitor.cpp

CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)