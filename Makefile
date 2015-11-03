all: hello simplemath fibonacci
run:
	echo "Running: hello"
	./hello
	./simplemath
	./fibonacci

clean:
	rm -f hello hello.o
