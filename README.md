# mruby on GR-PEACH+TECS
mruby on GR-PEACH+TECS is a software develpment framework for running mruby (Lightweight Ruby) scripts on GR-PEACH.

* [Reference Manual (in Japanense)](http://tecs-docs.readthedocs.io/ja/latest/mruby-on-gr-peach+tecs/index.html)

# How to build
0. Set up an environment:

	Prepare the followings before building.
	* [Cygwin](https://www.cygwin.com/)
		- Ruby
		- GNU Make
		- bison
	* [GNUARM-NONE v16.01 Windows Toolchain (ELF)](https://gcc-renesas.com/rz/rz-download-toolchains/)
        - a cross-compiler

	Note: it is probably possible to build it on Mac or Linux, but it has not been tested yet.

1. Clone the repository:
	```bash
	$ git clone https://github.com/robotan0921/mruby_on_GR-PEACH-TECS.git
	```

2. Build mruby:
	```bash
	$ cd mruby-1.3.0
	$ make
	```

3. Build platform and sample application:
	```bash
	$ cd ../asp3/workspace/build
	$ make
	```

4. Copy a binary to GR-PEACH and launch:
	```bash
	$ cp asp.bin /cygdrive/d/
	```

# Licenses
mruby on GR-PEACH+TECS is released under the [TOPPERS LICENSE](https://www.toppers.jp/license.html).

This framework integrates several developments and you should follow each liceses.
- mruby : [MIT License](https://github.com/mruby/mruby/blob/master/MITL)
- TLSF : [GPL and LGPL](http://www.gii.upv.es/tlsf/main/license)

# Links
### mruby (Lightweight Ruby)
* [https://github.com/mruby/mruby](https://github.com/mruby/mruby)
* [https://mruby.org/](https://mruby.org/)

### TECS (TOPPERS Embedded Component System)
* [https://www.toppers.jp/tecs.html](https://www.toppers.jp/tecs.html)

### TOPPERS/ASP3 Kernel
* [https://www.toppers.jp/asp3-kernel.html](https://www.toppers.jp/asp3-kernel.html)

### TLSF - a dynamic memory allocator -
* [http://www.gii.upv.es/tlsf/](http://www.gii.upv.es/tlsf/)

<!-- ### TINET+TECS ([https://github.com/robotan0921/tinet-tecs](https://github.com/robotan0921/tinet-tecs)) -->

<!-- # Contacts
Please feel free to ask me or send pull requests if you have any questions or find a bug.
If you find a bug or any problem, please let us know by sending e-mail; com-wg@toppers.jp or users@toppers.jp.
Note: [you have to participate ML before sending mail.](http://www.toppers.jp/en/community.html)
-->
