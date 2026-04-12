all:
	cmake -B ./build/ -S .
	cmake --build ./build/
run: all
	./build/prog
clean:
	rm -rf ./build/
