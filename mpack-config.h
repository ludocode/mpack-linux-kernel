/*
 * Copyright (c) 2021 Nicholas Fraser
 *
 * This is dual-licensed under the MIT and GPLv2.
 */

// This is an example mpack-config.h for compiling MPack v1.1 in the Linux kernel.
//     See: https://github.com/ludocode/mpack

// The linux kernel doesn't have proper headers like <limits.h> or
// <inttypes.h>. Since this doesn't conform to the C spec (not even for
// freestanding implementations), we turn off MPACK_CONFORMING. This also
// disables MPACK_STDLIB, MPACK_STDIO and some other stuff.
#define MPACK_CONFORMING 0

// Since we don't have the stdlib or freestanding headers, MPack won't include
// any. We have to include the Linux headers to at least define the standard
// fixed-width integer types as well as size_t, bool, and so on.
#include <linux/types.h>

// We do still have the standard string functions but they're in a
// Linux-specific header. We configure MPack to use them.
#include <linux/string.h>
#define MPACK_MEMCMP memcmp
#define MPACK_MEMCPY memcpy
#define MPACK_MEMMOVE memmove
#define MPACK_MEMSET memset
#define MPACK_STRLEN strlen

// This makes MPack use kmalloc() for allocations, allowing you to use things
// like the growable writer or the dynamic tree parser. It's probably not a
// good idea so it's disabled by default. You should use fixed buffers for
// writing and fixed node pools or the expect API for parsing. If you turn this
// on, beware the caveats of performing allocations in the kernel.
#if 0
#include <linux/slab.h>
#define MPACK_MALLOC(x) kmalloc(x, GFP_KERNEL)
#define MPACK_FREE(x) kfree(x)
#endif

// Floating point is not supported in the kernel.
#define MPACK_FLOAT 0

// This configuration turns debugging off; we don't want to abort on errors. If
// you want you could instead define an MPACK_CUSTOM_ASSERT function that
// triggers a kernel panic with a friendly error message, or printk()s the
// error and stops somehow. You probably won't be able to compile the unit test
// suite with this on.
#define MPACK_DEBUG 0

// Tracking should probably be off (in case you enable allocations) since it is
// allocation-heavy.
#define MPACK_READ_TRACKING 0
#define MPACK_WRITE_TRACKING 0
