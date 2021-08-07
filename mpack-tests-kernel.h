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

// This is force-included to add workarounds to the unit tests.

#include <linux/kernel.h>
#include <linux/slab.h>
#define printf(...) printk(KERN_INFO __VA_ARGS__)
#define vprintf(format, args) ((void)(format), (void)(args), (void)0) // silenced!
#define abort() __builtin_trap()
#define malloc(a) kmalloc(a, GFP_KERNEL)
#define free(a) kfree(a)
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include "test-system.h"
