/*
 * Copyright (c) 2021 Nicholas Fraser
 *
 * This program is dual licensed under the terms of the MIT license OR the GNU
 * General Public License version 2, your choice.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * attached licenses for details.
 */

#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual MIT/GPL");

extern int main(void);

int init_module(void) {
    printk(KERN_INFO "mpack module starting up\n");
    return main();
}

void cleanup_module(void) {
    printk(KERN_INFO "mpack module shutting down\n");
}
