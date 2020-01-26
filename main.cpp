#include "Boot.h"

using namespace boot;

int main(int argc, char *argv[]) {
    int port = 5600;
    if (argc > 1) {
        port = atoi(argv[1]); // assuming that the only arg i'll get will be a port number
    }
    Main m;
    m.main(port);
    return 0;
}
