/**
 * ----------------------------------------------------------------------------
 * This file is part of the aes_stream_drivers package. It is subject to
 * the license terms in the LICENSE.txt file found in the top-level directory
 * of this distribution and at:
 *    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html.
 * No part of the aes_stream_drivers package, including this file, may be
 * copied, modified, propagated, or distributed except according to the terms
 * contained in the LICENSE.txt file.
 * ----------------------------------------------------------------------------
**/
#ifndef __AXI_MEMORY_MAP_H__
#define __AXI_MEMORY_MAP_H__

#include <linux/types.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/poll.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <DmaDriver.h>

// Map size, 64K
#define MAP_SIZE     0x10000

// Memory map
struct MemMap {
   uint64_t    addr;
   uint8_t *   base;
   void *      next;
};

// Map structure
struct MapDevice {

   // Device tracking
   uint32_t        major;
   dev_t           devNum;
   char            devName[50];
   struct cdev     charDev;
   struct device * device;
   struct MemMap * maps;

};

char *Map_DevNode(struct device *dev, umode_t *mode);

int Map_Init(void);

void Map_Exit(void);

int Map_Open(struct inode *inode, struct file *filp);

int Map_Release(struct inode *inode, struct file *filp);

ssize_t Map_Read(struct file *filp, char *buffer, size_t count, loff_t *f_pos);

ssize_t Map_Write(struct file *filp, const char* buffer, size_t count, loff_t* f_pos);

uint8_t * Map_Find(uint64_t addr);

ssize_t Map_Ioctl(struct file *filp, uint32_t cmd, unsigned long arg);

#endif

