CC = cc
ECHO = @echo
RM = rm -f
DLINK = ld
DLFIX = .so
PRGTARG = CommonTools
DLTARG = lib$(PRGTARG)$(DLFIX)

OBJS = \
	commonTools.o

$(DLTARG):$(OBJS)
	$(ECHO) "Linking Shared Library [$(DLTARG)] ..."
	#$(CC) -shared -o $@ $(DLFLGS) $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

.cpp.o:
	$(ECHO) "Compiling C++ Objects [$@] ..."
	$(CC) -o $<

.c.o:
	$(ECHO) "Compiling C Objects [$@] ..."
	$(CC) -c -fpic $<

clean:
	$(RM) $(DLTARG) $(OBJS)
