#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    rlim_t stack_size;
    rlim_t process_limit;
    rlim_t max_fd;

    int status = getrlimit(RLIMIT_STACK, &lim);
    if(status == 0) stack_size = lim.rlim_cur;
    else {
        printf("Stack size could not be obtained\n");
        return 0;
    }
    status = getrlimit(RLIMIT_NPROC, &lim);
    if(status == 0) process_limit = lim.rlim_cur;
    else {
        printf("Process_limit could not be obtained\n");
        return 0;
    }
    status = getrlimit(RLIMIT_NOFILE, &lim);
    if(status == 0) max_fd = lim.rlim_cur;
    else {
        printf("Max fd could not be obtained\n");
        return 0;
    }


    printf("stack size: %ld\n", stack_size);
    printf("process limit: %ld\n", process_limit);
    printf("max file descriptors: %ld\n", max_fd);
    return 0;
}
