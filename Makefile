CC = sh-elf-gcc
LD = sh-elf-ld

SOURCEDIR = cas-sdk
BUILDDIR = obj

CFLAGS = -mrenesas -mb -m4a-nofpu -O2 -ffreestanding -nostartfiles -I $(CAS_SDK)/include -I $(PREFIX)/sh-elf/include -L$(PREFIX)/sh-elf/lib/
LDFLAGS = -nostdlib -r

SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))

all: cas-sdk/cas-sdk.o

cas-sdk/cas-sdk.o: $(OBJECTS)
	$(LD) $(LDFLAGS) $(addprefix $(BUILDDIR)/,$(notdir $(OBJECTS))) -o $@

$(BUILDDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(SOURCEDIR) -I$(dir $<) -c $< -o $(BUILDDIR)/$(notdir $@)

.PHONY: all