CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCS = $(wildcard Source/*.cpp)

build: $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

clean:
	rm -f build

.PHONY: clean
