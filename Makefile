all: hello simplemath
run:
	echo "Running: hello"
	./hello
	./simplemath

clean:
	rm -f hello hello.o
