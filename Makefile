CC := clang
CXX := clang++

.PHONY: all
all: answer

# 在这里添加了 answer.o 目标文件。
objects := main.o answer.o

answer: $(objects)
	$(CXX) -o $@ $(objects)

#
# Make 可以自动推断 .o 目标文件需要依赖同名的 .cpp 文件，
# 所以其实不需要在依赖中指定 main.cpp 和 answer.cpp，
# 也不需要写编译 commands。
#
# 这里只需要指定目标文件所依赖的头文件，使头文件变动时可以
# 重新编译对应目标文件。
#
main.o: answer.hpp
answer.o: answer.hpp

.PHONY: clean
clean:
	rm -f answer $(objects)
