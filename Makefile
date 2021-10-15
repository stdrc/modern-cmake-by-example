#
# := 用于给变量赋值，除此之外还有 =、?=、+= 等不同的赋值方式。
#
# 一般全大写变量用来表示允许调用 make 的时候传入的变量，
# 全小写变量表示仅内部使用的变量。
#
# 这里 CC 和 CXX 指定了要使用的 C 和 C++ 编译器。
#
CC := clang
CXX := clang++

#
# Makefile 中的核心概念是 target（目标），定义 target 的基本
# 格式是（注意每一行 command 是必须用 tab 缩进的）：
#
#   name: dependencies
#   	commands
#
# 要构建某个 target 时，使用如下命令：
#
#   make target_name
#
# 下面 all 是一个 target，它依赖另一个 target：hello，
# 意味着要构建 all，首先需要构建 hello。而 all 的 commands
# 部分为空，表示构建 all 不需要额外命令。
#
# .PHONY 表示 all 不是一个真实会生成的文件，而是一个“伪目标”。
#
.PHONY: all
all: hello

#
# 由于后面需要多次使用 main.o 等目标文件列表，这里赋值给变量
# objects。
#
objects := main.o

#
# hello 是我们最终要生成的可执行文件名，它依赖 objects 中的
# 所有目标文件。
#
# 它的 commands 部分使用 CXX 指定的编译器将所有目标文件链接
# 成 hello 可执行文件。
#
hello: $(objects)
	$(CXX) -o $@ $(objects)

# main.o 目标文件依赖 main.cpp 源文件。
main.o: main.cpp
	$(CXX) -c main.cpp

#
# clean 用于清除构建生成的临时文件、目标文件和可执行文件。
# 和 all 类似，它是一个“伪目标”。
#
.PHONY: clean
clean:
	rm -f hello $(objects)
