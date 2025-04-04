#include <iostream>
#include <cstring>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hello.h"

void send_message() {
    const char* queue_name = "/example_queue";
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open(queue_name, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        return;
    }

    const char* message = "Hello, World!";
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        return;
    }

    mq_close(mq);
}

void receive_message() {
    const char* queue_name = "/example_queue";
    mqd_t mq = mq_open(queue_name, O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        return;
    }

    char buffer[256];
    ssize_t bytes_read;

    bytes_read = mq_receive(mq, buffer, 256, NULL);
    if (bytes_read == -1) {
        perror("mq_receive");
        return;
    }

    std::cout << "Received message: " << buffer << std::endl;

    mq_close(mq);
    mq_unlink(queue_name);
}

int hello() {
    return 0;
}
