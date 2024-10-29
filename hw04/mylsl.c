#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int
main()
{
	DIR				*dp;
	struct dirent	*dep;
	struct stat		statbuf;
	struct passwd	*pwd;
	struct group	*grp; 

	if ((dp = opendir(".")) == NULL)  {
		perror("opendir");
		exit(1);
	}

	while (dep = readdir(dp))  {
		if (strcmp(dep->d_name, ".") == 0 || strcmp(dep->d_name, "..") == 0)
            continue;
		 // 현재와 상위 디렉터리는 건너뛰고

        // 파일 정보 가져오기
        if (stat(dep->d_name, &statbuf) == -1) {
            perror("stat");
            continue;
        }

		// 파일 유형 출력
        if (S_ISDIR(statbuf.st_mode))
            printf("d");
        else
            printf("-");

        // permission 출력 owner
        if (statbuf.st_mode & S_IRUSR)
            printf("r");
        else
            printf("-");
        if (statbuf.st_mode & S_IWUSR)
            printf("w");
        else
            printf("-");
        if (statbuf.st_mode & S_IXUSR)
            printf("x");
        else
            printf("-");

        // permission 출력 group
        if (statbuf.st_mode & S_IRGRP)
            printf("r");
        else
            printf("-");
        if (statbuf.st_mode & S_IWGRP)
            printf("w");
        else
            printf("-");
        if (statbuf.st_mode & S_IXGRP)
            printf("x");
        else
            printf("-");

        // permission 출력 other
        if (statbuf.st_mode & S_IROTH)
            printf("r");
        else
            printf("-");
        if (statbuf.st_mode & S_IWOTH)
            printf("w");
        else
            printf("-");
        if (statbuf.st_mode & S_IXOTH)
            printf("x");
        else
			printf("-");
	
		// 소유자와 그룹 이름 가져오기
        pwd = getpwuid(statbuf.st_uid);
        grp = getgrgid(statbuf.st_gid);
        if (pwd != NULL)
            printf(" %s", pwd->pw_name);
        else
            printf("pwd error");

        if (grp != NULL)
            printf(" %s", grp->gr_name);
        else
            printf("grp error");
		
		// 파일 이름 출력
        printf(" %s\n", dep->d_name);
	}
	closedir(dp);
}

