#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

struct kset *myfs_subsys;

struct my_attr {
        struct attribute attr;
	int value;
};

static struct my_attr my_first = {
	.attr.name="first",
	.attr.mode = 0644,
	.value = 1,
};

static struct my_attr my_second = {
	.attr.name="second",
	.attr.mode = 0644,
	.value = 2,
};

static struct attribute * myattr[] = {
	&my_first.attr,
	&my_second.attr,
	NULL
};

static ssize_t default_show(struct kobject *kobj, struct attribute *attr,
                              char *buf)
{
        struct my_attr *a = container_of(attr, struct my_attr, attr);
	return scnprintf(buf, PAGE_SIZE, "%d\n", a->value);
}

static ssize_t default_store(struct kobject *kobj, struct attribute *attr,
                               const char *buf, size_t len)
{
        struct my_attr *a = container_of(attr, struct my_attr, attr);
       	sscanf(buf, "%d", &a->value);
	return sizeof(int);
}

static struct sysfs_ops myops = {
	.show = default_show,
	.store = default_store,
};

static struct kobj_type mytype = {
	.sysfs_ops = &myops,
	.default_attrs = myattr,
};

static int __init sysfsexample_module_init(void)
{
	int err;

	myfs_subsys = kset_create_and_add("myfs", NULL, NULL);
	myfs_subsys->kobj.ktype = &mytype;
	
	err = kset_register(&myfs_subsys);

	return err;
}

static void __exit sysfsexample_module_exit(void)
{
	kset_unregister(&myfs_subsys);
}

module_init(sysfsexample_module_init);
module_exit(sysfsexample_module_exit);
MODULE_LICENSE("GPL");
