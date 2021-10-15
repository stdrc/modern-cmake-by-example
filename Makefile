CC := clang
CXX := clang++

.PHONY: all
all: answer

objects := main.o answer.o

answer: $(objects)
	$(CXX) -o $@ $(objects)

main.o: answer.hpp
answer.o: answer.hpp

.PHONY: clean
clean:
	rm -f answer $(objects)
