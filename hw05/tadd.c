#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void
DoSum(void *arg)
{
	int 	i;
	int		*num = (int *)arg;
	int		sum = 0;

	for(i = (*num); i < (*num)+50; i++) {
	//	printf("%d\n", sum);
		sum = sum + i;
	}

	*num = sum;

	pthread_exit(NULL);
}

int
main()
{
	pthread_t	tid1, tid2;
	int 		head = 1;
	int 		tail = 51;

	if (pthread_create(&tid1, NULL, (void *)DoSum, &head) < 0)  {
		perror("pthread_create");
		exit(1);
	}

	if (pthread_create(&tid2, NULL, (void *)DoSum, &tail) < 0)  {
		perror("pthread_create");
		exit(1);
	}

	//printf("Threads created: tid=%ld, %ld\n", tid1, tid2);
	
	/* Wait for tid1 to exit -> pthread_join  */
	if (pthread_join(tid1, NULL) < 0 )  {
		perror("pthread_join");
		exit(1);
	}
	if (pthread_join(tid2, NULL) < 0)  {
		perror("pthread_join");
		exit(1);
	}

	// printf("Threads terminated: tid=%ld, %ld\n", tid1, tid2);
	// printf("head :%d, tail :%d\n", head, tail);
	printf("%d\n", head+tail);
}

// head가 1~50 합 저장
// taildl 51-100 합 저장
