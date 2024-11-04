#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	/* 755 permission */
	if (mkdir(argv[1], 0755))  {
		perror("mkdir");
		exit(1);
	}
}
// make directory
// file permission은 8진수로 작성. 0xxx
