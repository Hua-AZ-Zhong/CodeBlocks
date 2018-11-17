CXX = g++
ECHO = echo
EXEC = emis
OBJS = \
	main.o \
	managerview_console_impl.o \
	manager.o \
	managerservice_impl.o \
	managerdao_file_impl.o \
	tools.o

.cpp.o:
	$(ECHO) "Compiling C [$@] ..."
	$(CXX) -o $@

$(EXEC):$(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

clean:
	rm -f $(OBJS)
