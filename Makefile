CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra

TARGET = examheap
OBJS = examheap.o heap.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
