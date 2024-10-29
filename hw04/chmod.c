#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int
main()
{
	struct stat	statbuf;

	if (stat("bar", &statbuf) < 0)  {
		perror("stat");
		exit(1);
	}

	if (chmod("bar", (statbuf.st_mode & ~S_IWGRP) | S_ISUID) < 0)  {
		perror("chmod");
		exit(1);
	}

	/* S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH : ON */
	// 6 4 4
	if (chmod("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)  {
		perror("chmod");
		exit(1);
	}
}
