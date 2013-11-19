/*
 * This file is part of Espruino, a JavaScript interpreter for Microcontrollers
 *
 * Copyright (C) 2013 Gordon Williams <gw@pur3.co.uk>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * ----------------------------------------------------------------------------
 * CC3000 WiFi SPI wrappers
 * ----------------------------------------------------------------------------
 */

// from jsutils
void *memcpy(void *dst, const void *src, unsigned int size);
extern int errno;
#define F_GETFL (0)
#define F_SETFL (0)
#define O_NONBLOCK (0)
#define EINPROGRESS (0)
#define EWOULDBLOCK (0)

#define INADDR_ANY      ((unsigned int) 0x00000000)

#ifndef __BOARD_SPI_H
#define __BOARD_SPI_H

#define SPI_VERSION_NUMBER 2

#include <stdint.h>

#define WLAN_SPI          EV_SPI1
#define WLAN_CLK_PIN      (Pin)(JSH_PORTB_OFFSET + 3)
#define WLAN_MISO_PIN     (Pin)(JSH_PORTB_OFFSET + 4)
#define WLAN_MOSI_PIN     (Pin)(JSH_PORTB_OFFSET + 5)
#define WLAN_EN_PIN       (Pin)(JSH_PORTB_OFFSET + 7)
#define WLAN_IRQ_PIN      (Pin)(JSH_PORTB_OFFSET + 8) // active low
#define WLAN_CS_PIN       (Pin)(JSH_PORTB_OFFSET + 6)

#ifndef NULL
#define NULL							(uint32_t)0x00
#endif

void cc3000_spi_open(void);
void cc3000_spi_close(void);

long cc3000_spi_write(unsigned char *pUserBuffer, unsigned short usLength);
void cc3000_spi_resume(void);

long cc3000_read_irq_pin(void);
void cc3000_irq_enable(void);
void cc3000_irq_disable(void);

void cc3000_irq_handler(void);

void cc3000_check_irq_pin();

#endif
