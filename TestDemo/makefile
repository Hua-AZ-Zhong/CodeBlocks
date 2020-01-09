#ARCH
ARCH="`uname -s`"

MACOS="Darwin"
LINUX="Linux"
HP-UX="HP-UX"

#if [ $(ARCH) = $(LINUX) ]; \
	then \
		echo $(ARCH); \
elif [ $(ARCH) = $(HP-UX) ]; \
	then \
		echo $(ARCH); \
elif [ $(ARCH) = $(MACOS) ]; \
	then \
		echo $(ARCH); \
else \
		echo "ARCH unknow"; \
fi

all:
	make -f libCommonTools.mak
	make -f testBin.mak

clean:
	make -f libCommonTools.mak $@
	make -f testBin.mak $@
