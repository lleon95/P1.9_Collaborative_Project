# -*- Makefile -*-
SHELL=/bin/sh

default: all

all:
	$(MAKE) $(MFLAGS) -C lib

clean:
	$(MAKE) $(MFLAGS) -C lib clean
	$(MAKE) $(MFLAGS) -C examples clean
	$(MAKE) clean -C tests

check: all
	$(MAKE) $(MFLAGS) -C examples check

units-check:
	$(MAKE) check -C tests