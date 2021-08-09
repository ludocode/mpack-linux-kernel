#
# Copyright (c) 2021 Nicholas Fraser
#
# This program is dual licensed under the terms of the MIT license OR the GNU
# General Public License version 2, your choice.
#
# This program is distributed WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# attached licenses for details.
#

ifeq ($(wildcard $(src)/mpack/src/mpack/mpack.h),)
$(error "You must checkout mpack/ here (or symlink the mpack repository.)")
endif

obj-m = mpack-tests.o

SRCS := $(shell cd $(src) && ls mpack/src/mpack/*.c)
SRCS += $(shell cd $(src) && ls mpack/test/unit/src/*.c)
SRCS += mpack-shim.c

mpack-tests-y := \
	$(patsubst %.c, %.o, $(SRCS))

ccflags-y := \
	-Os \
	-Werror \
	-I$(src) \
	-I$(src)/mpack/src \
	-I$(src)/mpack/test/unit/src \
	-include mpack-tests-kernel.h \
	-DMPACK_HAS_CONFIG=1
