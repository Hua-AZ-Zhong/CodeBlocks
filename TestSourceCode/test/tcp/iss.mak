CXX = gcc 
ECHO = @echo
RM = rm -f

EXEC = iss
OBJS = \
	iss.o

$(EXEC) : $(OBJS)
	$(ECHO) "Linking EXE  [$(EXEC)] ..."
	@$(CXX) -o $(EXEC) $(OBJS) -lConvert

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c $<

clean:
	$(RM) $(OBJS) $(EXEC)
