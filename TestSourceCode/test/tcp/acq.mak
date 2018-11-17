CXX = gcc 
ECHO = @echo
RM = rm -f

EXEC = acq
OBJS = \
	acq.o

$(EXEC) : $(OBJS)
	$(ECHO) "Linking EXE  [$(EXEC)] ..."
	@$(CXX) -o $(EXEC) $(OBJS)

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c $<

clean:
	$(RM) $(OBJS) $(EXEC)
