#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int __init first_function(void)
{
	printk(KERN_INFO "Welcome to kernel\n");
	return 0;
}
void __exit exit_function(void)
{
	printk(KERN_ERR "Goodbye from kernel\n");
}

module_init(first_function);
module_exit(exit_function);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAHUL");
MODULE_DESCRIPTION("A ADVANCED character driver");
