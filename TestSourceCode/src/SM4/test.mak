CXX = gcc
ECHO = @echo
RM = rm -f

EXEC = testsm4
OBJS = \
	sm4test.o

$(EXEC) : $(OBJS)
	$(ECHO) "Linking EXE  [$(EXEC)] ..."
	@$(CXX) -o $(EXEC) $(OBJS) -lSM4 -L.

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c $<

clean:
	$(RM) $(OBJS) $(EXEC)
