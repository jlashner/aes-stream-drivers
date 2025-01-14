/**
 *-----------------------------------------------------------------------------
 * Title      : Top level module
 * ----------------------------------------------------------------------------
 * File       : tem_top.h
 * Author     : Ryan Herbst, rherbst@slac.stanford.edu
 * Created    : 2016-08-08
 * Last update: 2016-08-08
 * ----------------------------------------------------------------------------
 * Description:
 * Top level module types and functions.
 * ----------------------------------------------------------------------------
 * This file is part of the aes_stream_drivers package. It is subject to
 * the license terms in the LICENSE.txt file found in the top-level directory
 * of this distribution and at:
 *    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html.
 * No part of the aes_stream_drivers_package, including this file, may be
 * copied, modified, propagated, or distributed except according to the terms
 * contained in the LICENSE.txt file.
 * ----------------------------------------------------------------------------
**/
#ifndef __TEM_TOP_H__
#define __TEM_TOP_H__

#include <linux/types.h>
#include <linux/pci.h>

#define MAX_DMA_DEVICES 4

// PCI IDs
#define PCI_VENDOR_ID_SLAC 0x1a4a
#define PCI_DEVICE_ID_TEM  0x2020

// Init Kernel Module
int32_t Tem_Init(void);

// Exit Kernel Module
void Tem_Exit(void);

// Create and init device
int Tem_Probe(struct pci_dev *pcidev, const struct pci_device_id *dev_id);

// Cleanup device
void  Tem_Remove(struct pci_dev *pcidev);

#endif

