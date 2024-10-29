#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int
main()
{
	umask(0);
	if (creat("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)  {
		perror("creat");
		exit(0);
	}

	/* Set file mode creation mask: S_IRGRP, S_IWGRP, S_IROTH, S_IWOTH */
	// grp oth의 rw 제거
	
	umask(033);
	if (creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)  {
		perror("creat");
		exit(0);
	}
}
