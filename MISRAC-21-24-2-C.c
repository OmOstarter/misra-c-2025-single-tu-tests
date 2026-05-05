#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

uint32_t generateRandomLinux(void) {
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 0;
    }
    uint32_t randomNumber;
    read(fd, &randomNumber, sizeof(randomNumber));
    close(fd);
    return randomNumber;
}

int main() {
    printf("Random Number: %u\n", generateRandomLinux());
    return 0;
}
