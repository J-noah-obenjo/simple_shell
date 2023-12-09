#include "builtins.h"

/**
 * bin_env - Implementation for the  builtin env
 *
 * @info: Generic information about  shell
 * @arguments: Commands
 **/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}
