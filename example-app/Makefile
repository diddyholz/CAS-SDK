ifndef CAS_SDK
$(error You have to define the CAS_SDK variable and point it to the cas-sdk directory!)
endif

OUTFILE = app0 				# The name of the output files
APPNAME = Example app 	# The name of your app 
APPAUTHOR = yourname	# The author of the app
APPVERSION = v1.00 		# The version of the app

CC = sh-elf-gcc						# The c compiler to use
OBJCOPY = sh-elf-objcopy	# The objcopy to use
PYTHON = python						# Your python executable

SOURCEDIR = src		# The directory with your app's source files
BUILDDIR = obj		# The directory to use where obj files should be created

CFLAGS = -mrenesas -mb -m4-nofpu -O2 -ffreestanding -nostartfiles -I $(CAS_SDK)/include -I $(PREFIX)/sh-elf/include -L$(PREFIX)/sh-elf/lib/
LDFLAGS = -T linker-script.ld
BCOPYFLAGS = -R .got*

SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))

all: $(OUTFILE).tmp
	$(OBJCOPY) -O binary $(OUTFILE).elf $(OUTFILE).bin
	$(PYTHON) $(CAS_SDK)/makehmb.py "$(OUTFILE).bin" "$(OUTFILE).hmb" "$(APPNAME)" "$(APPAUTHOR)" "$(APPVERSION)"

$(OUTFILE).tmp: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(addprefix $(BUILDDIR)/,$(notdir $(OBJECTS))) -o $(OUTFILE).elf $(CAS_SDK)/cas-sdk.o

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(SOURCEDIR) -I$(dir $<) -c $< -o $(BUILDDIR)/$(notdir $@)

.PHONY: all