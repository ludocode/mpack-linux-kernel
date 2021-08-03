#
# Copyright (c) 2021 Nicholas Fraser
#
# This is dual-licensed under the MIT and GPLv2.
#

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -f mpack/src/mpack/{*.o,.*.o.cmd} mpack/test/{*.o,.*.o.cmd}
