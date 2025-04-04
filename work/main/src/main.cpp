#include <iostream>
#include <cstring>
#include "hello.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <send|receive>" << std::endl;
        return 1;
    }

    if (std::strcmp(argv[1], "send") == 0) {
        send_message();
    } else if (std::strcmp(argv[1], "receive") == 0) {
        receive_message();
    } else {
        std::cerr << "Invalid argument. Use 'send' or 'receive'." << std::endl;
        return 1;
    }

    return 0;
//    hello();
//    return 0;
}
