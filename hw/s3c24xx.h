/* hw/s3c24xx.h
 *
 * Samsung s3c24xx cpu state and functions.
 *
 * Copyright 2006, 2007, 2008 Daniel Silverstone and Vincent Sanders
 *
 * This file is under the terms of the GNU General Public
 * License Version 2.
 */

#ifndef S3C24XX_H
#define S3C24XX_H 1

/* This structure type encapsulates the state of a S3C24XX SoC. */
typedef struct S3CState_s {
    CPUState *cpu_env;

    /* Memory controller state */
    struct s3c24xx_memc_state_s *memc;

    /* IRQ controller state */
    struct s3c24xx_irq_state_s *irq;

    /* Clock and power control */
    struct s3c24xx_clkcon_state_s *clkcon;

    /* timer controller */
    struct s3c24xx_timers_state_s *timers;

    /* Serial ports */
    struct s3c24xx_serial_dev_s *uart[3];

    /* Real time clock */
    struct s3c24xx_rtc_state_s *rtc;

    /* GPIO */
    struct s3c24xx_gpio_state_s *gpio;
} S3CState;


/* initialise memory controller peripheral */
struct s3c24xx_memc_state_s *s3c24xx_memc_init(target_phys_addr_t base_addr);

/* initialise the IRQ controller */
struct s3c24xx_irq_state_s *s3c24xx_irq_init(S3CState *soc, target_phys_addr_t base_addr);

/* get the qemu interrupt from an irq number */
qemu_irq s3c24xx_get_irq(struct s3c24xx_irq_state_s *s, int inum);

/* initialise clock controller */
struct s3c24xx_clkcon_state_s *s3c24xx_clkcon_init(S3CState *soc, target_phys_addr_t base_addr, uint32_t ref_freq);

/* initialise timer controller */
struct s3c24xx_timers_state_s *s3c24xx_timers_init(S3CState *soc, target_phys_addr_t base_addr, uint32_t tclk0, uint32_t tclk1);

/* initialise a serial port controller */
struct s3c24xx_serial_dev_s *s3c24xx_serial_init(S3CState *soc, CharDriverState *chr, target_phys_addr_t base_addr, int irqn);

/* Initialise real time clock */
struct s3c24xx_rtc_state_s *s3c24xx_rtc_init(target_phys_addr_t base_addr);

/* initialise GPIO */
struct s3c24xx_gpio_state_s *s3c24xx_gpio_init(S3CState *soc, target_phys_addr_t base_addr, uint32_t cpu_id);

/* get the qemu interrupt from an eirq number */
qemu_irq s3c24xx_get_eirq(struct s3c24xx_gpio_state_s *s, int einum);

#endif /* S3C24XX_H */