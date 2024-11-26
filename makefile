currentDir = puntatori

make all:
make run:
	cls
	$(currentDir)/main.exe

make build:
	cls
	gcc $(currentDir)/*.c -o $(currentDir)/main