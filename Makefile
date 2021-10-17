WOLFRAM_APPID :=

.PHONY: build
build: configure
	cmake --build build

.PHONY: configure
configure:
	cmake -B build -DWOLFRAM_APPID=${WOLFRAM_APPID}

.PHONY: run
run:
	./build/answer_app

.PHONY: test
test:
	ctest --test-dir build -R "^answer."

.PHONY: clean
clean:
	rm -rf build

#
# 可以使用 Make 来更方便地调用 CMake 命令：
#
#     make build WOLFRAM_APPID=xxx
#     make test
#     make run
#     make clean
#
