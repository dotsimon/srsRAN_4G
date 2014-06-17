/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2014 The libLTE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the libLTE library.
 *
 * libLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * libLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * A copy of the GNU Lesser General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#ifndef TURBOCODER_
#define TURBOCODER_

#include "lte/fec/tc_interl.h"

#define NUMREGS     3

#define RATE 3
#define TOTALTAIL 12

typedef struct {
	int max_long_cb;
	tc_interl_t interl;

}tcod_t;

int tcod_init(tcod_t *h, int max_long_cb);
void tcod_free(tcod_t *h);
int tcod_encode(tcod_t *h, char *input, char *output, int long_cb);

#endif

