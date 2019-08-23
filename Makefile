INSTALLDIR= module
ifneq ($(KERNELRELEASE),)
	obj-m :=adv_driver.o
	adv_driver-obj := init.o
else
        KERNDIR ?= /lib/modules/$(shell uname -r)/build
        PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)
clean:
	rm -rf $(INSTALLDIR)

endif

