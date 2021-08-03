This builds the [MPack](https://github.com/ludocode/mpack) unit test suite into a Linux kernel module.

## Using MPack in the Linux kernel

The file [`mpack-config.h`](mpack-config.h) provides an example configuration to use to get MPack working in the Linux kernel. To use it, copy it into your include path and define `-DMPACK_HAS_CONFIG=1` when building MPack.

This configuration is not done automatically by MPack because including Linux headers would make MPack a derived work of Linux requiring dual-licensing it under the GPLv2. Instead this code is kept separate so that only this config and test shim is dual-licensed.

## Building and running the unit tests

You will need the Linux headers installed for your kernel. First clone or symlink the MPack tree into this folder, then type `make` to build the unit test kernel module:

```
git clone https://github.com/ludocode/mpack.git
make
```

You can then run the unit tests by inserting the `mpack-tests.ko` kernel module. Beware, if a test fails the kernel may panic, your data may be destroyed, your machine may catch fire etc. Run this in a virtual machine.

```
sudo insmod mpack-tests.ko  # DANGER
```

Then, assuming your machine is still alive, check the kernel log (e.g. `dmesg` or `journalctl -e`.) You should see something like "Unit testing complete. 0 failures in 13394 checks."

To remove it afterwards:

```
sudo rmmod mpack-tests
```
