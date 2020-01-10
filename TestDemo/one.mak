CC = cc
ECHO = @echo
RM = rm -f
DLINK = ld
DLFIX = .so
PRGTARG = CommonTools
DLTARG = lib$(PRGTARG)$(DLFIX)

LIBOBJS = \
	commonTools.o

EXEC = testBin
OBJS = \
	main.o


all: $(DLTARG) $(EXEC)
obj: $(LIBOBJS) $(OBJS)

$(DLTARG):$(LIBOBJS)
	$(ECHO) "Linking Shared Library [$(DLTARG)] ..."
	$(CC) -shared -o $@ $(LIBOBJS)

$(EXEC):$(OBJS)
	$(ECHO) "Linking EXE [$(EXEC)] ..."
	$(CC) -o $(EXEC) $(OBJS) $(DLTARG)

commonTools.o:commonTools.c
	$(ECHO) "Compiling C Objects [$@] ..."
	$(CC) -c -fpic $<

main.o:main.c
	$(ECHO) "Compiling C Objects [$@] ..."
	$(CC) -c $<

clean:
	$(RM) $(DLTARG) $(OBJS) $(LIBOBJS) $(EXEC)
