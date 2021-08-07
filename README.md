# MPack in the Linux Kernel

[MPack](https://github.com/ludocode/mpack) is a C implementation of an encoder and decoder for the [MessagePack](http://msgpack.org/) serialization format.

This repository contains an example [`mpack-config.h`](mpack-config.h) configuration file to use to build MPack in the Linux kernel. To use it, copy it into your include path and define `-DMPACK_HAS_CONFIG=1` when building MPack.

This configuration is not done automatically by MPack because including Linux headers would make MPack a derived work of Linux requiring dual-licensing it under the GPLv2. Instead this code is kept separate so that only this config and test shim is dual-licensed.

## Building and running the unit tests

This repository contains a unit test shim that builds the MPack unit test suite into a Linux kernel module. You do not need to build the unit tests to use MPack in the kernel.

To build the unit tests, you will need the Linux headers installed for your kernel. First clone or symlink the MPack tree into this folder, then type `make` to build the unit test kernel module. For example:

```
git clone https://github.com/ludocode/mpack-linux-kernel.git
cd mpack-linux-kernel
git clone https://github.com/ludocode/mpack.git
make
```

You can then run the unit tests by inserting the `mpack-tests.ko` kernel module. Beware, if a test fails or if bugs occur the kernel may panic, your data may be destroyed, your machine may catch fire etc. Run this in a virtual machine.

```
sudo insmod mpack-tests.ko  # DANGER
```

Then, assuming your machine is still alive, check the kernel log (e.g. `dmesg` or `journalctl -e`.) You should see something like "Unit testing complete. 0 failures in 13394 checks."

To remove it afterwards:

```
sudo rmmod mpack-tests
```
