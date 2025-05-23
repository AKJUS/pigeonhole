/* Copyright (c) 2002-2018 Pigeonhole authors, see the included COPYING file
 */

/* Extension vnd.dovecot.execute
 * -----------------------------
 *
 * Authors: Stephan Bosch
 * Specification: vendor-defined; spec-bosch-sieve-extprograms
 * Implementation: full
 * Status: experimental
 *
 */

#include "lib.h"

#include "sieve-extensions.h"
#include "sieve-commands.h"
#include "sieve-binary.h"

#include "sieve-validator.h"
#include "sieve-interpreter.h"

#include "sieve-ext-copy.h"

#include "sieve-extprograms-common.h"

/*
 * Extension
 */

static bool
ext_execute_validator_load(const struct sieve_extension *ext,
			   struct sieve_validator *valdtr);

const struct sieve_extension_def sieve_ext_vnd_execute = {
	.name = "vnd.dovecot.execute",
	.load = sieve_extprograms_ext_load,
	.unload = sieve_extprograms_ext_unload,
	.validator_load = ext_execute_validator_load,
	SIEVE_EXT_DEFINE_OPERATION(sieve_opr_execute),
};

/*
 * Validation
 */

static bool
ext_execute_validator_load(const struct sieve_extension *ext,
			   struct sieve_validator *valdtr)
{
	/* Register commands */
	sieve_validator_register_command(valdtr, ext, &sieve_cmd_execute);

	return TRUE;
}
