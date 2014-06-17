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


#ifndef PDSCH_
#define PDSCH_

#include "lte/common/base.h"
#include "lte/mimo/precoding.h"
#include "lte/mimo/layermap.h"
#include "lte/modem/mod.h"
#include "lte/modem/demod_soft.h"
#include "lte/scrambling/scrambling.h"
#include "lte/fec/rm_turbo.h"
#include "lte/fec/turbocoder.h"
#include "lte/fec/turbodecoder.h"
#include "lte/fec/crc.h"
#include "lte/phch/dci.h"
#include "lte/phch/regs.h"

#define TDEC_ITERATIONS	1

typedef _Complex float cf_t;

/* PDSCH object */
typedef struct {
	int cell_id;
	lte_cp_t cp;
	int nof_prb;
	int nof_ports;
	int max_symbols;
	unsigned short rnti;

	/* buffers */
	cf_t *ce[MAX_PORTS];
	cf_t *pdsch_symbols[MAX_PORTS];
	cf_t *pdsch_x[MAX_PORTS];
	cf_t *pdsch_d;
	char *pdsch_e_bits;
	char *cb_in_b;
	char *cb_out_b;
	float *pdsch_llr;
	float *pdsch_rm_f;

	/* tx & rx objects */
	modem_table_t mod[4];
	demod_soft_t demod;
	sequence_t seq_pdsch[NSUBFRAMES_X_FRAME];
	tcod_t encoder;
	tdec_t decoder;
	rm_turbo_t rm_turbo;
	crc_t crc_tb;
	crc_t crc_cb;
}pdsch_t;

int pdsch_init(pdsch_t *q, unsigned short user_rnti, int nof_prb,
		int nof_ports, int cell_id, lte_cp_t cp);
void pdsch_free(pdsch_t *q);

int pdsch_encode(pdsch_t *q, char *data, cf_t *sf_symbols[MAX_PORTS],
		int nsubframe, ra_mcs_t mcs, ra_prb_t *prb_alloc);
int pdsch_decode(pdsch_t *q, cf_t *sf_symbols, cf_t *ce[MAX_PORTS],
		char *data, int nsubframe, ra_mcs_t mcs, ra_prb_t *prb_alloc);


#endif
