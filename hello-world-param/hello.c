#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Cbarela");

// default values for module parameters
static char *whom = "world";
static int howmany = 1;

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);


int hello_init(void) {

    int i;
    for (i=howmany; i>0; i--){ 
        printk(KERN_INFO "Hello %s\n", whom);
    }    
    
    return 0;
}

void hello_exit(void) {

    printk(KERN_INFO "Goodbye World\n");
}

module_init(hello_init);
module_exit(hello_exit);
