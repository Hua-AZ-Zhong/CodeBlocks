CXX = gcc
ECHO = @echo
RM = rm -f

EXEC = zplite8583C0
OBJS = \
	testPOMP1.o

$(EXEC) : $(OBJS)
	$(ECHO) "Linking EXE  [$(EXEC)] ..."
	@$(CXX) -o $(EXEC) $(OBJS) -lPOMP -L.

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c $<

clean:
	$(RM) $(OBJS) $(EXEC)
