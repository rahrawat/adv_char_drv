#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
int node, cb_debug_val=0;
char *cb_debug;
module_param(node, int, S_IRUSR|S_IWUSR);
module_param(cb_debug_val, int, S_IRUSR|S_IWUSR);
/*----------------------Module_param_cb()--------------------------------*/
int change_debug_lvl(const char *val, const struct kernel_param *kp)
{
        int res = param_set_int(val, kp); // Use helper for write variable
        if(res==0) {
                printk(KERN_INFO "Call back function called...\n");
		switch (cb_debug_val) {
			case 0:
				#ifdef DEBUG
				#undef DEBUG
				#endif
				break;
			case 1:
				#ifndef DEBUG
				#define DEBUG
				#endif
				break;
			}
                return 0;
        }
        return -1;
}

const struct kernel_param_ops my_param_ops = 
{
        .set = &change_debug_lvl, // Use our setter ...
        .get = &param_get_int, // .. and standard getter
};

module_param(cb_debug, charp, S_IRUSR|S_IWUSR);

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
