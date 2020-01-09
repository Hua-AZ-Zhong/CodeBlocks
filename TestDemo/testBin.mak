CC = cc
ECHO = @echo
RM = rm -f

EXEC = testBin
OBJS = \
	main.o
LIBS = \
	libCommonTools.so

$(EXEC):$(OBJS)
	$(ECHO) "Linking EXE [$(EXEC)] ..."
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
	#$(CC) -o $(EXEC) $(OBJS) -lCommonTools -L.

.cpp.o:
	$(ECHO) "Compiling C++ Objects [$@] ..."
	$(CC) -o $<

.c.o:
	$(ECHO) "Compiling C Objects [$@] ..."
	$(CC) -c $<

clean:
	$(RM) $(EXEC) $(OBJS)
