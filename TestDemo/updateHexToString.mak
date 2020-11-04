all:
	proc updateHexToString.pc
	gcc -o updateHexToString updateHexToString.c -lclntsh
