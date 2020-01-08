#ARCH
ARCH="`uname -s`"

MACOS="Darwin"
LINUX="Linux"
HP-UX="HP-UX"

if [ $(ARCH) = $(LINUX) ]; \
	then \
		echo $(ARCH); \
elif [ $(ARCH) = $(HP-UX) ]; \
	then \
		echo $(ARCH); \
elif [ $(ARCH) = $(MACOS) ]; \
	then \
		echo $(ARCH); \
else \
		echo "ARCH unknow"; \
fi

CC = cc
ECHO = echo
EXEC = testBin
OBJS = \
	main.o \
	commonTools.o

.cpp.o:
	$(ECHO) "Compiling C [$@] ..."
	$(CC) -o $@

.c.o:
	$(ECHO) "Compiling C [$@] ..."
	$(CC) -o $@

$(EXEC):$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

clean:
	rm -f $(OBJS)
