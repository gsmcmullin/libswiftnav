/*
 * Copyright (c) 2015 Swift Navigation Inc.
 * Contact: Vlad Ungureanu <vvu@vdev.ro>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSWIFTNAV_SIGNAL_H
#define LIBSWIFTNAV_SIGNAL_H

#include "common.h"

#define GPS_L1_SATS 32
#define WAAS_SATS 3
#define EGNOS_SATS 3
#define GAGAN_SATS 2
#define MSAS_SATS 2
#define SDCM_SATS 2
#define SBAS_SATS (WAAS_SATS + EGNOS_SATS + GAGAN_SATS + MSAS_SATS + SDCM_SATS)
#define ALL_SATS (GPS_L1_SATS + SBAS_SATS)

#define CONSTELLATION_GPS 0
#define CONSTELLATION_SBAS 1

#define BAND_L1 0

typedef struct __attribute__((packed)) {
  u16 sat;
  u8 band;
  u8 constellation;
} gnss_signal_t;

static inline int sid_compare(const gnss_signal_t a, const gnss_signal_t b)
{
  s32 x;
  if ((x = a.constellation - b.constellation))
    return x;
  if ((x = a.band - b.band))
    return x;
  return a.sat - b.sat;
}

static inline int cmp_sid_sid(const void *a, const void *b)
{
  return sid_compare(*(gnss_signal_t *)a, *(gnss_signal_t*)b);
}

static inline bool sid_is_equal(const gnss_signal_t a, const gnss_signal_t b)
{
  return sid_compare(a, b) == 0;
}

#endif /* LIBSWIFTNAV_SIGNAL_H */

