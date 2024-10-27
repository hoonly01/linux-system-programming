#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

int
main(int argc, char *argv[])
{
	FILE	*src, *dst;
	Record	rec;

	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source dest\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	if ((dst = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	while (fgets(rec.stud, SMAX, src))  {
		*strchr(rec.stud, '\n') = '\0';
		fgets(rec.num, NMAX, src);
		*strchr(rec.num, '\n') = '\0';
		fgets(rec.dept, DMAX, src);
		*strchr(rec.dept, '\n') = '\0';

		fwrite(&rec, sizeof(rec), 1, dst);
	}

	fclose(src);
	fclose(dst);
}
// record.h는 stud, num dept로 이루어진 struct를 define
// 3줄씩 읽어 stud, num, dept에 저장 후 dst에 write

