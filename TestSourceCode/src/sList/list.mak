CXX = g++
ECHO = @echo
DLINK = ld
DLFIX = .so
PRGTARG = TestList
DLTARG = $(HOME)/TestSourceCode/lib/lib$(PRGTARG)$(DLFIX)
RM = rm -f

OBJS = \
	list.o \
	insert.o \
	display.o

$(DLTARG) : $(OBJS)
	$(ECHO) "Linking .so  [$(DLTARG)] ..."
	@$(CXX) -shared -o $@ $(DLFLGS) $(OBJS)

.cpp.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c -fpic $<

clean:
	$(RM) $(OBJS) $(DLTARG)
