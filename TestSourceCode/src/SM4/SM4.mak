CXX = gcc 
ECHO = @echo
DLINK = ld
DLFIX = .so 
PRGTARG = SM4
DLTARG = lib$(PRGTARG)$(DLFIX)
RM = rm -f

OBJS = \
	sm4.o

$(DLTARG) : $(OBJS)
	$(ECHO) "Linking .so  [$(DLTARG)] ..."
	@$(CXX) -shared -o $@ $(DLFLGS) $(OBJS)

.c.o:
	$(ECHO) "Compiling [$@] ..."
	@$(CXX) -c -fpic $<

clean:
	$(RM) $(OBJS) $(DLTARG)
