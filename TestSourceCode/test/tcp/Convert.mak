CXX = gcc
ECHO = @echo
DLINK = ld
DLFIX = .so
PRGTARG = Convert
DLTARG = $(HOME)/TestSourceCode/lib/lib$(PRGTARG)$(DLFIX)
RM = rm -f

OBJS = \
	Convert.o

$(DLTARG) : $(OBJS)
	$(ECHO) "Linking .so  [$(DLTARG)] ..."
	@$(CXX) -shared -o $@ $(DLFLGS) $(OBJS)

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c -fpic $<

clean:
	$(RM) $(OBJS) $(DLTARG)
