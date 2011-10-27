#
# Makefile for the linux kernel.
#

# Object file lists.

obj-$(CONFIG_LKM_UDP) += udpRecvCallback.o

obj-$(CONFIG_LKM_CDEV) += cdev.o

obj-$(CONFIG_LKM_NETLINK) += gnKernel.o

obj-$(CONFIG_LKM_IOCTL) += ioctl.o

obj-$(CONFIG_LKM_DEBUGFS) += debugfs.o

obj-$(CONFIG_LKM_MMAP) += mmap_simple_kernel.o

obj-$(CONFIG_LKM_SIGNAL) += signal_kernel.o

obj-$(CONFIG_LKM_SYSCTL) += sysctl.o

obj-$(CONFIG_LKM_SYSFS) += sysfs_ex2.o sysfs_ex.o

obj-$(CONFIG_LKM_HELPER) += usermodehelper.o
