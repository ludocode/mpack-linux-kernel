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

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -f mpack/src/mpack/{*.o,.*.o.cmd} mpack/test/unit/src/{*.o,.*.o.cmd}
