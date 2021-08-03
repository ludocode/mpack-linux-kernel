#
# Copyright (c) 2021 Nicholas Fraser
#
# This is dual-licensed under the MIT and GPLv2.
#

ifeq ($(wildcard $(src)/mpack/src/mpack/mpack.h),)
$(error "You must checkout mpack/ here (or symlink the mpack repository.)")
endif

obj-m = mpack-tests.o

SRCS := $(shell cd $(src) && ls mpack/src/mpack/*.c)
SRCS += $(shell cd $(src) && ls mpack/test/test*.c)
SRCS += mpack-shim.c

mpack-tests-y := \
	$(patsubst %.c, %.o, $(SRCS))

ccflags-y := \
	-Os \
	-Werror \
	-I$(src) \
	-I$(src)/mpack/src \
	-I$(src)/mpack/test \
	-include mpack-tests-kernel.h \
	-DMPACK_HAS_CONFIG=1
