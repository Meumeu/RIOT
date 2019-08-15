/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_stm32
 * @{
 *
 * @file
 * @brief           Shared CPU specific configuration for STM32 family
 *
 * @author          Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#ifndef CPU_CONF_STM32_COMMON_H
#define CPU_CONF_STM32_COMMON_H

#include "periph_cpu.h"

#include "periph/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CPU_FAM_STM32F0) || defined(CPU_FAM_STM32F3) || \
    defined(CPU_FAM_STM32F7) || defined(CPU_FAM_STM32L0) || \
    defined(CPU_FAM_STM32L4) || defined(CPU_FAM_STM32L4) || \
    defined(CPU_FAM_STM32WB)

/**
 * @brief   Timing register settings
 *
 * @ref i2c_timing_param_ns_t
 */
static const i2c_timing_param_ns_t timing_params_ns[] = {
#if defined(CPU_FAM_STM32F0) || defined(CPU_FAM_STM32F7) || \
    defined(CPU_FAM_STM32L4) || defined(CPU_FAM_STM32WB)
    [ I2C_SPEED_NORMAL ]    = {
        .scll_ns   = 5000,     /* t_SCLL   = 5.0us  */
        .sclh_ns   = 4000,     /* t_SCLH   = 4.0us  */
        .sdadel_ns = 500,      /* t_SDADEL = 500ns  */
        .scldel_ns = 1250,     /* t_SCLDEL = 1250ns */
    },
    [ I2C_SPEED_FAST ]      = {
        .scll_ns   = 1250,     /* t_SCLL   = 1250ns */
        .sclh_ns   = 500,      /* t_SCLH   = 500ns  */
        .sdadel_ns = 375,      /* t_SDADEL = 375ns  */
        .scldel_ns = 500,      /* t_SCLDEL = 500ns  */
    },
    [ I2C_SPEED_FAST_PLUS ] = {
        .scll_ns =   500,      /* t_SCLL   = 500ns */
        .sclh_ns =   250,      /* t_SCLH   = 250ns */
        .sdadel_ns = 0,        /* t_SDADEL = 0ns   */
        .scldel_ns = 250,      /* t_SCLDEL = 250ns */
    }
#elif defined(CPU_FAM_STM32F3) || defined(CPU_FAM_STM32L0)
    [ I2C_SPEED_NORMAL ]    = {
        .scll_ns   = 5000,     /* t_SCLL   = 5.0us  */
        .sclh_ns   = 4000,     /* t_SCLH   = 4.0us  */
        .sdadel_ns = 500,      /* t_SDADEL = 500ns  */
        .scldel_ns = 1250,     /* t_SCLDEL = 1250ns */
    },
    [ I2C_SPEED_FAST ]      = {
        .scll_ns   = 1250,     /* t_SCLL   = 1250ns */
        .sclh_ns   = 500,      /* t_SCLH   = 500ns  */
        .sdadel_ns = 125,      /* t_SDADEL = 125ns  */
        .scldel_ns = 500,      /* t_SCLDEL = 500ns  */
    },
    [ I2C_SPEED_FAST_PLUS ] = {
        .scll_ns =   875,      /* t_SCLL   = 875ns */
        .sclh_ns =   500,      /* t_SCLH   = 500ns */
        .sdadel_ns = 0,        /* t_SDADEL = 0ns   */
        .scldel_ns = 250,      /* t_SCLDEL = 250ns */
    }
#endif
};

#endif /* CPU_FAM_STM32F0 || CPU_FAM_STM32F3 || CPU_FAM_STM32F7 ||
          CPU_FAM_STM32L0 || CPU_FAM_STM32L4 || CPU_FAM_STM32WB */

#ifdef __cplusplus
}
#endif

#endif /* CPU_CONF_STM32_COMMON_H */
/** @} */
