#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	if (rmdir(argv[1]) < 0)  {
		perror("rmdir");
		exit(1);
	}
}
// remove directory
