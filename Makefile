all: bin/easycl

bin/easycl: bin/easycl.o lib/libsimplefs.so lib/libui.so
	@printf "# Compiling bin/easycl..."
	@export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
	
	@g++ bin/easycl.o -Llib -lsimplefs -lui -o bin/easycl
	@printf "done\n"

bin/easycl.o: src/main.cpp
	@printf "# Compiling bin/easycl.o..."
	@g++ -c src/main.cpp -o bin/easycl.o
	@printf "done\n"

lib/libsimplefs.o: src/lib/simplefs.cpp
	@printf "# Compiling lib/libsimplefs.o..."
	@g++ -c -fPIC src/lib/simplefs.cpp -o lib/libsimplefs.o
	@printf "done\n"

lib/libsimplefs.so: lib/libsimplefs.o
	@printf "# Compiling lib/libsimplefs.so..."
	@g++ -shared lib/libsimplefs.o -o lib/libsimplefs.so
	@printf "done\n"

lib/libui.o: src/lib/ui.cpp
	@printf "# Compiling lib/libui.o..."
	@g++ -c -fPIC src/lib/ui.cpp -o lib/libui.o
	@printf "done\n"

lib/libui.so: lib/libui.o
	@printf "# Compiling lib/libui.so..."
	@g++ -shared lib/libui.o -o lib/libui.so
	@printf "done\n"
