#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define	MAX_BUF	256

int
main(int argc, char *argv[])
{
	char	buf[MAX_BUF];

	if (getcwd(buf, MAX_BUF) == NULL)  {
		perror("getcwd");
		exit(1);
	}

	printf("%s\n", buf);
}
