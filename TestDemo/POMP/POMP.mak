CXX = gcc 
ECHO = @echo
DLINK = ld
DLFIX = .so 
PRGTARG = POMP
DLTARG = lib$(PRGTARG)$(DLFIX)
RM = rm -f

OBJS = \
	libPOMP.o

$(DLTARG) : $(OBJS)
	$(ECHO) "Linking .so  [$(DLTARG)] ..."
	@$(CXX) -shared -o $@ $(DLFLGS) $(OBJS)

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c -fpic $<

clean:
	$(RM) $(OBJS) $(DLTARG)
