.PHONY: all build run clean help rebuild

help:
	@echo "Binary Search Tree - Build Targets"
	@echo "===================================="
	@echo "make build   - Build the project"
	@echo "make run     - Build and run the program"
	@echo "make clean   - Remove build artifacts"
	@echo "make rebuild - Clean and rebuild"
	@echo "make help    - Show this help message"

build:
	@mkdir -p build
	@cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

run: build
	@cd build && ./binary-tree.exe

clean:
	@rm -rf build/
	@echo "Build artifacts removed"

rebuild: clean build
	@echo "Project rebuilt successfully"

all: build
