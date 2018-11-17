CXX = g++
ECHO = @echo
RM = rm -f

EXEC = testList
OBJS = main.o

$(EXEC) : $(OBJS)
	$(ECHO) "Linking EXE  [$(EXEC)] ..."
	@$(CXX) -o $(EXEC) $(OBJS) -lTestList

.cpp.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c $<

clean:
	$(RM) $(OBJS) $(EXEC)
