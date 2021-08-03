/*
 * Copyright (c) 2021 Nicholas Fraser
 *
 * This is dual-licensed under the MIT and GPLv2.
 */

// This is an example mpack-config.h for compiling MPack v1.1 in the Linux kernel.
//     See: https://github.com/ludocode/mpack

// These headers are required to provide the necessary types and functions that
// would normally be provided by libc or by a conforming C99 compiler.
#define MPACK_CONFORMING 0
#include <linux/types.h>
#include <linux/limits.h>

// Floating point is not supported in the kernel.
#define MPACK_FLOAT 0

// Even though we don't have a real stdlib or conforming headers, we do have
// the standard string functions in a Linux-specific header. This forces MPack
// to use them.
#include <linux/string.h>
#define mpack_memcmp memcmp
#define mpack_memcpy memcpy
#define mpack_memmove memmove
#define mpack_memset memset
#define mpack_strlen strlen

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

// This configuration turns debugging off; we don't want to abort on errors. If
// you want you could instead define an MPACK_CUSTOM_ASSERT function that
// triggers a kernel panic with a friendly error message, or printk()s the
// error and goes into an infinite loop. You probably won't be able to compile
// the unit test suite with this on though.
#define MPACK_DEBUG 0

// Tracking should probably be off (in case you enable allocations) since it is
// allocation-heavy.
#define MPACK_READ_TRACKING 0
#define MPACK_WRITE_TRACKING 0
