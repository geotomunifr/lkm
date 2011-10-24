#
# Makefile for the linux kernel.
#

# Object file lists.

obj-$(CONFIG_LKM_UDP) += udpRecvCallback.o

obj-$(CONFIG_LKM_CDEV) += cdev.o

obj-$(CONFIG_LKM_NETLINK) += gnKernel.o
