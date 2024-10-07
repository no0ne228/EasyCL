all: bin/easycl

bin/easycl: bin/easycl.o lib/libsimplefs.o
	@printf "# Compiling bin/easycl..."
	@g++ bin/easycl.o lib/libsimplefs.o -o bin/easycl
	@printf "done\n"

bin/easycl.o: src/main.cpp
	@printf "# Compiling bin/easycl.o"
	@g++ -c src/main.cpp -o bin/easycl.o
	@printf "done\n"

lib/libsimplefs.o: src/lib/simplefs.cpp
	@printf "# Compiling lib/libsimplefs.o..."
	@g++ -c src/lib/simplefs.cpp -o lib/libsimplefs.o
	@printf "done\n"
