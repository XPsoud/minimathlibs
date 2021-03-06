#
# Copyright (c) 2012 Juan Palacios juan.palacios.puyana@gmail.com
# This file is part of minimathlibs.
# Subject to the 2-clause BSD license 
# - see <http://opensource.org/licenses/BSD-2-Clause>
#

include rules.mk
TESTDIR = tests

.PHONY: all
.PHONY: test_objs
.PHONY: list_tests
.PHONY: objs
.PHONY: clean


all : build_tests

list_tests :
	make -C $(TESTDIR) list

test :
	make -C $(TESTDIR) test

build_tests :
	make -C $(TESTDIR) build_tests

test_objs :
	make -C $(TESTDIR) obj_main

objs :
	make -C $(TESTDIR) objs

clean :
	make -C $(TESTDIR) clean
