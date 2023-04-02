#include "header/cub3d.h"

static void validations(char **argv)
{
	if (check_map_validations(argv[1]))
		printf("VALIDATIONS");
}

int main(int argc, char **argv)
{
	(void)argc;
	validations(argv);

	return (0);
}
