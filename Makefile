CC = gcc
CFLAGS = -Wall -g
SRCDIR = .
BUILDDIR = build

SOURCES := $(wildcard ch*/*.c)
OBJECTS := $(patsubst %.c, $(BUILDDIR)/%, $(notdir $(SOURCES)))

all: $(OBJECTS)

$(BUILDDIR)/%: $(SRCDIR)/*/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean

