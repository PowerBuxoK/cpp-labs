all:
	cmake -B ./build/ -S .
	cmake --build ./build/
test:
	make
	ctest --test-dir ./build/ctest/
clean:
	rm -rf ./build/
