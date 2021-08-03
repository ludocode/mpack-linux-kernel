/*
 * Copyright (c) 2021 Nicholas Fraser
 *
 * This is dual-licensed under the MIT and GPLv2.
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
