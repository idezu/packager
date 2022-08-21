BUILD_DIR=../build
PKG_SRCS := $(wildcard *.c)
PKG_OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(PKG_SRCS))
PKG= $(BUILD_DIR)/packager
INSTALL = installck
SOURCES = sourcesck

INCLUDE_FLAGS=-I../include

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
COMPILE_TIME = -pipe
CFLAGS = $(WARNING) $(DEBUG) $(OPTIMIZE) $(COMPILE_TIME)


all: $(PKG) link

$(BUILD_DIR)/%.o: %.c
	$(CC) $(INCLUDE_FLAGS) $< -c -o $@

$(PKG): $(PKG_OBJS)
	$(CC) $(CFLAGS) $(PKG_OBJS) -o $@ -lc

link:
	$(LN) $(PKG) $(INSTALL)
	$(LN) $(PKG) $(SOURCES)

clean:
	rm $(PKG_OBJS)
