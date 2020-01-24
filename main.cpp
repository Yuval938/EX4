
#include "Boot.h"

using namespace boot;

int main(int argc, char *argv[]) {
    int port=5404;
    if(argc > 0) {
      //  port = atoi(argv[0]);
    }
    Main m;
    m.main(port);
    return 0;
}
