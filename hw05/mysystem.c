#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int mysystem(char *cmd) {
    pid_t pid;
    int status;

    // 자식 프로세스 생성
    pid = fork();
    if (pid < 0) { // fork 실패 시
        perror("fork failed");
        exit(-1);
    } else if (pid == 0) { // 자식 프로세스
        // 명령어를 실행하기 위한 배열 생성
        char *args[] = {"/bin/sh", "-c", cmd, NULL};

        // execv를 사용하여 명령어 실행
        execv("/bin/sh", args);

        // execv가 실패한 경우
        perror("execv failed");
        exit(EXIT_FAILURE);
    } else { // 부모 프로세스
        // 자식 프로세스가 끝날 때까지 대기
        if (waitpid(pid, &status, 0) < 0) {
            perror("waitpid failed");
            exit(-1);
        }

        // 자식 프로세스의 종료 상태 확인 후 종료
        if (WIFEXITED(status)) {
            exit(WEXITSTATUS(status));
        } else {
            exit(-1);
        }
    }
}

int main() {
    char command[256];

    // 실행할 명령어 입력
    printf("Enter command to execute: ");
    if (fgets(command, sizeof(command), stdin) == NULL) {
        perror("fgets failed");
        exit(1);
    }

    // 줄바꿈 제거
    command[strcspn(command, "\n")] = '\0';

    // mysystem 함수 호출
    mysystem(command);

    // mysystem에서 종료되므로 여기는 도달하지 않음
    return 0;
}

